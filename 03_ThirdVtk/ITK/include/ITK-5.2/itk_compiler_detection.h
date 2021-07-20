
// This is a generated file. Do not edit!

#ifndef ITK_COMPILER_DETECTION_H
#define ITK_COMPILER_DETECTION_H

#ifdef __cplusplus
# define ITK_COMPILER_IS_Comeau 0
# define ITK_COMPILER_IS_Intel 0
# define ITK_COMPILER_IS_IntelLLVM 0
# define ITK_COMPILER_IS_PathScale 0
# define ITK_COMPILER_IS_Embarcadero 0
# define ITK_COMPILER_IS_Borland 0
# define ITK_COMPILER_IS_Watcom 0
# define ITK_COMPILER_IS_OpenWatcom 0
# define ITK_COMPILER_IS_SunPro 0
# define ITK_COMPILER_IS_HP 0
# define ITK_COMPILER_IS_Compaq 0
# define ITK_COMPILER_IS_zOS 0
# define ITK_COMPILER_IS_XLClang 0
# define ITK_COMPILER_IS_XL 0
# define ITK_COMPILER_IS_VisualAge 0
# define ITK_COMPILER_IS_NVHPC 0
# define ITK_COMPILER_IS_PGI 0
# define ITK_COMPILER_IS_Cray 0
# define ITK_COMPILER_IS_TI 0
# define ITK_COMPILER_IS_FujitsuClang 0
# define ITK_COMPILER_IS_Fujitsu 0
# define ITK_COMPILER_IS_GHS 0
# define ITK_COMPILER_IS_SCO 0
# define ITK_COMPILER_IS_ARMCC 0
# define ITK_COMPILER_IS_AppleClang 0
# define ITK_COMPILER_IS_ARMClang 0
# define ITK_COMPILER_IS_Clang 0
# define ITK_COMPILER_IS_GNU 0
# define ITK_COMPILER_IS_MSVC 0
# define ITK_COMPILER_IS_ADSP 0
# define ITK_COMPILER_IS_IAR 0
# define ITK_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef ITK_COMPILER_IS_Comeau
# define ITK_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef ITK_COMPILER_IS_Intel
# define ITK_COMPILER_IS_Intel 1

#elif (defined(__clang__) && defined(__INTEL_CLANG_COMPILER)) || defined(__INTEL_LLVM_COMPILER)
# undef ITK_COMPILER_IS_IntelLLVM
# define ITK_COMPILER_IS_IntelLLVM 1

#elif defined(__PATHCC__)
# undef ITK_COMPILER_IS_PathScale
# define ITK_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef ITK_COMPILER_IS_Embarcadero
# define ITK_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef ITK_COMPILER_IS_Borland
# define ITK_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef ITK_COMPILER_IS_Watcom
# define ITK_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef ITK_COMPILER_IS_OpenWatcom
# define ITK_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef ITK_COMPILER_IS_SunPro
# define ITK_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef ITK_COMPILER_IS_HP
# define ITK_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef ITK_COMPILER_IS_Compaq
# define ITK_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef ITK_COMPILER_IS_zOS
# define ITK_COMPILER_IS_zOS 1

#elif defined(__ibmxl__) && defined(__clang__)
# undef ITK_COMPILER_IS_XLClang
# define ITK_COMPILER_IS_XLClang 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef ITK_COMPILER_IS_XL
# define ITK_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef ITK_COMPILER_IS_VisualAge
# define ITK_COMPILER_IS_VisualAge 1

#elif defined(__NVCOMPILER)
# undef ITK_COMPILER_IS_NVHPC
# define ITK_COMPILER_IS_NVHPC 1

#elif defined(__PGI)
# undef ITK_COMPILER_IS_PGI
# define ITK_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef ITK_COMPILER_IS_Cray
# define ITK_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef ITK_COMPILER_IS_TI
# define ITK_COMPILER_IS_TI 1

#elif defined(__CLANG_FUJITSU)
# undef ITK_COMPILER_IS_FujitsuClang
# define ITK_COMPILER_IS_FujitsuClang 1

#elif defined(__FUJITSU)
# undef ITK_COMPILER_IS_Fujitsu
# define ITK_COMPILER_IS_Fujitsu 1

#elif defined(__ghs__)
# undef ITK_COMPILER_IS_GHS
# define ITK_COMPILER_IS_GHS 1

#elif defined(__SCO_VERSION__)
# undef ITK_COMPILER_IS_SCO
# define ITK_COMPILER_IS_SCO 1

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# undef ITK_COMPILER_IS_ARMCC
# define ITK_COMPILER_IS_ARMCC 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef ITK_COMPILER_IS_AppleClang
# define ITK_COMPILER_IS_AppleClang 1

#elif defined(__clang__) && defined(__ARMCOMPILER_VERSION)
# undef ITK_COMPILER_IS_ARMClang
# define ITK_COMPILER_IS_ARMClang 1

#elif defined(__clang__)
# undef ITK_COMPILER_IS_Clang
# define ITK_COMPILER_IS_Clang 1

#elif defined(__GNUC__) || defined(__GNUG__)
# undef ITK_COMPILER_IS_GNU
# define ITK_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef ITK_COMPILER_IS_MSVC
# define ITK_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef ITK_COMPILER_IS_ADSP
# define ITK_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# undef ITK_COMPILER_IS_IAR
# define ITK_COMPILER_IS_IAR 1


#endif

#  if ITK_COMPILER_IS_MSVC

#    include "compilers/ITK_COMPILER_INFO_MSVC_CXX.h"

#  else
#    error Unsupported compiler
#  endif

#  if defined(ITK_COMPILER_CXX_ALIGNAS) && ITK_COMPILER_CXX_ALIGNAS
#    define ITK_ALIGNAS(X) alignas(X)
#  elif ITK_COMPILER_IS_GNU || ITK_COMPILER_IS_Clang || ITK_COMPILER_IS_AppleClang
#    define ITK_ALIGNAS(X) __attribute__ ((__aligned__(X)))
#  elif ITK_COMPILER_IS_MSVC
#    define ITK_ALIGNAS(X) __declspec(align(X))
#  else
#    define ITK_ALIGNAS(X)
#  endif


#  if defined(ITK_COMPILER_CXX_ALIGNOF) && ITK_COMPILER_CXX_ALIGNOF
#    define ITK_ALIGNOF(X) alignof(X)
#  elif ITK_COMPILER_IS_GNU || ITK_COMPILER_IS_Clang || ITK_COMPILER_IS_AppleClang
#    define ITK_ALIGNOF(X) __alignof__(X)
#  elif ITK_COMPILER_IS_MSVC
#    define ITK_ALIGNOF(X) __alignof(X)
#  endif


#  ifndef ITK_DEPRECATED
#    if defined(ITK_COMPILER_CXX_ATTRIBUTE_DEPRECATED) && ITK_COMPILER_CXX_ATTRIBUTE_DEPRECATED
#      define ITK_DEPRECATED [[deprecated]]
#      define ITK_DEPRECATED_MSG(MSG) [[deprecated(MSG)]]
#    elif ITK_COMPILER_IS_GNU || ITK_COMPILER_IS_Clang
#      define ITK_DEPRECATED __attribute__((__deprecated__))
#      define ITK_DEPRECATED_MSG(MSG) __attribute__((__deprecated__(MSG)))
#    elif ITK_COMPILER_IS_MSVC
#      define ITK_DEPRECATED __declspec(deprecated)
#      define ITK_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#    else
#      define ITK_DEPRECATED
#      define ITK_DEPRECATED_MSG(MSG)
#    endif
#  endif


#  if defined(ITK_COMPILER_CXX_CONSTEXPR) && ITK_COMPILER_CXX_CONSTEXPR
#    define ITK_CONSTEXPR constexpr
#  else
#    define ITK_CONSTEXPR 
#  endif


#  if defined(ITK_COMPILER_CXX_DELETED_FUNCTIONS) && ITK_COMPILER_CXX_DELETED_FUNCTIONS
#    define ITK_DELETED_FUNCTION = delete
#  else
#    define ITK_DELETED_FUNCTION 
#  endif


#  if defined(ITK_COMPILER_CXX_EXTERN_TEMPLATES) && ITK_COMPILER_CXX_EXTERN_TEMPLATES
#    define ITK_EXTERN_TEMPLATE extern
#  else
#    define ITK_EXTERN_TEMPLATE 
#  endif


#  if defined(ITK_COMPILER_CXX_FINAL) && ITK_COMPILER_CXX_FINAL
#    define ITK_FINAL final
#  else
#    define ITK_FINAL 
#  endif


#  if defined(ITK_COMPILER_CXX_NOEXCEPT) && ITK_COMPILER_CXX_NOEXCEPT
#    define ITK_NOEXCEPT noexcept
#    define ITK_NOEXCEPT_EXPR(X) noexcept(X)
#  else
#    define ITK_NOEXCEPT
#    define ITK_NOEXCEPT_EXPR(X)
#  endif


#  if defined(ITK_COMPILER_CXX_NULLPTR) && ITK_COMPILER_CXX_NULLPTR
#    define ITK_NULLPTR nullptr
#  elif ITK_COMPILER_IS_GNU
#    define ITK_NULLPTR __null
#  else
#    define ITK_NULLPTR 0
#  endif


#  if defined(ITK_COMPILER_CXX_OVERRIDE) && ITK_COMPILER_CXX_OVERRIDE
#    define ITK_OVERRIDE override
#  else
#    define ITK_OVERRIDE 
#  endif

#  if defined(ITK_COMPILER_CXX_STATIC_ASSERT) && ITK_COMPILER_CXX_STATIC_ASSERT
#    define ITK_STATIC_ASSERT(X) static_assert(X, #X)
#    define ITK_STATIC_ASSERT_MSG(X, MSG) static_assert(X, MSG)
#  else
#    define ITK_STATIC_ASSERT_JOIN(X, Y) ITK_STATIC_ASSERT_JOIN_IMPL(X, Y)
#    define ITK_STATIC_ASSERT_JOIN_IMPL(X, Y) X##Y
template<bool> struct ITKStaticAssert;
template<> struct ITKStaticAssert<true>{};
#    define ITK_STATIC_ASSERT(X) enum { ITK_STATIC_ASSERT_JOIN(ITKStaticAssertEnum, __LINE__) = sizeof(ITKStaticAssert<X>) }
#    define ITK_STATIC_ASSERT_MSG(X, MSG) enum { ITK_STATIC_ASSERT_JOIN(ITKStaticAssertEnum, __LINE__) = sizeof(ITKStaticAssert<X>) }
#  endif


#  if defined(ITK_COMPILER_CXX_THREAD_LOCAL) && ITK_COMPILER_CXX_THREAD_LOCAL
#    define ITK_THREAD_LOCAL thread_local
#  elif ITK_COMPILER_IS_GNU || ITK_COMPILER_IS_Clang || ITK_COMPILER_IS_AppleClang
#    define ITK_THREAD_LOCAL __thread
#  elif ITK_COMPILER_IS_MSVC
#    define ITK_THREAD_LOCAL __declspec(thread)
#  else
// ITK_THREAD_LOCAL not defined for this configuration.
#  endif

#endif

#endif
