#pragma once

#include <map>
#include <string>


class TConfiguration
{
	private:
		std::map<std::string, std::string> values;

	public:
		TConfiguration();

		std::string operator [](std::string);
};

