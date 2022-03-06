#pragma once

#include <iostream>
#include <csignal>
#include <dds/core/ddscore.hpp>

#include "DDSUtils.h"

/*
This class is used to create a message that can be published.
It provides functions to safely set data and retrieve information about the message state
*/
class DDSMessage
{

public:
	DDSMessage(const dds::core::xtypes::DynamicData& dynamic_data);

	template <class T>
	void set_dynamic_value(const std::string& key, const T& value);

	/* Set string member type in message */
	void set_string(const std::string& key, const std::string& value);

	/* Print message type and current state of member fields */
	void print();

	/* Get underlying dynamic data that is used in publishing. Useful to access lower level RTi functionality */
	dds::core::xtypes::DynamicData& get_dynamic_data();

	friend std::ostream& operator<<(std::ostream& os, const DDSMessage& msg);


private:
	dds::core::xtypes::DynamicData dynamic_data;
};

/* Set's dynamic value. Remember to cast your value first, especially if its ambiguous. Eg. (short)int_var */
template<class T>
inline void DDSMessage::set_dynamic_value(const std::string& key, const T& value)
{
	try {
		this->dynamic_data.value<T>(key, value);
	}
	catch (dds::core::IllegalOperationError e) {
		throw DDSException("Failed to set " + key + " field dynamically. Is the value being correctly cast?");
	}
}
