AC_INIT([libopenmpt], [0.7.13+release.autotools], [https://bugs.openmpt.org/], [libopenmpt], [https://lib.openmpt.org/])
AC_PREREQ([2.69])
# we do want 2.70, but distributions are not ready yet
#AC_PREREQ([2.70])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_FILES([Makefile libopenmpt/libopenmpt.pc Doxyfile])

AM_INIT_AUTOMAKE([1.11 -Wall -Werror foreign subdir-objects])

AC_USE_SYSTEM_EXTENSIONS

AM_PROG_AR

LT_INIT

AC_SYS_LARGEFILE

PKG_PROG_PKG_CONFIG([0.24])
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_INSTALL

# We need C++17 support.
AX_CXX_COMPILE_STDCXX([20], [noext], [optional])
AS_IF([test "x$HAVE_CXX20" != "x1"],
 [
  AX_CXX_COMPILE_STDCXX([17], [noext], [mandatory])
 ],[]
)

GLOBAL_CPPFLAGS=
GLOBAL_CFLAGS=
GLOBAL_CXXFLAGS=

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

DX_DOXYGEN_FEATURE(ON)
DX_DOT_FEATURE(OFF)
DX_HTML_FEATURE(ON)

DX_MAN_FEATURE(OFF)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_RTF_FEATURE(OFF)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)

DX_INIT_DOXYGEN([libopenmpt], [Doxyfile], [doxygen-doc])

## now use all these TODO
# AC_SUBST([PKG_CPPFLAGS],["${PKG_CPPFLAGS} ${CXXFLAGS} ${protobuf_cxxflags}"])
# AC_SUBST([PKG_LIBS],["${PKG_LIBS} ${protobuf_libs}"])
# AC_CONFIG_FILES([src/Makevars])
# AC_OUTPUT

echo "
printf("prepared Makevars")
${PACKAGE_NAME} $PACKAGE_VERSION
================

cflags:  ${PKG_CPPFLAGS}
libs:    ${PKG_LIBS}
"
