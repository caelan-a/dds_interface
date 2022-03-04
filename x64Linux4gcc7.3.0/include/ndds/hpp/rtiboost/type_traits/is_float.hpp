//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef RTIBOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED
#define RTIBOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED

// should be the last #include
#include <rtiboost/type_traits/is_floating_point.hpp>

namespace rtiboost {

//* is a type T a floating-point type described in the standard (3.9.1p8)
   template <class T> struct is_float : public is_floating_point<T> {};
} // namespace rtiboost

#endif // RTIBOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED
