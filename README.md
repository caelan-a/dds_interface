
# DDS Interface
This project provides tools to make creating projects using RTi's ConnextDDS as easy as possible.

## Requirements
1.  Minimum compiler requirements:
    * On Windows, one must have MSVC installed with a minimum version of 2017.\
      Download [Visual Studio 17 2022 (C++)](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&passive=true&tailored=cplus&cid=2037#cplusplus)
    * On Linux, one must have GCC installed with a minimum version of 7.3.0
2.  [CMake 3.17+](https://cmake.org/download/)
## 1 | DDS Interface Wrapper
The first use of this project is to build a static library that wraps a subset of RTi's ConnextDDS sdk. 
This has the following benefits:
* Provide functionality to make use of DynamicData (xml datatypes) safer and easier
* Abstract away as much boiler plate as possible

The project allows cross-compilation of the static library for linking on windows or linux machines.
This process is demonstrated in the `/scripts` directory by `build_static_lib.bat` on windows and `build_static_lib.sh` on linux (coming soon)

### How To Use
1. Run automatic script
```
./scripts/build_static_lib.bat
```
2. Find output at `build/out/lib`

## 2 | DDS Enabled Project Generator
This second use is to streamline the generation of projects that need to use DDS.
This project allows generating a new project with a completely configured CMakeLists.txt to build against RTi DDS core libs and a precompiled DDS Interface wrapper. It makes use of modular cmake code to avoid interfering with project development or integration with legacy code.

The generated project will support cross compilation on supported platforms.
This process is demonstrated in the `/scripts` directory by `create_project_with_dds.bat` on windows and `create_project_with_dds.sh` on linux (coming soon)

### How To Use
1. Run the following tool. The project will be created in the current directory
```
./scripts/create_project_with_dds.bat <project_name>
```

## Dependencies
For all projects that link against DDS (both in this repo and generated ones) CMake will attempt to download the required dependencies remotely. These resources (libs and headers) are hosted in branches of this repo for portability and centralisation. 
The resources include:
* Full set of RTi ConnextDDS headers
* Minimal set of RTi core libs
* Precompiled DDS Interface wrapper libs and headers

The libs are built for specific RTi platforms which are currently limited to:
* x64Win64VS2017
* x64Linux4gcc7.3.0

The repo tools will autodetect valid RTi platforms to use and alert the user if none are available. 
To extend the platforms available and update precompiled libs that all tools will use, please see `cmake/dependency_downloader.cmake` for how and what to update. Additionally, if this git is being migrated, `cmake/dependency_downloader.cmake` will need to be updated with new commit tags to find said resources.
## Example Project
### DynamicTypes
An example project is included which demonstrates the CMakeLists.txt file making use of a modular CMake script to link against DDS dependencies. This project demonstrates the use of DynamicData objects in ConnextDDS which allow sending xml defined messages over the network. 

Windows
```
cd examples/dynamic_types
./build_example.bat
./out/<config>/DynamicTypes.exe

```
Linux
```
cd examples/dynamic_types
./build_example.sh
./out/<config>/DynamicTypes
```

## Example API Usage
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