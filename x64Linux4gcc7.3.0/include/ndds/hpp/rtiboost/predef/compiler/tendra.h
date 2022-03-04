/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef RTIBOOST_PREDEF_COMPILER_TENDRA_H
#define RTIBOOST_PREDEF_COMPILER_TENDRA_H

#include <rtiboost/predef/version_number.h>
#include <rtiboost/predef/make.h>

/*`
[heading `RTIBOOST_COMP_TENDRA`]

[@http://en.wikipedia.org/wiki/TenDRA_Compiler TenDRA C/C++] compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__TenDRA__`] [__predef_detection__]]
    ]
 */

#define RTIBOOST_COMP_TENDRA RTIBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__TenDRA__)
#   define RTIBOOST_COMP_TENDRA_DETECTION RTIBOOST_VERSION_NUMBER_AVAILABLE
#endif

#ifdef RTIBOOST_COMP_TENDRA_DETECTION
#   if defined(RTIBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define RTIBOOST_COMP_TENDRA_EMULATED RTIBOOST_COMP_TENDRA_DETECTION
#   else
#       undef RTIBOOST_COMP_TENDRA
#       define RTIBOOST_COMP_TENDRA RTIBOOST_COMP_TENDRA_DETECTION
#   endif
#   define RTIBOOST_COMP_TENDRA_AVAILABLE
#   include <rtiboost/predef/detail/comp_detected.h>
#endif

#define RTIBOOST_COMP_TENDRA_NAME "TenDRA C/C++"

#endif

#include <rtiboost/predef/detail/test.h>
RTIBOOST_PREDEF_DECLARE_TEST(RTIBOOST_COMP_TENDRA,RTIBOOST_COMP_TENDRA_NAME)

#ifdef RTIBOOST_COMP_TENDRA_EMULATED
#include <rtiboost/predef/detail/test.h>
RTIBOOST_PREDEF_DECLARE_TEST(RTIBOOST_COMP_TENDRA_EMULATED,RTIBOOST_COMP_TENDRA_NAME)
#endif
