//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef RTIBOOST_TT_HAS_POST_DECREMENT_HPP_INCLUDED
#define RTIBOOST_TT_HAS_POST_DECREMENT_HPP_INCLUDED

#include <rtiboost/type_traits/is_array.hpp>

#define RTIBOOST_TT_TRAIT_NAME has_post_decrement
#define RTIBOOST_TT_TRAIT_OP --
#define RTIBOOST_TT_FORBIDDEN_IF\
   (\
      /* bool */\
      ::rtiboost::is_same< bool, Lhs_nocv >::value || \
      /* void* */\
      (\
         ::rtiboost::is_pointer< Lhs_noref >::value && \
         ::rtiboost::is_void< Lhs_noptr >::value\
      ) || \
      /* (fundamental or pointer) and const */\
      (\
         ( \
            ::rtiboost::is_fundamental< Lhs_nocv >::value || \
            ::rtiboost::is_pointer< Lhs_noref >::value\
         ) && \
         ::rtiboost::is_const< Lhs_noref >::value\
      )||\
      /* Arrays */ \
      ::rtiboost::is_array<Lhs_noref>::value\
      )


#include <rtiboost/type_traits/detail/has_postfix_operator.hpp>

#undef RTIBOOST_TT_TRAIT_NAME
#undef RTIBOOST_TT_TRAIT_OP
#undef RTIBOOST_TT_FORBIDDEN_IF

#endif
