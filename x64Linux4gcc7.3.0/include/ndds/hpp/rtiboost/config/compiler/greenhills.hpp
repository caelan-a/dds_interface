//  (C) Copyright John Maddock 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Greenhills C++ compiler setup:

#define RTIBOOST_COMPILER "Greenhills C++ version " RTIBOOST_STRINGIZE(__ghs) " __EDG_VERSION__ " RTIBOOST_STRINGIZE(__EDG_VERSION__)

#include "rtiboost/config/compiler/common_edg.hpp"

//
// RTI -- need to define RTIBOOST_HAS_PTHREADS on Integrity platforms
//
// Without threading support, shared_ptr uses an implementation
// that is not thread-safe.
//
#define RTIBOOST_HAS_THREADS
#define RTIBOOST_HAS_PTHREADS

//
// versions check:
// we don't support Greenhills prior to version 0:
#if __ghs < 0
#  error "Compiler not supported or configured - please reconfigure"
#endif
//
// last known and checked version is 0:
#if (__ghs > 0)
#  if defined(RTIBOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  endif
#endif


