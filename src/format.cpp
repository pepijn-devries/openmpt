#include <cpp11.hpp>
#include <libopenmpt/libopenmpt.hpp>
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

[[cpp11::register]]
strings_matrix<> format_pattern_(SEXP mod, int pattern, int width, bool pad) {
  module * my_mod = get_mod(mod);
  int num_channels = my_mod->get_num_channels();
  int num_rows     = my_mod->get_pattern_num_rows(pattern);
  
  writable::strings_matrix<> result(num_rows, num_channels);
  for (int j = 0; j < num_channels; j++) {
    for (int i = 0; i < num_rows; i++) {
      result(i, j) = r_string(
        my_mod->format_pattern_row_channel(pattern, i, j, width, pad)
      );
    }
  }
  return result;
}