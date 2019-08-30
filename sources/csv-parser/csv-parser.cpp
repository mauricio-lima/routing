
#include "csv-parser.h"

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


CSVParser::CSVParser(std::string input)
{
	this->input = input;
}


void CSVParser::parse(void)
{
	std::istringstream  input(this->input);
	std::string			token;

	const char* ws = " \t";
	while (input)
	{
		if (!std::getline(input, token, ',')) break;

		size_t pos = token.find_first_not_of(ws);
		if (std::string::npos != pos)
		{
			token = token.substr(pos);
		}
		token.erase(token.find_last_not_of(ws) + 1);
		token.erase(std::remove(token.begin(), token.end(), '\"'), token.end());

		record.push_back(token);
	}
}


std::string CSVParser::operator [](int index) const 
{
	return record[index];
}

