/*

VTK_FREETYPE_CHANGE this file is new for VTK.

*/

#ifndef _freetypeConfig_h
#define _freetypeConfig_h

/* 
   Static or shared lib flags
*/
#define VTKFREETYPE_DLL
/* #undef VTKFREETYPE_STATIC */

/* 
   HPUX workaround
*/
/* #undef VTKFREETYPE_HPUX_SOURCE */
#if defined(VTKFREETYPE_HPUX_SOURCE) && !defined(_HPUX_SOURCE)
#define _HPUX_SOURCE
#endif

/* 
   Enable or disable freetype's Mac font support.
   DARWIN_NO_CARBON is the freetype define that makes the choice.
*/
/* #undef VTKFREETYPE_MAC_FONT_SUPPORT */
#if !defined(VTKFREETYPE_MAC_FONT_SUPPORT) && !defined(DARWIN_NO_CARBON)
#define DARWIN_NO_CARBON
#endif

#define FT2_BUILD_LIBRARY 1

#endif
