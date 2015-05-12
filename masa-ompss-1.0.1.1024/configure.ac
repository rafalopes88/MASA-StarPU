AC_PREREQ([2.63])
AC_INIT([MASA-OmpSs], [1.0.1.1024], [edans.sandes@gmail.com], [masa-ompss], [https://sourceforge.net/projects/cudalign/])
AC_CONFIG_AUX_DIR(admin)
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES([Makefile])

AC_CONFIG_SUBDIRS([libs/masa-core])

AC_PROG_CXX

LIBMASA_PATH="libs/masa-core"

AC_CHECK_FILES(
	[$LIBMASA_PATH $LIBMASA_PATH/src],
	,
	AC_MSG_ERROR([
		MASA-Core source directory was not found: $LIBMASA_PATH/src.
	])
)


OPTIMIZATION="-O3"

AC_ARG_ENABLE([debug],
	AC_HELP_STRING([--enable-debug],[enable GDB debug]),
	[DEBUG="-ggdb --debug"; OPTIMIZATION=""]
)

AC_ARG_WITH([mcxx],
    AS_HELP_STRING([--with-mcxx=dir], [Change the path to look for the C++ compiler (CXX) to use when building the aligner, either mcxx or imcxx.]),
    [
        MCXXDIR="${withval}"
    ]
)

AC_PATH_PROGS([mcxx], [mcxx imcxx], [no], [$PATH$PATH_SEPARATOR$MCXXDIR/bin] )
if test "x$mcxx" = "xno" ; then
    AC_MSG_ERROR([Mercurium compiler not found. The aligner cannot be built.])
fi

OMPSS="--ompss -k"

AC_ARG_ENABLE([instrument],
	AC_HELP_STRING([--enable-instrument],[Enable OmpSs instrumentation]),
	[INSTRUMENTATION="--instrument" ]
)

AC_ARG_ENABLE([profiling],
	AC_HELP_STRING([--enable-profiling],[Enable Aligner profiling]),
	[if test x$enableval = xyes; then
		AC_DEFINE(ENABLE_PROFILING, 1, [Define this to enable aligner profiling.])
	fi]	
)

#default: 64bit
AC_ARG_ENABLE([32bit],
	AC_HELP_STRING([--enable-32bit],[force compilation in 32 bit mode.]),
	[ARCH="386"; PLATFORM="-m32";
		AC_MSG_NOTICE([Enabling 32bit compilation])
	],
	[ARCH="x86_64"; PLATFORM="-m64";
		AC_MSG_NOTICE([Enabling 64bit compilation])	
	]
)

# Setup OmpSs parts
# ------------------------------------------------------------------------------
#AM_CONDITIONAL([COMPILE_OMPSS], [test "x$use_ompss" = "xtrue"])

CXXFLAGS="-DUNIX $COMMONFLAGS $PLATFORM $OPTIMIZATION $DEBUG $OMPSS $INSTRUMENTATION -I$LIBMASA_PATH/src"

AC_SUBST(LIBMASA_PATH)
AC_SUBST(CXXFLAGS)

AC_OUTPUT
