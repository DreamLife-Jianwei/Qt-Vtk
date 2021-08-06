/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing#kwsys for details.  */
#ifndef vtksys_Configure_hxx
#define vtksys_Configure_hxx

/* Include C configuration.  */
#include <vtksys/Configure.h>

/* Whether wstring is available.  */
#define vtksys_STL_HAS_WSTRING 1
/* Whether <ext/stdio_filebuf.h> is available. */
#define vtksys_CXX_HAS_EXT_STDIO_FILEBUF_H                         \
  0
/* Whether the translation map is available or not. */
#define vtksys_SYSTEMTOOLS_USE_TRANSLATION_MAP                     \
  1

#if defined(__SUNPRO_CC) && __SUNPRO_CC > 0x5130 && defined(__has_attribute)
#  define vtksys__has_cpp_attribute(x) __has_attribute(x)
#elif defined(__has_cpp_attribute)
#  define vtksys__has_cpp_attribute(x) __has_cpp_attribute(x)
#else
#  define vtksys__has_cpp_attribute(x) 0
#endif

#if __cplusplus >= 201103L
#  define vtksys_NULLPTR nullptr
#else
#  define vtksys_NULLPTR 0
#endif

#ifndef vtksys_FALLTHROUGH
#  if __cplusplus >= 201703L &&                                               \
    vtksys__has_cpp_attribute(fallthrough)
#    define vtksys_FALLTHROUGH [[fallthrough]]
#  elif __cplusplus >= 201103L &&                                             \
    vtksys__has_cpp_attribute(gnu::fallthrough)
#    define vtksys_FALLTHROUGH [[gnu::fallthrough]]
#  elif __cplusplus >= 201103L &&                                             \
    vtksys__has_cpp_attribute(clang::fallthrough)
#    define vtksys_FALLTHROUGH [[clang::fallthrough]]
#  endif
#endif
#ifndef vtksys_FALLTHROUGH
#  define vtksys_FALLTHROUGH static_cast<void>(0)
#endif

#undef vtksys__has_cpp_attribute

/* If building a C++ file in kwsys itself, give the source file
   access to the macros without a configured namespace.  */
#if defined(KWSYS_NAMESPACE)
#  if !vtksys_NAME_IS_KWSYS
#    define kwsys vtksys
#  endif
#  define KWSYS_NAME_IS_KWSYS vtksys_NAME_IS_KWSYS
#  define KWSYS_STL_HAS_WSTRING vtksys_STL_HAS_WSTRING
#  define KWSYS_CXX_HAS_EXT_STDIO_FILEBUF_H                                   \
    vtksys_CXX_HAS_EXT_STDIO_FILEBUF_H
#  define KWSYS_FALLTHROUGH vtksys_FALLTHROUGH
#  define KWSYS_SYSTEMTOOLS_USE_TRANSLATION_MAP                               \
    vtksys_SYSTEMTOOLS_USE_TRANSLATION_MAP
#endif

#endif
