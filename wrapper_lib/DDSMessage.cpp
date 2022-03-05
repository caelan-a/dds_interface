#include "DDSMessage.h"

DDSMessage::DDSMessage(const dds::core::xtypes::DynamicData& dynamic_data) : dynamic_data(dynamic_data)
{

}

void DDSMessage::set_string(const std::string& key, const std::string& text)
{
	try {
		this->dynamic_data.value<std::string>(key, text);
	}
	catch (dds::core::Error e) {
		throw DDSException("Failed to set string value");
	}
}

void DDSMessage::print() {
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const DDSMessage& msg)
{
	os << "DDSMessage: " << msg.dynamic_data.type().name() << std::endl;
	os << "Members: " << std::endl << msg.dynamic_data << std::endl;
	return os;
}