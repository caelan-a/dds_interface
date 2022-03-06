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

class NotImplemented : public std::logic_error
{
public:
	NotImplemented() : std::logic_error("Function not yet implemented") { };
};


class DDSException : public std::exception
{
public:
	std::string m_msg;

	DDSException(const std::string& msg)
		: m_msg(msg)
	{}

	virtual const char* what() const throw()
	{
		return m_msg.c_str();;
	}
};
