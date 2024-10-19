#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod); // specified in get_mod.cpp

[[cpp11::register]]
strings ctl_get_text_(SEXP mod, std::string ctl) {
  module * my_mod = get_mod(mod);
  r_string result(
      my_mod->ctl_get_text(ctl)
  );
  return writable::strings(result);
}