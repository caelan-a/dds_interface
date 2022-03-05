#include "DDSUtils.h"

bool DDSUtils::is_type_library_present(const dds::core::QosProvider& qos_provider, const std::string& type_library_name) {
	for (auto e : qos_provider->type_libraries()) {
		if (type_library_name == e) {
			return true;
		}
	}
	return false;
}

// Makes sure library is correct then tries to create data_type and if it fails we know its not there
// There should be a way to either list the types from rti or do some better checking.
bool DDSUtils::is_data_type_present(const dds::core::QosProvider& qos_provider, const std::string& type_library_name, const std::string& data_type_name) {
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

//Util functions. TODO: Refactor into utils class
bool DDSUtils::file_exists(const std::string& name) {
	std::ifstream ifile;
	ifile.open(name);
	if (ifile) {
		return true;
	}
	else {
		return false;
	}
}

