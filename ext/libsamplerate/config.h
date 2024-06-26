/*
** Copyright (c) 2002-2016, Erik de Castro Lopo <erikd@mega-nerd.com>
** All rights reserved.
**
** This code is released under 2-clause BSD license. Please see the
** file at : https://github.com/erikd/libsamplerate/blob/master/COPYING
*/

/*
** This is the Win32 specific config.h header file. //PINMAME: changed to include both WIN32 and others (hopefully)
**
** On Unix (including MacOSX), this header file is automatically generated
** during the configure process while on Win32 this has to be hand edited
** to keep it up to date.
**
** This is also a good file to add Win32 specific things.
*/

/*
** MSVC++ assumes that all floating point constants without a trailing
** letter 'f' are double precision.
**
** If this assumption is incorrect and one of these floating point constants
** is assigned to a float variable MSVC++ generates a warning.
**
** Since there are currently about 25000 of these warnings generated in
** src/src_sinc.c this slows down compile times considerably. The
** following #pragma disables the warning.
*/

//#pragma warning(disable: 4305)

/*----------------------------------------------------------------------------
** Normal #defines follow.
*/

#if (defined(_M_IX86_FP) && _M_IX86_FP >= 2) || defined(__SSE2__) || defined(_M_X64) || defined(_M_AMD64) || defined(__ia64__) || defined(__x86_64__)
 #define RESAMPLER_SSE_OPT
 #define HAVE_IMMINTRIN_H
#elif (defined(_M_ARM) || defined(_M_ARM64) || defined(__arm__) || defined(__arm64__) || defined(__aarch64__)) && (!defined(__ARM_ARCH) || __ARM_ARCH >= 7) && (!defined(_MSC_VER) || defined(__clang__)) //!! disable sse2neon if MSVC&non-clang
 #define RESAMPLER_SSE_OPT // uses sse2neon then
 #define HAVE_IMMINTRIN_H
#else
 #pragma message ( "Warning: No SSE2 optimizations for Resampler enabled" )
#endif

/* Set to 1 if the compile is GNU GCC. */
#ifdef _MSC_VER
#define COMPILER_IS_GCC 0
#else
#define COMPILER_IS_GCC 1
#endif

/* Target processor clips on negative float to int conversion. */
#define CPU_CLIPS_NEGATIVE 0

/* Target processor clips on positive float to int conversion. */
#define CPU_CLIPS_POSITIVE 0

/* Target processor is big endian. */
#define CPU_IS_BIG_ENDIAN 0

/* Target processor is little endian. */
#define CPU_IS_LITTLE_ENDIAN 1

/* Set to 1 to enable debugging. */
#define ENABLE_DEBUG 0

/* Major version of GCC or 3 otherwise. */
/* #undef GCC_MAJOR_VERSION */

/* Define to 1 if you have the `alarm' function. */
/* #undef HAVE_ALARM */

/* Define to 1 if you have the `calloc' function. */
#define HAVE_CALLOC 1

/* Define to 1 if you have the `ceil' function. */
#define HAVE_CEIL 1

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Set to 1 if you have libfftw3. */
/* #undef HAVE_FFTW3 */

/* Define to 1 if you have the `floor' function. */
#define HAVE_FLOOR 1

/* Define to 1 if you have the `fmod' function. */
#define HAVE_FMOD 1

/* Define to 1 if you have the `free' function. */
#define HAVE_FREE 1

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the `m' library (-lm). */
/* #undef HAVE_LIBM */

/* Define if you have C99's lrint/lrintf functions. */
#if (defined(__STDC_VERSION__) &&  (__STDC_VERSION__ >= 199901L)) || (defined(_MSC_VER) && (_MSC_VER >= 1800)) || (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 600)) || _ISOC99_SOURCE || (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L))
 #define HAVE_LRINT 1
 #define HAVE_LRINTF 1
#else
 #define HAVE_LRINT 0
 #define HAVE_LRINTF 0
#endif

/* Define to 1 if you have the `malloc' function. */
#define HAVE_MALLOC 1

/* Define to 1 if you have the `memcpy' function. */
#define HAVE_MEMCPY 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if you have signal SIGALRM. */
/* #undef HAVE_SIGALRM */

/* Define to 1 if you have the `signal' function. */
/* #undef HAVE_SIGNAL */

/* Set to 1 if you have libsndfile. */
#define HAVE_SNDFILE 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/times.h> header file. */
/* #undef HAVE_SYS_TIMES_H */

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
/* #undef NO_MINUS_C_MINUS_O */

/* Set to 1 if compiling for Win32 */
#ifdef _WIN32
#define OS_IS_WIN32 1
#else
#define OS_IS_WIN32 0
#endif

/* Name of package */
#define PACKAGE "libsamplerate"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "erikd@mega-nerd.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME "libsamplerate"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libsamplerate 0.1.9"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libsamplerate"

/* Define to the home page for this package. */
#define PACKAGE_URL "http://www.mega-nerd.com/libsamplerate/"

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.1.9"

/* The size of `double', as computed by sizeof. */
#define SIZEOF_DOUBLE 8

/* The size of `float', as computed by sizeof. */
#define SIZEOF_FLOAT 4

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "0.1.9"



/* Extra Win32 hacks. */

/*
**	Microsoft's compiler still does not support the 1999 ISO C Standard
**	which includes 'inline'.
*/

#if defined(_MSC_VER) && _MSC_VER < 1920
 #define inline __inline
#endif
