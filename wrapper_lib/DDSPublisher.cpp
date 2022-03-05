#include "DDSPublisher.h"

/*
See this document from RTi that describes in detail use of xml defined datatypes:
https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/manuals/connext_dds_professional/xml_application_creation/RTI_ConnextDDS_CoreLibraries_XML_AppCreation_GettingStartedGuide.pdf
*/

//Util functions. TODO: Refactor into utils class
bool file_exists(const std::string& name) {
	std::ifstream ifile;
	ifile.open(name);
	if (ifile) {
		return true;
	}
	else {
		return false;
	}
}

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

bool is_type_library_present(const dds::core::QosProvider& qos_provider, const std::string& type_library_name) {
	for (auto e : qos_provider->type_libraries()) {
		if (type_library_name == e) {
			return true;
		}
	}
	return false;
}

// Makes sure library is correct then tries to create data_type and if it fails we know its not there
// There should be a way to either list the types from rti or do some better checking.
bool is_data_type_present(const dds::core::QosProvider& qos_provider, const std::string& type_library_name, const std::string& data_type_name) {
	// Make sure library is present first
	if (is_type_library_present(qos_provider, type_library_name)) {
		try {
			const dds::core::xtypes::DynamicType& data_type = qos_provider->type(type_library_name, data_type_name);
			return true;
		}
		catch (dds::core::Error e) {
			// Didn't work so must be the data_type_name missing
			return false;
		}
	}

	return false;
}

DDSPublisher DDSPublisher::CreateDDSPublisher(
	DDSInterface& dds_interface,
	const std::string& config_xml_path,
	const std::string& topic_name,
	const std::string& data_type_name,
	const std::string& data_type_library_name) {

	using namespace dds::core::xtypes;

	// Make sure file exists to avoid cryptic rti qosprovider exception. Throw our own better one
	if (!file_exists(config_xml_path)) throw DDSException("no matching file " + config_xml_path + " to use for config_xml_path");

	dds::core::QosProvider& qos_provider = dds::core::QosProvider(config_xml_path);
	
	// Make sure type library exists
	if (!is_type_library_present(qos_provider, data_type_library_name))  throw DDSException(data_type_library_name + " data type doesn't exist in " + config_xml_path);
	if (!is_data_type_present(qos_provider, data_type_library_name, data_type_name))  throw DDSException(data_type_name + " doesn't exist in " + data_type_library_name + " type library");

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
