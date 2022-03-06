#pragma once

#include <iostream>
#include <string>
#include <map>
#include <exception>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>  // for sleep()
#include <rti/config/Logger.hpp>  // for logging
#include <dds/core/ddscore.hpp>

#include <fstream>
#include <iostream>
#include <dds/core/Exception.hpp>

#include "DDSMessage.h"
#include "DDSInterface.h"
#include "DDSUtils.h"

/*
This class is used to contain and manage all the resources necessary to publish a specific data_type to a specified topic.
It makes sure all the values given are valid and present during creation.
*/
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
	DDSPublisher();
		
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

	DDSMessage create_message();

	/* Publish message to the DDS network */
	void publish(DDSMessage& msg);
};
