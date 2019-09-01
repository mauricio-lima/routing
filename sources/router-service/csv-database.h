#pragma once

#include "router-database.h"

#include <string>


class TCSVDatabase : TRouterDatabase
{
	private:
		std::string filename;

	public:
		TCSVDatabase(std::string filename);

};