#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
#include <portaudiocpp/PortAudioCpp.hxx>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod); // specified in get_mod.cpp

[[cpp11::register]]
SEXP play_(SEXP mod, int samplerate) {
  module * my_mod = get_mod(mod);
  portaudio::AutoSystem portaudio_initializer;
  portaudio::System & portaudio = portaudio::System::instance();
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
  // TODO not complete yet, use example at https://lib.openmpt.org/doc/libopenmpt_cpp_overview.html
  // for inspiration
  return R_NilValue;
}