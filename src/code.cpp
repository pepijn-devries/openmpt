#include <cpp11.hpp>
#include <libopenmpt.hpp>
using namespace cpp11;
using namespace openmpt;

[[cpp11::register]]
int lompt_version() {
  return get_library_version();
}
