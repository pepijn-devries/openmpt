#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

void destroy_mod(module * m) {
  delete m;
  return;
}

[[cpp11::register]]
SEXP read_from_raw_(raws data) {
  const uint8_t * rdata = (const uint8_t *)RAW(as_sexp(data));
  
  module * my_mod = new module(rdata, rdata + data.size());
  
  external_pointer<module, destroy_mod>modptr(my_mod);
  sexp result = as_sexp(modptr);
  result.attr("class") = "openmpt";
  
  return result;
}
