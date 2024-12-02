#include <cpp11.hpp>
#include <portaudio.h>
using namespace cpp11;

[[cpp11::register]]
bool has_audio_device_(void) {
  int result = 0;
  try {
    Pa_Initialize();
    result = Pa_GetDeviceCount();
    Pa_Terminate();
  } catch(...) {
    
  }
  return result > 0;
}
