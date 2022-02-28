
# DDS Interface
This project allows the creation of a 'DDS Interface' static library that includes all of RTi's libraries bundled together along with a convenience class to use the XML defined messages. This facilitates much more flexible and convenient usage of DDS in future projects.

## Requirements
1. It's required for RTi DDS Connext to be installed on your device. Specifically, the header files and libraries 
  "nddscpp2z"
  "nddscz"
  "nddscorez"
2. Environment variable NDDSHOME be set correctly on system (eg NDDSHOME="C:/Program Files/rti_connext_dds-6.1.0")

## How To Build
1. Create directory for generated build files
```
mkdir build
cd build
```
2. Generate build files using CMake for specified platform (Eg PLATFORM=x64Win64VS2017)
```
cmake -DPLATFORM=<PLATFORM> ../
```
3. Build static library for DDS Interface 
`cmake --build . --config=<Debug|Release>` 

## Using Static Library in Projects
### Debug
1. To use DDSInterface in external projects, the following should be done:
* Add link library `dds_interface_debug.lib` to linker 
* Add link library directory containing `dds_interface_debug.lib` to linker
* Add the following directories to compiler to look for headers
`build/include/`
`build/include/rti_headers`
`build/include/rti_headers/ndds`
`build/include/rti_headers/ndds/hpp`
2. Add preprocessor definitions
`NDDS_DLL_VARIABLE WIN32_LEAN_AND_MEAN _DEBUG _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS`

### Release
1. To use DDSInterface in external projects, the following should be done:
* Add link library `dds_interface.lib` to linker found in `build/Debug/<PLATFORM>/dds_interface.lib
* Add link library directory containing `dds_interface.lib` to linker
* Add the following directories to compiler to look for headers
`build/include/`
`build/include/rti_headers`
`build/include/rti_headers/ndds`
`build/include/rti_headers/ndds/hpp`
2. `NDDS_DLL_VARIABLE WIN32_LEAN_AND_MEAN _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS`

### Notes
Use this CMAKE as an example for future DDS enabled projects
## Example Usage

### Using DDSInterface wrapper

```
DSInterface dds_interface = DDSInterface::CreateDDSInterface(0, 0);
DDSPublisher dds_publisher = DDSPublisher::CreateDDSPublisher(dds_interface, "message.xml", "topic_HelloWorld", "HelloWorld", "topics_lib");

////// construct message to send
dds::core::xtypes::DynamicData message = dds_publisher.create_message();
message.value<std::string>("msg", "yoyo");

while (true) {
    printf("Sending message\n");
    dds_publisher.publish(message);
    std::cout << "Sleeping for 4s.." << std::endl;
    rti::util::sleep(dds::core::Duration(4));
    std::cout << "I'm back baby" << std::endl;
}
```

### Using Native RTi Classes

```
using namespace dds::core::xtypes;

dds::core::QosProvider qos_provider("message.xml");
const DynamicType& mytype = qos_provider->type("topics_lib", "HelloWorld");

dds::domain::DomainParticipant participant(domain_id);
dds::topic::Topic<DynamicData> topic(participant, "Example HelloWorld", mytype);
dds::pub::DataWriter<DynamicData> writer(dds::pub::Publisher(participant), topic);

DynamicData sample(mytype);
for (unsigned int count = 0;
    !shutdown_requested && count < sample_count;
    count++) {

    sample.value<std::string>("msg", "count: " + std::to_string(count)); // my_string = hello

    std::cout << sample << std::endl;
    writer.write(sample);

    rti::util::sleep(dds::core::Duration(4));
}

```