#include "configuration.h"

TConfiguration::TConfiguration()
{
	// Read configuration from file not implemented yet

	values["source"] = "database.csv";
}


std::string TConfiguration::operator [](std::string key)
{
	return this->values[key];
}


/*
std::string Configuration::operator [](std::string key) const
{
	//return values[key]
}
*/