#include <cpp11.hpp>
#include <libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

module * get_mod(SEXP mod); // specified in get_mod.cpp

[[cpp11::register]]
strings format_pattern_row_channel_(SEXP mod, int pattern, int row, int channel,
                                    int width = 0, bool pad = true) {
  module * my_mod = get_mod(mod);
  r_string result(
      my_mod->format_pattern_row_channel(pattern, row, channel, width, pad)
  );
  return writable::strings(result);
}
