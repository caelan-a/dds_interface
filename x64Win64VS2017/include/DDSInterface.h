#pragma once

#include <iostream>
#include <csignal>
#include <dds/core/ddscore.hpp>

/*
This class wraps a participant with some settings that can be used to create multiple publishers
*/
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