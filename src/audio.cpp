#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
#include <portaudiocpp/PortAudioCpp.hxx>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod); // specified in get_mod.cpp

[[cpp11::register]]
SEXP play_(SEXP mod, int samplerate) {
  module * my_mod = get_mod(mod);
  try {
    constexpr std::size_t buffersize = 480;
    portaudio::AutoSystem portaudio_initializer;
    portaudio::System & portaudio = portaudio::System::instance();
    std::vector<float> left( buffersize );
    std::vector<float> right( buffersize );
    std::vector<float> interleaved_buffer( buffersize * 2 );
    bool is_interleaved = false;
#if defined( _MSC_VER ) && defined( _PREFAST_ )
    // work-around bug in VS2019 MSVC 16.5.5 static analyzer
    is_interleaved = false;
    portaudio::DirectionSpecificStreamParameters outputstream_parameters( portaudio.defaultOutputDevice(), 2, portaudio::FLOAT32, false, portaudio.defaultOutputDevice().defaultHighOutputLatency(), 0 );
    portaudio::StreamParameters stream_parameters( portaudio::DirectionSpecificStreamParameters::null(), outputstream_parameters, samplerate, paFramesPerBufferUnspecified, paNoFlag );
    portaudio::BlockingStream stream( stream_parameters );
#else
    portaudio::BlockingStream stream = [&]()
    {
      try {
        is_interleaved = false;
        portaudio::DirectionSpecificStreamParameters outputstream_parameters( portaudio.defaultOutputDevice(), 2, portaudio::FLOAT32, false, portaudio.defaultOutputDevice().defaultHighOutputLatency(), 0 );
        portaudio::StreamParameters stream_parameters( portaudio::DirectionSpecificStreamParameters::null(), outputstream_parameters, samplerate, paFramesPerBufferUnspecified, paNoFlag );
        return portaudio::BlockingStream( stream_parameters );
      } catch ( const portaudio::PaException & e ) {
        if ( e.paError() != paSampleFormatNotSupported ) {
          throw;
        }
        is_interleaved = true;
        portaudio::DirectionSpecificStreamParameters outputstream_parameters( portaudio.defaultOutputDevice(), 2, portaudio::FLOAT32, true, portaudio.defaultOutputDevice().defaultHighOutputLatency(), 0 );
        portaudio::StreamParameters stream_parameters( portaudio::DirectionSpecificStreamParameters::null(), outputstream_parameters, samplerate, paFramesPerBufferUnspecified, paNoFlag );
        return portaudio::BlockingStream( stream_parameters );
      }
    }();
#endif
    stream.start();
    while ( true ) {
      std::size_t count = is_interleaved ? my_mod->read_interleaved_stereo( samplerate, buffersize, interleaved_buffer.data() ) : my_mod->read( samplerate, buffersize, left.data(), right.data() );
      if ( count == 0 ) {
        break;
      }
      try {
        if ( is_interleaved ) {
          stream.write( interleaved_buffer.data(), static_cast<unsigned long>( count ) );
        } else {
          const float * const buffers[2] = { left.data(), right.data() };
          stream.write( buffers, static_cast<unsigned long>( count ) );
        }
      } catch ( const portaudio::PaException & pa_exception ) {
        if ( pa_exception.paError() != paOutputUnderflowed ) {
          throw;
        }
      }
    }
    stream.stop();
  } catch ( const std::bad_alloc & ) {
    std::cerr << "Error: " << std::string( "out of memory" ) << std::endl;
    return R_NilValue;
  } catch ( const std::exception & e ) {
    std::cerr << "Error: " << std::string( e.what() ? e.what() : "unknown error" ) << std::endl;
    return R_NilValue;
  }
  return R_NilValue;
}