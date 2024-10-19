#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod); // specified in get_mod.cpp

[[cpp11::register]]
SEXP lompt_get_string_(const char * key) {
  r_string result(
      string::get(key) // TODO get seems to be deprecated
  );
  return writable::strings(result);
}

[[cpp11::register]]
strings get_metadata_keys_(SEXP mod) {
  module * my_mod = get_mod(mod);
  std::vector<std::string> keys = my_mod->get_metadata_keys();
  writable::strings result((R_xlen_t)keys.size());
  for (int i = 0; i < (int)keys.size(); i++) {
    result.at(i) = r_string(keys.at(i));
  }
  return result;
}

[[cpp11::register]]
double get_duration_seconds_(SEXP mod) {
  module * my_mod = get_mod(mod);
  return my_mod->get_duration_seconds();
}

[[cpp11::register]]
SEXP get_metadata_(SEXP mod, const char * key) {
  module * my_mod = get_mod(mod);
  r_string result(
      my_mod->get_metadata(key)
  );
  return writable::strings(result);
}