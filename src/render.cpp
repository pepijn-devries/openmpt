#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod); // specified in get_mod.cpp

[[cpp11::register]]
doubles render_(SEXP mod, int n_samples, int sample_rate) {
  module * my_mod = get_mod(mod);
  writable::doubles samps((R_xlen_t)2*n_samples);
  float fl[n_samples]; // TODO fix this, not allowed by ISO C++
  float fr[n_samples]; // TODO fix this, not allowed by ISO C++
  //TODO bind left and right
  my_mod->read(sample_rate, n_samples, fl, fr);
  for (int i = 0; i < n_samples; i++) {
    samps.at(i*2)     = fl[i]; // left
    samps.at(i*2 + 1) = fr[i]; // right
  }
  return samps;
}