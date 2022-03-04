#include <string>

#include <dds/core/ddscore.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>

#include "DDSInterface.h"
#include "DDSPublisher.h"

void run_using_dds_interface() {
    try {
        DDSInterface dds_interface = DDSInterface::CreateDDSInterface(0, 0);
        DDSPublisher dds_publisher = DDSPublisher::CreateDDSPublisher(dds_interface, "test_message.xml", "topic_HelloWorld", "HelloWorld", "topics_lib");

        dds::core::xtypes::DynamicData message = dds_publisher.create_message();
        message.value<std::string>("msg", "This is a message");

        while (true) {
            printf("Sending message\n");
            std::cout << message << std::endl;
            dds_publisher.publish(message);
            std::cout << "Sleeping for 4s.." << std::endl;
            rti::util::sleep(dds::core::Duration(4));
        }
    }
    catch (DDSException& e) {
        std::cout << e.what() << std::endl;
    }
}

void run_using_core_libs() {
  using namespace dds::core::xtypes;

    dds::core::QosProvider qos_provider("test_message.xml");
    const DynamicType& mytype = qos_provider->type("topics_lib", "HelloWorld");

    dds::domain::DomainParticipant participant(0);
    dds::topic::Topic<DynamicData> topic(participant, "Example HelloWorld", mytype);
    dds::pub::DataWriter<DynamicData> writer(dds::pub::Publisher(participant), topic);

    DynamicData sample(mytype);
    for (unsigned int count = 0; count < 10;
        count++) {

        sample.value<std::string>("msg", "count: " + std::to_string(count)); // my_string = hello
        std::cout << sample << std::endl;
        writer.write(sample);

        rti::util::sleep(dds::core::Duration(4));
    }
}

int main(int argc, char **argv) {
    //run_using_core_libs();

    try {
        run_using_dds_interface();
    }
    catch (DDSException e) {
        std::cout << e.what() << std::endl;
    }

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("test_message.xml");
    auto dds_node = doc.select_nodes("dds").first().node();

    for (auto child : dds_node.select_nodes("type_library")) {
       std::cout << "Type Library: " << child.node().attribute("name").value() << std::endl;
    }

    std::cout << "Load result: " << result.description() << ", dds: " << doc.child("dds").value() << std::endl;

}
