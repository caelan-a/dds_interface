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
        DDSMessage message = dds_publisher.create_message();
        message.set_string("msg", "hello");
        message.set_dynamic_value("short_member", 1);

        while (true) {
            printf("Sending the following message\n");
            message.print();
           
            dds_publisher.publish(message);

            std::cout << "Sleeping for 4s.." << std::endl;
            rti::util::sleep(dds::core::Duration(4));
        }
    }
    catch (DDSException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (dds::core::Error e) {
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
}
