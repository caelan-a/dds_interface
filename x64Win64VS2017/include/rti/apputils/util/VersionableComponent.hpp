/*
(c) Copyright, Real-Time Innovations, 2018.
All rights reserved.
No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/
#ifndef HPP_RTI_APPUTILS_VERSIONABLECOMPONENT_HPP_
#define HPP_RTI_APPUTILS_VERSIONABLECOMPONENT_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <sstream>
#include <string>
#include <stdint.h>

#include "rtiboost/assert.hpp"
#include "dds/core/Exception.hpp"

namespace rti { namespace apputils { namespace util {

class ComponentVersion {
public:

    ComponentVersion() : major_(0), minor_(0)
    {
        init_version_str();
    }
    ComponentVersion(const uint8_t major, const uint8_t minor) :
        major_(major),
        minor_(minor)
    {
        init_version_str();
    }
    ComponentVersion(const std::string& version_str) :
        major_(0),
        minor_(0)
    {
        std::istringstream stream(version_str);
        std::stringstream error_stream;

        error_stream << "VersionableComponent: invalid version string: "
                << version_str.c_str();

        int16_t value;
        stream >> value;
        if (stream.fail()) {
            throw dds::core::InvalidArgumentError(error_stream.str());
        }
        major_ = (uint8_t) value;
        char character;
        stream >> character;
        if (stream.fail()) {
            throw dds::core::InvalidArgumentError(error_stream.str());
        }
        RTIBOOST_ASSERT(character == '.');
        stream >> value;
        if (stream.fail()) {
            throw dds::core::InvalidArgumentError(error_stream.str());
        }
        minor_ = (uint8_t) value;
        version_str_ = version_str;
    }
    ~ComponentVersion() { }

    uint8_t get_major() const { return major_; }
    uint8_t get_minor() const { return minor_; }

    bool operator ==(const ComponentVersion& other) const
    {
        return (major_ == other.major_ && minor_ == other.minor_);
    }

    bool operator !=(const ComponentVersion& other) const
    {
        return !(*this == other);
    }

    bool operator < (const ComponentVersion& other) const
    {
        if ((int16_t) major_ - (int16_t) other.major_ == 0) {
            return ((int16_t) minor_ - (int16_t) other.minor_ < 0);
        } else {
            return ((int16_t) major_ - (int16_t) other.major_ < 0);
        }
    }

    bool operator > (const ComponentVersion& other) const
    {
        if ((int16_t) major_ - (int16_t) other.major_ == 0) {
            return ((int16_t) minor_ - (int16_t) other.minor_ > 0);
        } else {
            return ((int16_t) major_ - (int16_t) other.major_ > 0);
        }
    }

    operator const std::string&() const
    {
        return version_str_;
    }

private:
    uint8_t major_;
    uint8_t minor_;
    std::string version_str_;

    void init_version_str()
    {
        if (version_str_.empty()) {
            std::ostringstream stream;
            stream << (int16_t) major_ << "." << (int16_t) minor_;
            version_str_ = stream.str();
        }
    }
};

/**
 * @brief A versionable component has a name and a version and it's used to
 *        keep track of the versions of the components used to record data.
 *        This information is kept in the 'metadata' database file. It can later
 *        be recovered by Replay/Converter to use exactly the same components'
 *        versions that were when recording.
 * @param VersionType The version object to be used. By default, the Version
 *        type implemented above is used (a simple, two-digit, stringifyable
 *        version type).
 */
template<typename VersionType>
class VersionableComponent {
public:

    VersionableComponent(
            std::string component_name,
            const VersionType& version) :
        component_name_(component_name),
        version_(version) { }

    const VersionType& version() const { return version_; }

    const std::string& component_name() const { return component_name_; }

    void verify_version(const VersionType& version) const
    {
        if (version > version_) {
            std::stringstream error_stream;
            error_stream << "VersionableComponent: " << component_name_.c_str()
                    << ": detected newer version. The current version of the "
                    << "component in this tool ("
                    <<  ((const std::string&) version_).c_str()
                    << ") is unable to read the newer "
                    << component_name_.c_str() <<" version ("
                    << ((const std::string&) version).c_str() <<") found ";
            throw dds::core::IllegalOperationError(error_stream.str());
        }
    }

private:
    std::string component_name_;
    VersionType version_;
};

typedef VersionableComponent<ComponentVersion> DefaultVersionableComponent;

} } } /* namespace rti::apputils::util */

#endif /* HPP_RTI_APPUTILS_VERSIONABLECOMPONENT_HPP_ */
