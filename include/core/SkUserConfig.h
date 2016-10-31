
///////////////////////////////////////////////////////////////////////////////
//
// THIS FILE IS AUTOGENERATED BY GYP_TO_ANDROID.PY. DO NOT EDIT.
//
// This file contains Skia's upstream include/config/SkUserConfig.h as a
// reference, followed by the actual defines set for Android.
//
///////////////////////////////////////////////////////////////////////////////


/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkUserConfig_DEFINED
#define SkUserConfig_DEFINED

/*  SkTypes.h, the root of the public header files, does the following trick:

    #include "SkPreConfig.h"
    #include "SkUserConfig.h"
    #include "SkPostConfig.h"

    SkPreConfig.h runs first, and it is responsible for initializing certain
    skia defines.

    SkPostConfig.h runs last, and its job is to just check that the final
    defines are consistent (i.e. that we don't have mutually conflicting
    defines).

    SkUserConfig.h (this file) runs in the middle. It gets to change or augment
    the list of flags initially set in preconfig, and then postconfig checks
    that everything still makes sense.

    Below are optional defines that add, subtract, or change default behavior
    in Skia. Your port can locally edit this file to enable/disable flags as
    you choose, or these can be delared on your command line (i.e. -Dfoo).

    By default, this include file will always default to having all of the flags
    commented out, so including it will have no effect.
*/

///////////////////////////////////////////////////////////////////////////////

/*  Skia has lots of debug-only code. Often this is just null checks or other
    parameter checking, but sometimes it can be quite intrusive (e.g. check that
    each 32bit pixel is in premultiplied form). This code can be very useful
    during development, but will slow things down in a shipping product.

    By default, these mutually exclusive flags are defined in SkPreConfig.h,
    based on the presence or absence of NDEBUG, but that decision can be changed
    here.
 */
//#define SK_DEBUG
//#define SK_RELEASE

/*  Skia has certain debug-only code that is extremely intensive even for debug
    builds.  This code is useful for diagnosing specific issues, but is not
    generally applicable, therefore it must be explicitly enabled to avoid
    the performance impact. By default these flags are undefined, but can be
    enabled by uncommenting them below.
 */
//#define SK_DEBUG_GLYPH_CACHE
//#define SK_DEBUG_PATH

/*  preconfig will have attempted to determine the endianness of the system,
    but you can change these mutually exclusive flags here.
 */
//#define SK_CPU_BENDIAN
//#define SK_CPU_LENDIAN

/*  Most compilers use the same bit endianness for bit flags in a byte as the
    system byte endianness, and this is the default. If for some reason this
    needs to be overridden, specify which of the mutually exclusive flags to
    use. For example, some atom processors in certain configurations have big
    endian byte order but little endian bit orders.
*/
//#define SK_UINT8_BITFIELD_BENDIAN
//#define SK_UINT8_BITFIELD_LENDIAN


/*  To write debug messages to a console, skia will call SkDebugf(...) following
    printf conventions (e.g. const char* format, ...). If you want to redirect
    this to something other than printf, define yours here
 */
//#define SkDebugf(...)  MyFunction(__VA_ARGS__)

/*
 *  To specify a different default font cache limit, define this. If this is
 *  undefined, skia will use a built-in value.
 */
//#define SK_DEFAULT_FONT_CACHE_LIMIT   (1024 * 1024)

/*
 *  To specify the default size of the image cache, undefine this and set it to
 *  the desired value (in bytes). SkGraphics.h as a runtime API to set this
 *  value as well. If this is undefined, a built-in value will be used.
 */
//#define SK_DEFAULT_IMAGE_CACHE_LIMIT (1024 * 1024)

/*  Define this to provide font subsetter in PDF generation.
 */
//#define SK_SFNTLY_SUBSETTER "sample/chromium/font_subsetter.h"

/*  Define this to set the upper limit for text to support LCD. Values that
    are very large increase the cost in the font cache and draw slower, without
    improving readability. If this is undefined, Skia will use its default
    value (e.g. 48)
 */
//#define SK_MAX_SIZE_FOR_LCDTEXT     48

/*  If SK_DEBUG is defined, then you can optionally define SK_SUPPORT_UNITTEST
    which will run additional self-tests at startup. These can take a long time,
    so this flag is optional.
 */
#ifdef SK_DEBUG
//#define SK_SUPPORT_UNITTEST
#endif

/*  Change the ordering to work in X windows.
 */
#ifdef SK_SAMPLES_FOR_X
        #define SK_R32_SHIFT    16
        #define SK_G32_SHIFT    8
        #define SK_B32_SHIFT    0
        #define SK_A32_SHIFT    24
#endif


/* Determines whether to build code that supports the GPU backend. Some classes
   that are not GPU-specific, such as SkShader subclasses, have optional code
   that is used allows them to interact with the GPU backend. If you'd like to
   omit this code set SK_SUPPORT_GPU to 0. This also allows you to omit the gpu
   directories from your include search path when you're not building the GPU
   backend. Defaults to 1 (build the GPU code).
 */
//#define SK_SUPPORT_GPU 1

/* Skia makes use of histogram logging macros to trace the frequency of
 * events. By default, Skia provides no-op versions of these macros.
 * Skia consumers can provide their own definitions of these macros to
 * integrate with their histogram collection backend.
 */
//#define SK_HISTOGRAM_BOOLEAN(name, value)
//#define SK_HISTOGRAM_ENUMERATION(name, value, boundary_value)

#endif

// Android defines:
#ifndef SkUserConfig_Android_DEFINED
#define SkUserConfig_Android_DEFINED
#ifdef ANDROID
    #include <utils/misc.h>
#endif

#if __BYTE_ORDER == __BIG_ENDIAN
    #define SK_CPU_BENDIAN
    #undef  SK_CPU_LENDIAN
#else
    #define SK_CPU_LENDIAN
    #undef  SK_CPU_BENDIAN
#endif

#define DCT_IFAST_SUPPORTED
#define GR_GL_CUSTOM_SETUP_HEADER "gl/GrGLConfig_chrome.h"
#define GR_GL_USE_NEW_SHADER_SOURCE_SIGNATURE 1
#define QT_NO_KEYWORDS
#define SKIA
#define SKIA_DLL
#define SK_ALLOW_STATIC_GLOBAL_INITIALIZERS 0
#define SK_BUILD_FOR_ANDROID
#define SK_BUILD_FOR_ANDROID_FRAMEWORK
#define SK_CAN_USE_DLOPEN 0
#define SK_CODEC_DECODES_RAW
#define SK_DEFAULT_FONT_CACHE_LIMIT   (768 * 1024)
#define SK_DEFAULT_GLOBAL_DISCARDABLE_MEMORY_POOL_SIZE (512 * 1024)
#define SK_FONTHOST_FREETYPE_RUNTIME_VERSION 0x020400
#define SK_FORCE_DISTANCE_FIELD_TEXT 0
#define SK_GAMMA_APPLY_TO_A8
#define SK_GAMMA_CONTRAST 0.0
#define SK_GAMMA_EXPONENT 1.4
#define SK_HAS_JPEG_LIBRARY
#define SK_HAS_PNG_LIBRARY
#define SK_HAS_WEBP_LIBRARY
#define SK_IGNORE_ETC1_SUPPORT
#define SK_IGNORE_GPU_DITHER
#define SK_IGNORE_LINEONLY_AA_CONVEX_PATH_OPTS
#define SK_INTERNAL
#define SK_IS_BOT
#define SK_PDF_USE_SFNTLY
#define SK_PRINT_CODEC_MESSAGES
#define SK_SUPPORT_GPU 1
#define SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
#define SK_SUPPORT_LEGACY_CLIP_REGIONOPS
#define SK_SUPPORT_LEGACY_COLOR_SPACE_FACTORIES
#define SK_SUPPORT_LEGACY_DRAWFILTER
#define SK_SUPPORT_LEGACY_GRADIENT_DITHERING
#define SK_SUPPORT_LEGACY_SHADER_ASALOCALMATRIXSHADER
#define SK_SUPPORT_LEGACY_SHADER_ISABITMAP
#define SK_SUPPORT_LEGACY_UNBALANCED_PIXELREF_LOCKCOUNT
#define SK_USE_FREETYPE_EMBOLDEN
#define SK_VULKAN

#endif // SkUserConfig_Android_DEFINED
