#include "DDSInterface.h"


DDSInterface DDSInterface::CreateDDSInterface() {
	return CreateDDSInterface(0, 0);
}

DDSInterface DDSInterface::CreateDDSInterface(int domain_id) {
	return CreateDDSInterface(domain_id, 0);
}

DDSInterface DDSInterface::CreateDDSInterface(int domain_id, int verbosityLevel) {
	dds::domain::DomainParticipant&& participant = dds::domain::DomainParticipant(domain_id);
	
	return DDSInterface(domain_id, verbosityLevel, std::move(participant));
}

dds::domain::DomainParticipant& DDSInterface::get_participant()
{
	return this->participant;
}

DDSInterface::DDSInterface(int domain_id, int verbosityLevel, dds::domain::DomainParticipant&& participant)
: 
	domain_id(domain_id),
	verbosity(static_cast<rti::config::Verbosity::inner_enum>(verbosityLevel)) ,
	participant((dds::domain::DomainParticipant&&)participant)
{
	//// Sets Connext verbosity to help debugging
	rti::config::Logger::instance().verbosity(this->verbosity);
}

DDSInterface::~DDSInterface()
{
	// Releases the memory used by the participant factory
	this->participant.close();
	dds::domain::DomainParticipant::finalize_participant_factory();
}
