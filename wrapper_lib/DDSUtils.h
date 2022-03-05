#pragma once
#include <fstream>
#include <iostream>

#include <dds/core/ddscore.hpp>

class DDSUtils
{
public:
	static bool is_type_library_present(const dds::core::QosProvider& qos_provider, const std::string& type_library_name);
	static bool is_data_type_present(const dds::core::QosProvider& qos_provider, const std::string& type_library_name, const std::string& data_type_name);
	static bool file_exists(const std::string& name);
};

