#include <cpp11.hpp>
#include <libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod) {
  if (TYPEOF(mod) != EXTPTRSXP || !Rf_inherits(mod, "openmpt"))
    Rf_error("`mod` should be and external pointer of class openmpt");
  module * my_mod = reinterpret_cast<module *>(R_ExternalPtrAddr(mod));
  if (my_mod == NULL) Rf_error("Invalid pointer");
  return my_mod;
}