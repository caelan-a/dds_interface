#pragma once

#include <iostream>
#include <csignal>
#include <dds/core/ddscore.hpp>

#include "DDSUtils.h"

class DDSMessage
{

public:
	DDSMessage(const dds::core::xtypes::DynamicData& dynamic_data);

	void set_string(const std::string& key, const std::string& value);
	void set_short(const short num);
	void set_long(const long num);

	void print();

	dds::core::xtypes::DynamicData& get_dynamic_data();


	friend std::ostream& operator<<(std::ostream& os, const DDSMessage& msg);


private:
	dds::core::xtypes::DynamicData dynamic_data;
};

