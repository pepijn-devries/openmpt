#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod); // specified in get_mod.cpp

[[cpp11::register]]
strings get_ctls_(SEXP mod) {
  module * my_mod = get_mod(mod);
  std::vector< std::string > temp = my_mod->get_ctls();
  writable::strings result((R_xlen_t)temp.size());
  for (long long unsigned int i = 0; i < temp.size(); i++) {
    result.at(i) = r_string(temp.at(i));
  }
  return(result);
}

[[cpp11::register]]
std::string ctl_get_text_(SEXP mod, std::string ctl) {
  module * my_mod = get_mod(mod);
  return my_mod->ctl_get_text(ctl);
}

[[cpp11::register]]
int ctl_get_int_(SEXP mod, std::string ctl) {
  module * my_mod = get_mod(mod);
  return (int)my_mod->ctl_get_integer(ctl);
}

[[cpp11::register]]
bool ctl_get_bool_(SEXP mod, std::string ctl) {
  module * my_mod = get_mod(mod);
  return my_mod->ctl_get_boolean(ctl);
}

[[cpp11::register]]
double ctl_get_double_(SEXP mod, std::string ctl) {
  module * my_mod = get_mod(mod);
  return my_mod->ctl_get_floatingpoint(ctl);
}
