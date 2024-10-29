// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// audio.cpp
SEXP play_(SEXP mod, int samplerate, std::string progress);
extern "C" SEXP _openmpt_play_(SEXP mod, SEXP samplerate, SEXP progress) {
  BEGIN_CPP11
    return cpp11::as_sexp(play_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<int>>(samplerate), cpp11::as_cpp<cpp11::decay_t<std::string>>(progress)));
  END_CPP11
}
// ctl.cpp
strings ctl_get_text_(SEXP mod, std::string ctl);
extern "C" SEXP _openmpt_ctl_get_text_(SEXP mod, SEXP ctl) {
  BEGIN_CPP11
    return cpp11::as_sexp(ctl_get_text_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<std::string>>(ctl)));
  END_CPP11
}
// format.cpp
strings format_pattern_row_channel_(SEXP mod, int pattern, int row, int channel, int width, bool pad);
extern "C" SEXP _openmpt_format_pattern_row_channel_(SEXP mod, SEXP pattern, SEXP row, SEXP channel, SEXP width, SEXP pad) {
  BEGIN_CPP11
    return cpp11::as_sexp(format_pattern_row_channel_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<int>>(pattern), cpp11::as_cpp<cpp11::decay_t<int>>(row), cpp11::as_cpp<cpp11::decay_t<int>>(channel), cpp11::as_cpp<cpp11::decay_t<int>>(width), cpp11::as_cpp<cpp11::decay_t<bool>>(pad)));
  END_CPP11
}
// format.cpp
strings_matrix<> format_pattern_(SEXP mod, int pattern, int width, bool pad);
extern "C" SEXP _openmpt_format_pattern_(SEXP mod, SEXP pattern, SEXP width, SEXP pad) {
  BEGIN_CPP11
    return cpp11::as_sexp(format_pattern_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<int>>(pattern), cpp11::as_cpp<cpp11::decay_t<int>>(width), cpp11::as_cpp<cpp11::decay_t<bool>>(pad)));
  END_CPP11
}
// info.cpp
SEXP lompt_get_string_(const char * key);
extern "C" SEXP _openmpt_lompt_get_string_(SEXP key) {
  BEGIN_CPP11
    return cpp11::as_sexp(lompt_get_string_(cpp11::as_cpp<cpp11::decay_t<const char *>>(key)));
  END_CPP11
}
// info.cpp
strings get_metadata_keys_(SEXP mod);
extern "C" SEXP _openmpt_get_metadata_keys_(SEXP mod) {
  BEGIN_CPP11
    return cpp11::as_sexp(get_metadata_keys_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod)));
  END_CPP11
}
// info.cpp
double get_duration_seconds_(SEXP mod);
extern "C" SEXP _openmpt_get_duration_seconds_(SEXP mod) {
  BEGIN_CPP11
    return cpp11::as_sexp(get_duration_seconds_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod)));
  END_CPP11
}
// info.cpp
double get_position_seconds_(SEXP mod);
extern "C" SEXP _openmpt_get_position_seconds_(SEXP mod) {
  BEGIN_CPP11
    return cpp11::as_sexp(get_position_seconds_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod)));
  END_CPP11
}
// info.cpp
SEXP get_metadata_(SEXP mod, const char * key);
extern "C" SEXP _openmpt_get_metadata_(SEXP mod, SEXP key) {
  BEGIN_CPP11
    return cpp11::as_sexp(get_metadata_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<const char *>>(key)));
  END_CPP11
}
// io.cpp
SEXP read_from_raw_(raws data);
extern "C" SEXP _openmpt_read_from_raw_(SEXP data) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_from_raw_(cpp11::as_cpp<cpp11::decay_t<raws>>(data)));
  END_CPP11
}
// module_ext.cpp
SEXP set_channel_mute_status_(SEXP mod, int channel, bool status);
extern "C" SEXP _openmpt_set_channel_mute_status_(SEXP mod, SEXP channel, SEXP status) {
  BEGIN_CPP11
    return cpp11::as_sexp(set_channel_mute_status_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<int>>(channel), cpp11::as_cpp<cpp11::decay_t<bool>>(status)));
  END_CPP11
}
// module_ext.cpp
SEXP test_(SEXP mod, double position_seconds);
extern "C" SEXP _openmpt_test_(SEXP mod, SEXP position_seconds) {
  BEGIN_CPP11
    return cpp11::as_sexp(test_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<double>>(position_seconds)));
  END_CPP11
}
// render.cpp
SEXP render_(SEXP mod, std::string filename, int samplerate);
extern "C" SEXP _openmpt_render_(SEXP mod, SEXP filename, SEXP samplerate) {
  BEGIN_CPP11
    return cpp11::as_sexp(render_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<std::string>>(filename), cpp11::as_cpp<cpp11::decay_t<int>>(samplerate)));
  END_CPP11
}
// set.cpp
SEXP set_position_seconds_(SEXP mod, double secs);
extern "C" SEXP _openmpt_set_position_seconds_(SEXP mod, SEXP secs) {
  BEGIN_CPP11
    return cpp11::as_sexp(set_position_seconds_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<double>>(secs)));
  END_CPP11
}
// set.cpp
SEXP set_position_order_row_(SEXP mod, int order, int row);
extern "C" SEXP _openmpt_set_position_order_row_(SEXP mod, SEXP order, SEXP row) {
  BEGIN_CPP11
    return cpp11::as_sexp(set_position_order_row_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(mod), cpp11::as_cpp<cpp11::decay_t<int>>(order), cpp11::as_cpp<cpp11::decay_t<int>>(row)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_openmpt_ctl_get_text_",               (DL_FUNC) &_openmpt_ctl_get_text_,               2},
    {"_openmpt_format_pattern_",             (DL_FUNC) &_openmpt_format_pattern_,             4},
    {"_openmpt_format_pattern_row_channel_", (DL_FUNC) &_openmpt_format_pattern_row_channel_, 6},
    {"_openmpt_get_duration_seconds_",       (DL_FUNC) &_openmpt_get_duration_seconds_,       1},
    {"_openmpt_get_metadata_",               (DL_FUNC) &_openmpt_get_metadata_,               2},
    {"_openmpt_get_metadata_keys_",          (DL_FUNC) &_openmpt_get_metadata_keys_,          1},
    {"_openmpt_get_position_seconds_",       (DL_FUNC) &_openmpt_get_position_seconds_,       1},
    {"_openmpt_lompt_get_string_",           (DL_FUNC) &_openmpt_lompt_get_string_,           1},
    {"_openmpt_play_",                       (DL_FUNC) &_openmpt_play_,                       3},
    {"_openmpt_read_from_raw_",              (DL_FUNC) &_openmpt_read_from_raw_,              1},
    {"_openmpt_render_",                     (DL_FUNC) &_openmpt_render_,                     3},
    {"_openmpt_set_channel_mute_status_",    (DL_FUNC) &_openmpt_set_channel_mute_status_,    3},
    {"_openmpt_set_position_order_row_",     (DL_FUNC) &_openmpt_set_position_order_row_,     3},
    {"_openmpt_set_position_seconds_",       (DL_FUNC) &_openmpt_set_position_seconds_,       2},
    {"_openmpt_test_",                       (DL_FUNC) &_openmpt_test_,                       2},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_openmpt(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
