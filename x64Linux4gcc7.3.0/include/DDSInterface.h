#pragma once

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
//#include <dds/core/macros.hpp>

#include <iostream>
#include <csignal>
#include <dds/core/ddscore.hpp>
#include <ndds/hpp/rti/config/Logger.hpp>

class DDSInterface
{

public:
	DDSInterface(int domain_id, int verbosityLevel, dds::domain::DomainParticipant&& participant);
	~DDSInterface();

	static DDSInterface CreateDDSInterface();
	static DDSInterface CreateDDSInterface(int domain_id);
	static DDSInterface CreateDDSInterface(int domain_id, int verbosityLevel);

	dds::domain::DomainParticipant& get_participant();

private:
	const int domain_id;
	dds::domain::DomainParticipant participant;
};

//using namespace dds::core::xtypes;
//template class dds::core::TQosProvider<rti::core::QosProviderImpl>;
