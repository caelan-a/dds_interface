#pragma once

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
//#include <dds/core/macros.hpp>

#include <iostream>
#include <string>
#include <map>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>  // for sleep()
#include <rti/config/Logger.hpp>  // for logging
#include <dds/core/ddscore.hpp>

#include "DDSInterface.h"

class DDSPublisher
{
private:
	std::string config_xml_path;
	std::string qos_file_path;

	std::string topic_name;
	std::string data_type_name;
	std::string data_type_library_name;

	dds::core::QosProvider qos_provider;
	const dds::core::xtypes::DynamicType& data_type;
	dds::pub::DataWriter<dds::core::xtypes::DynamicData> writer;
	

	bool should_terminate = false;

public:
	static DDSPublisher CreateDDSPublisher(
		DDSInterface& dds_interface,
		const std::string& data_types_xml_file_path,
		const std::string& topic_name,
		const std::string& data_type_name,
		const std::string& data_type_library_name);

	DDSPublisher(
		const std::string& config_xml_path,
		const std::string& topic_name,
		const std::string& data_type_name,
		const std::string& data_type_library_name,
		dds::core::QosProvider qos_provider,
		const dds::core::xtypes::DynamicType& data_type,
		dds::pub::DataWriter<dds::core::xtypes::DynamicData>&& writer
		);

	~DDSPublisher();

	dds::core::xtypes::DynamicData create_message();
	void publish(const dds::core::xtypes::DynamicData&);
};
