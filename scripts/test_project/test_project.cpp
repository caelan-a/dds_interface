#include "test_project.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <windows.h>

void read_directory(const std::string& name)
{
    std::string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            std::cout << data.cFileName << "\n";
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}
int main(int argc, char **argv) {

    ////
    ////  The following code demonstrates basic usage of the DDS Interface wrapper library!
    ////

    //  Use DDS Interface wrapper to create a convenient xml defined message publisher
    DDSInterface dds_interface = DDSInterface::CreateDDSInterface(0, 0);
    DDSPublisher dds_publisher = DDSPublisher::CreateDDSPublisher(dds_interface, 
                                                                    "example_message.xml",  
                                                                    "example_topic", 
                                                                    "example_data_type", 
                                                                    "example_data_type_library");

    // Create message and set value
    dds::core::xtypes::DynamicData message = dds_publisher.create_message();
    message.value<std::string>("example_string_field", "This is an example message! Replace me!");

    // Send a message every 4 seconds 
    while (true) {
        printf("Sending message\n");
        std::cout << message << std::endl;
        dds_publisher.publish(message);
        std::cout << "Sleeping for 4s.." << std::endl;
        rti::util::sleep(dds::core::Duration(4));
    }
}
