/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing#kwsys for details.  */
#ifndef itksys_Configure_hxx
#define itksys_Configure_hxx

/* Include C configuration.  */
#include <itksys/Configure.h>

/* Whether wstring is available.  */
#define itksys_STL_HAS_WSTRING 1
/* Whether <ext/stdio_filebuf.h> is available. */
#define itksys_CXX_HAS_EXT_STDIO_FILEBUF_H                         \
  0
/* Whether the translation map is available or not. */
#define itksys_SYSTEMTOOLS_USE_TRANSLATION_MAP                     \
  1

#if defined(__SUNPRO_CC) && __SUNPRO_CC > 0x5130 && defined(__has_attribute)
#  define itksys__has_cpp_attribute(x) __has_attribute(x)
#elif defined(__has_cpp_attribute)
#  define itksys__has_cpp_attribute(x) __has_cpp_attribute(x)
#else
#  define itksys__has_cpp_attribute(x) 0
#endif

#if __cplusplus >= 201103L
#  define itksys_NULLPTR nullptr
#else
#  define itksys_NULLPTR 0
#endif

#ifndef itksys_FALLTHROUGH
#  if __cplusplus >= 201703L &&                                               \
    itksys__has_cpp_attribute(fallthrough)
#    define itksys_FALLTHROUGH [[fallthrough]]
#  elif __cplusplus >= 201103L &&                                             \
    itksys__has_cpp_attribute(gnu::fallthrough)
#    define itksys_FALLTHROUGH [[gnu::fallthrough]]
#  elif __cplusplus >= 201103L &&                                             \
    itksys__has_cpp_attribute(clang::fallthrough)
#    define itksys_FALLTHROUGH [[clang::fallthrough]]
#  endif
#endif
#ifndef itksys_FALLTHROUGH
#  define itksys_FALLTHROUGH static_cast<void>(0)
#endif

#undef itksys__has_cpp_attribute

/* If building a C++ file in kwsys itself, give the source file
   access to the macros without a configured namespace.  */
#if defined(KWSYS_NAMESPACE)
#  if !itksys_NAME_IS_KWSYS
#    define kwsys itksys
#  endif
#  define KWSYS_NAME_IS_KWSYS itksys_NAME_IS_KWSYS
#  define KWSYS_STL_HAS_WSTRING itksys_STL_HAS_WSTRING
#  define KWSYS_CXX_HAS_EXT_STDIO_FILEBUF_H                                   \
    itksys_CXX_HAS_EXT_STDIO_FILEBUF_H
#  define KWSYS_FALLTHROUGH itksys_FALLTHROUGH
#  define KWSYS_SYSTEMTOOLS_USE_TRANSLATION_MAP                               \
    itksys_SYSTEMTOOLS_USE_TRANSLATION_MAP
#endif

#endif
