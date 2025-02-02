AC_INIT([libopenmpt], [0.7.13+release.autotools], [https://bugs.openmpt.org/], [libopenmpt], [https://lib.openmpt.org/])
AC_PREREQ([2.69])

AC_CONFIG_MACRO_DIRS([tools/m4])
AC_CONFIG_AUX_DIR([tools/build-aux])
AC_CONFIG_FILES([tools/Makefile tools/libopenmpt/libopenmpt.pc tools/Doxyfile])

AM_INIT_AUTOMAKE([1.11 -Wall -Werror foreign subdir-objects])

AC_USE_SYSTEM_EXTENSIONS

AM_PROG_AR

LT_INIT

AC_SYS_LARGEFILE

PKG_PROG_PKG_CONFIG([0.24])

# Ensure C++ is set up as R expects
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
    AC_MSG_ERROR([Could not determine R_HOME.])
fi
CXX=`"${R_HOME}/bin/R" CMD config CXX`
CXXFLAGS=`"${R_HOME}/bin/R" CMD config CXXFLAGS`
AC_SUBST(R_HOME)
AC_REQUIRE_CPP

AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_INSTALL

# We need C++17 support.
# AX_CXX_COMPILE_STDCXX([20], [noext], [optional])
AX_CXX_COMPILE_STDCXX([20], [noext])
AS_IF([test "x$HAVE_CXX20" != "x1"],
 [
  AX_CXX_COMPILE_STDCXX([17], [noext], [mandatory])
 ],[]
)

AC_DEFUN([AC_PROG_PKGCONFIG], [AC_CHECK_PROG(PKGCONFIG,pkg-config,yes)])

AC_PROG_PKGCONFIG

## use pkg-config for libopenmpt settings
##
if test x"${PKGCONFIG}" = x"yes"; then
    if pkg-config --exists libopenmpt; then
        libopenmpt_configtest="yes"
        libopenmpt_cxxflags=`pkg-config --cflags libopenmpt`
        libopenmpt_libs=`pkg-config --libs libopenmpt`
    else
        libopenmpt_configtest="no"
        libopenmpt_cxxflags=""
        libopenmpt_libs="-lopenmpt"
    fi
    libopenmpt_configtest="no"
    # Add a reasonable default of -lopenmpt if we don't have pkg-config
    libopenmpt_cxxflags=""
    libopenmpt_libs="-lopenmpt"
fi

AC_SUBST(PKG_CFLAGS)
AC_SUBST(PKG_LIBS)
if test x"${libopenmpt_configtest}" = x"no"; then
    case x"${host_os}" in
        x"darwin"*)
            AC_MSG_NOTICE([Using pre-build brew formula])
            curl -sfL "https://autobrew.github.io/scripts/libopenmpt" > autobrew
            . ./autobrew
            libopenmpt_cxxflags="${PKG_CFLAGS}"
            libopenmpt_libs="${PKG_LIBS}";;
    esac
fi

## And make sure these flags are used for the tests below.
GLOBAL_CPPFLAGS="${libopenmpt_cxxflags} ${CPPFLAGS}"
GLOBAL_CXXFLAGS="${libopenmpt_cxxflags} ${CXXFLAGS}"

# GLOBAL_CPPFLAGS=
GLOBAL_CFLAGS=
# GLOBAL_CXXFLAGS=

AC_LANG_PUSH([C])
AX_CHECK_COMPILE_FLAG([-fvisibility=hidden], [GLOBAL_CFLAGS="$GLOBAL_CFLAGS -fvisibility=hidden"])
AX_CFLAGS_WARN_ALL
AC_LANG_POP([C])

AC_LANG_PUSH([C++])
AX_CHECK_COMPILE_FLAG([-fvisibility=hidden], [GLOBAL_CXXFLAGS="$GLOBAL_CXXFLAGS -fvisibility=hidden"])
AX_CXXFLAGS_WARN_ALL
AC_LANG_POP([C++])

AX_CXX_EXCEPTIONS
AX_CXX_RTTI

AX_PTHREAD([
 LIBS="$PTHREAD_LIBS $LIBS"
 GLOBAL_CFLAGS="$GLOBAL_CFLAGS $PTHREAD_CFLAGS"
 GLOBAL_CXXFLAGS="$GLOBAL_CXXFLAGS $PTHREAD_CFLAGS"
 #CC="$PTHREAD_CC"
 #CXX="$PTHREAD_CXX"
 ],
 []
)

# work-around <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=115049>
# This is somewhat pessimistic, but necessary for GCC 8 or earlier,
# which we still support and where we cannot use #pragma GCC optimize.
AC_LANG_PUSH([C])
AX_CHECK_COMPILE_FLAG([-fno-ipa-ra], [GLOBAL_CFLAGS="$GLOBAL_CFLAGS -fno-ipa-ra"])
AX_CFLAGS_WARN_ALL
AC_LANG_POP([C])
AC_LANG_PUSH([C++])
AX_CHECK_COMPILE_FLAG([-fno-ipa-ra], [GLOBAL_CXXFLAGS="$GLOBAL_CXXFLAGS -fno-ipa-ra"])
AX_CXXFLAGS_WARN_ALL
AC_LANG_POP([C++])

AC_SUBST([GLOBAL_CPPFLAGS])
AC_SUBST([GLOBAL_CFLAGS])
AC_SUBST([GLOBAL_CXXFLAGS])

LIBOPENMPT_LTVER_CURRENT=4
LIBOPENMPT_LTVER_REVISION=4
LIBOPENMPT_LTVER_AGE=4
AC_SUBST([LIBOPENMPT_LTVER_CURRENT])
AC_SUBST([LIBOPENMPT_LTVER_REVISION])
AC_SUBST([LIBOPENMPT_LTVER_AGE])

AC_DEFINE([MPT_SVNURL], ["https://source.openmpt.org/svn/openmpt/tags/libopenmpt-0.7.13"], [svn version])
AC_DEFINE([MPT_SVNVERSION], ["22826"], [svn version])
AC_DEFINE([MPT_SVNDATE], ["2025-01-06T13:49:43.586768Z"], [svn date])
AC_DEFINE([MPT_PACKAGE], [true], [is package])

AC_ARG_VAR(CXXSTDLIB_PCLIBSPRIVATE, [C++ standard library (or libraries) required for static linking. This will be put in the pkg-config file libopenmpt.pc Libs.private field and used for nothing else.])

AC_CANONICAL_HOST

# work-around NetBSD toolchain not understanding transitive shared object dependencies at all
AS_CASE([$host_os],
 [netbsd*], [LIBS="$LIBS -lstdc++"],
 []
)

AS_CASE([$host_os],
 [mingw32*],[
  LIBOPENMPT_WIN32_LIBS=
  LIBOPENMPT_LIBS_PRIVATE_WIN32=
  LIBOPENMPTTEST_WIN32_LIBS="-lole32 -lrpcrt4"
  OPENMPT123_WIN32_LIBS=-lwinmm
  WIN32_CPPFLAGS="-D_UNICODE -DNOMINMAX"
  WIN32_CXXFLAGS="-municode -mthreads"
  WIN32_CFLAGS="-municode -mthreads"
  WIN32_CONSOLE_CXXFLAGS=-mconsole
  WIN32_CONSOLE_CFLAGS=-mconsole
 ],
 [
  LIBOPENMPT_WIN32_LIBS=
  LIBOPENMPT_LIBS_PRIVATE_WIN32=
  LIBOPENMPTTEST_WIN32_LIBS=
  OPENMPT123_WIN32_LIBS=
  WIN32_CPPFLAGS=
  WIN32_CXXFLAGS=
  WIN32_CFLAGS=
  WIN32_CONSOLE_CXXFLAGS=
  WIN32_CONSOLE_CFLAGS=
 ]
)
AC_SUBST([LIBOPENMPT_WIN32_LIBS])
AC_SUBST([LIBOPENMPTTEST_WIN32_LIBS])
AC_SUBST([OPENMPT123_WIN32_LIBS])
AC_SUBST([WIN32_CPPFLAGS])
AC_SUBST([WIN32_CXXFLAGS])
AC_SUBST([WIN32_CFLAGS])
AC_SUBST([WIN32_CONSOLE_CXXFLAGS])
AC_SUBST([WIN32_CONSOLE_CFLAGS])

LIBOPENMPT_REQUIRES_PRIVATE=
LIBOPENMPT_LIBS_PRIVATE=

# Required libopenmpt dependency: zlib
ZLIB_PKG=
AC_ARG_WITH([zlib], AS_HELP_STRING([--without-zlib], [Disable use of zlib.]))
AS_IF([test "x$with_zlib" != "xno"],
 [
  PKG_CHECK_MODULES([ZLIB], [zlib],
   [
    ZLIB_PKG=zlib
    ZLIB_CFLAGS="-DMPT_WITH_ZLIB $ZLIB_CFLAGS"
   ], [AC_MSG_ERROR([Unable to find zlib.])])
 ]
)

# Required libopenmpt dependency: mpg123
MPG123_PKG=
AC_ARG_WITH([mpg123], AS_HELP_STRING([--without-mpg123], [Disable use of libmpg123.]))

PKG_CHECK_MODULES([MPG123], [libmpg123 >= 1.14.0],
   [
   AC_MSG_NOTICE([TODO found mpg123])
   ], [AC_MSG_NOTICE([TODO did not find mpg123])])
PKG_CHECK_MODULES([MPG123], [brewmpg123],
   [
   AC_MSG_NOTICE([TODO found brewmpg123])
   ], [AC_MSG_NOTICE([TODO did not find brewmpg123])])

AS_IF([test "x$with_mpg123" != "xno"],
 [
  PKG_CHECK_MODULES([MPG123], [libmpg123 >= 1.14.0],
   [
    MPG123_PKG=libmpg123
    MPG123_CFLAGS="-DMPT_WITH_MPG123 $MPG123_CFLAGS"
   ], [AC_MSG_ERROR([Unable to find libmpg123.])])
 ]
)

# Required libopenmpt dependency: ogg
OGG_PKG=
AC_ARG_WITH([ogg], AS_HELP_STRING([--without-ogg], [Disable use of libogg.]))
AS_IF([test "x$with_ogg" != "xno"],
 [
  PKG_CHECK_MODULES([OGG], [ogg],
   [
    OGG_PKG=ogg
    OGG_CFLAGS="-DMPT_WITH_OGG $OGG_CFLAGS"
   ], [AC_MSG_ERROR([Unable to find libogg.])])
 ]
)

# Required libopenmpt dependency: vorbis
VORBIS_PKG=
AC_ARG_WITH([vorbis], AS_HELP_STRING([--without-vorbis], [Disable use of libvorbis.]))
AS_IF([test "x$with_vorbis" != "xno"],
 [
  PKG_CHECK_MODULES([VORBIS], [vorbis],
   [
    VORBIS_PKG=vorbis
    VORBIS_CFLAGS="-DMPT_WITH_VORBIS $VORBIS_CFLAGS"
   ], [AC_MSG_ERROR([Unable to find libvorbis.])])
 ]
)

# Required libopenmpt dependency: vorbisfile
VORBISFILE_PKG=
AC_ARG_WITH([vorbisfile], AS_HELP_STRING([--without-vorbisfile], [Disable use of libvorbisfile.]))
AS_IF([test "x$with_vorbisfile" != "xno"],
 [
  PKG_CHECK_MODULES([VORBISFILE], [vorbisfile],
   [
    VORBISFILE_PKG=vorbisfile
    VORBISFILE_CFLAGS="-DMPT_WITH_VORBISFILE $VORBISFILE_CFLAGS"
   ], [AC_MSG_ERROR([Unable to find libvorbisfile.])])
 ]
)

LIBOPENMPT_REQUIRES_PRIVATE="$ZLIB_PKG $MPG123_PKG $OGG_PKG $VORBIS_PKG $VORBISFILE_PKG"
LIBOPENMPT_LIBS_PRIVATE="$CXXSTDLIB_PCLIBSPRIVATE $LIBOPENMPT_LIBS_PRIVATE_WIN32"
AC_SUBST([LIBOPENMPT_REQUIRES_PRIVATE])
AC_SUBST([LIBOPENMPT_LIBS_PRIVATE])

# openmpt123
AC_ARG_ENABLE([openmpt123], AS_HELP_STRING([--disable-openmpt123], [Disable the openmpt123 command line player.]))
AM_CONDITIONAL([ENABLE_OPENMPT123], [test "x$enable_openmpt123" != "xno"])


# examples
AC_ARG_ENABLE([examples], AS_HELP_STRING([--disable-examples], [Disable the example programs.]))
AM_CONDITIONAL([ENABLE_EXAMPLES], [test "x$enable_examples" != "xno"])

# tests
AC_ARG_ENABLE([tests], AS_HELP_STRING([--disable-tests], [Disable the test suite.]))
AM_CONDITIONAL([ENABLE_TESTS], [test "x$enable_tests" != "xno"])

# Optional openmpt123 and examples dependency
AC_ARG_WITH([portaudio], AS_HELP_STRING([--without-portaudio], [Disable use of libportaudio.]))
AS_IF([test "x$enable_openmpt123$enable_examples" != "xnono"],[
AS_IF([test "x$with_portaudio" != "xno"],
 [
  PKG_CHECK_MODULES([PORTAUDIO], [portaudio-2.0],
   [
    have_portaudio=1
    PORTAUDIO_CFLAGS="-DMPT_WITH_PORTAUDIO $PORTAUDIO_CFLAGS"
   ],
   [
    have_portaudio=0
    AC_MSG_ERROR([Unable to find libportaudio.])
   ]
  )
 ],
 [
  have_portaudio=0
 ]
)
],[have_portaudio=0])
AM_CONDITIONAL([HAVE_PORTAUDIO], [test x$have_portaudio = x1])

# Optional examples dependency: PortAudio C++
AC_ARG_WITH([portaudiocpp], AS_HELP_STRING([--without-portaudiocpp], [Disable use of libportaudiocpp.]))
AS_IF([test "x$enable_examples" != "xno"],[
AS_IF([test "x$with_portaudiocpp" != "xno"],
 [
  PKG_CHECK_MODULES([PORTAUDIOCPP], [portaudiocpp],
   [
    have_portaudiocpp=1
    PORTAUDIOCPP_CFLAGS="-DMPT_WITH_PORTAUDIOCPP $PORTAUDIOCPP_CFLAGS"
   ],
   [
    have_portaudiocpp=0
    AC_MSG_ERROR([Unable to find libportaudiocpp.])
   ]
  )
 ],
 [
  have_portaudiocpp=0
 ]
)
],[have_portaudiocpp=0])
AM_CONDITIONAL([HAVE_PORTAUDIOCPP], [test x$have_portaudiocpp = x1])

DX_DOXYGEN_FEATURE(OFF)
DX_DOT_FEATURE(OFF)
DX_HTML_FEATURE(OFF)

DX_MAN_FEATURE(OFF)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_RTF_FEATURE(OFF)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)

DX_INIT_DOXYGEN([tools/libopenmpt], [tools/Doxyfile], [doxygen-doc])

AC_DEFUN([AC_PROG_R], [AC_CHECK_PROG(R,R,yes)])
AC_PROG_R

AC_SUBST([PKG_CPPFLAGS],["${CXXFLAGS} ${PKG_CPPFLAGS} ${GLOBAL_CPPFLAGS} ${GLOBAL_CXXFLAGS}"])
AC_SUBST([PKG_LIBS],["${PKG_LIBS} ${ZLIB_LIBS} ${MPG123_LIBS} ${OGG_LIBS} ${VORBIS_LIBS} ${VORBISFILE_LIBS} ${PORTAUDIO_LIBS} ${PORTAUDIOCPP_LIBS} ${libopenmpt_libs}"])
AC_CONFIG_FILES([src/Makevars])

LIBS="$LIBS ${PKG_LIBS}"
LDFLAGS="${PKG_CPPFLAGS}"

AC_MSG_CHECKING([whether openmpt programs can be compiled])
AC_LANG([C++])
AC_LINK_IFELSE([AC_LANG_SOURCE([
#include <fstream>
#include <iostream>
#include <libopenmpt/libopenmpt.hpp>
int main() {
    std::ifstream file( "inst/cyberrid/cyberrid.mod", std::ios::binary );
    openmpt::module mod( file );
    mod.ctl_get_integer("dither");
    return 0;
}
])],[AC_MSG_RESULT(yes)],
[AC_MSG_ERROR([Cannot compile a simple openmpt program. See config.log for details.])])

AC_OUTPUT

echo "
${PACKAGE_NAME} $PACKAGE_VERSION
================

cflags:  ${PKG_CPPFLAGS}
libs:    ${PKG_LIBS}
"