/**
 * @author Caelan Anderson
 * @email caelan.andsn@gmail.com
 * @create date 2022-03-02 16:37:58
 * @modify date 2022-03-02 16:37:58
 * @desc Example demonstrating usage of DDS Dynamic Data and DDS Interface Wrapper
 */

#include "load_dynamic_type.hpp"

void run_using_dds_interface() {
    DDSInterface dds_interface = DDSInterface::CreateDDSInterface(0, 0);
    DDSPublisher dds_publisher = DDSPublisher::CreateDDSPublisher(dds_interface, "message.xml", "topic_HelloWorld", "HelloWorld", "topics_lib");

    ////// construct message to send
    dds::core::xtypes::DynamicData message = dds_publisher.create_message();
    message.value<std::string>("msg", "yoyo");

    while (true) {
        printf("Sending message\n");
        std::cout << message << std::endl;
        dds_publisher.publish(message);
        std::cout << "Sleeping for 4s.." << std::endl;
        rti::util::sleep(dds::core::Duration(4));
    }
}

void run_using_core_libs() {
  using namespace dds::core::xtypes;

    dds::core::QosProvider qos_provider("message.xml");
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
    run_using_core_libs();
    // run_using_dds_interface();
}
