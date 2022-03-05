#include "DDSPublisher.h"

/*
See this document from RTi that describes in detail use of xml defined datatypes:
https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/manuals/connext_dds_professional/xml_application_creation/RTI_ConnextDDS_CoreLibraries_XML_AppCreation_GettingStartedGuide.pdf
*/


DDSPublisher::DDSPublisher(
	const std::string& config_xml_path,
	const std::string& topic_name,
	const std::string& data_type_name,
	const std::string& data_type_library_name,
	dds::core::QosProvider qos_provider,
	const dds::core::xtypes::DynamicType& data_type,
	dds::pub::DataWriter<dds::core::xtypes::DynamicData>&& writer
) :
	config_xml_path(config_xml_path),
	topic_name(topic_name),
	data_type_name(data_type_name),
	data_type_library_name(data_type_library_name),
	qos_provider(qos_provider),
	data_type(data_type),
	writer((dds::pub::DataWriter<dds::core::xtypes::DynamicData>&&)writer)
{
	std::cout << "Created DDSPublisher: [" + topic_name + "]\n";
}


DDSPublisher::~DDSPublisher() {
	std::cout << "Removing DDSPublisher\n";
}

DDSMessage DDSPublisher::create_message() {
	dds::core::xtypes::DynamicData sample = dds::core::xtypes::DynamicData(this->data_type);
	DDSMessage msg = DDSMessage(sample);

	return msg;
}

void DDSPublisher::publish(const dds::core::xtypes::DynamicData& message) {
	this->writer.write(message);
}

DDSPublisher DDSPublisher::CreateDDSPublisher(
	DDSInterface& dds_interface,
	const std::string& config_xml_path,
	const std::string& topic_name,
	const std::string& data_type_name,
	const std::string& data_type_library_name) {

	using namespace dds::core::xtypes;

	// Make sure file exists to avoid cryptic rti qosprovider exception. Throw our own better one
	if (!DDSUtils::file_exists(config_xml_path)) throw DDSException("no matching file " + config_xml_path + " to use for config_xml_path");

	dds::core::QosProvider& qos_provider = dds::core::QosProvider(config_xml_path);
	
	// Make sure type library exists
	if (!DDSUtils::is_type_library_present(qos_provider, data_type_library_name))  throw DDSException(data_type_library_name + " data type doesn't exist in " + config_xml_path);
	if (!DDSUtils:: is_data_type_present(qos_provider, data_type_library_name, data_type_name))  throw DDSException(data_type_name + " doesn't exist in " + data_type_library_name + " type library");

	// Check if type exists
	const dds::core::xtypes::DynamicType& data_type = qos_provider->type(data_type_library_name, data_type_name);

	dds::topic::Topic<DynamicData> topic(dds_interface.get_participant(), topic_name, data_type);
	dds::pub::DataWriter<dds::core::xtypes::DynamicData>&& writer = dds::pub::DataWriter<dds::core::xtypes::DynamicData>(dds::pub::Publisher(dds_interface.get_participant()), topic);

	return DDSPublisher(
		config_xml_path,
		topic_name,
		data_type_name,
		data_type_library_name,
		qos_provider,
		data_type,
		std::move(writer)
	);
}
