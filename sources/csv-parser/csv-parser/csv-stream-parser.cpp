#include <iostream>

#include "csv-parser.h"


int main(int argc, char* argv[])
{
	CSVParser parser("abc, def  ,,  ada,  \" teste \"");

	parser.parse();
	std::cout << parser[1] << std::endl;

	return 0;
}