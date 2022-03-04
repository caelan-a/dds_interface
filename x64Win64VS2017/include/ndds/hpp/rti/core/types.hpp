#ifndef RTI_DDS_CORE_TYPES_HPP_
#define RTI_DDS_CORE_TYPES_HPP_

/* Copyright 2019, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

namespace rti {
/**
 * @brief @extension Extensions to dds::core
 */
namespace core {

/**
 * @ingroup DDSCPP2SupportingTypes
 * @brief A tag type that selects the to_string overload that prints all the
 * values of a Qos object.
 *
 * The only value of this type is rti::core::qos_print_all, and is used only as
 * a sentinel to select one of the to_string overloads.
 *
 * For example:
 *
 * auto s = to_string(my_reader_qos, ..., rti::core::qos_print_all);
 *
 * See rti::sub::qos::to_string(...).
 *
 * @see rti::sub::qos::to_string
 */
struct qos_print_all_t
{
};

/**
 * @ingroup DDSCPP2SupportingTypes
 * @brief Sentinel value that selects the to_string overload that prints all of
 * the values of a Qos object.
 * @see rti::sub::qos::to_string
 */
extern OMG_DDS_API_VARIABLE const qos_print_all_t qos_print_all;

} // namespace core

} // namespace rti

#endif // RTI_DDS_CORE_TYPES_HPP_

