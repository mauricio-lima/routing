#include <iostream>

#include "csv-parser.h"


using namespace std;


#ifdef CSV_PARSER_TEST

int main(int argc, char* argv[])
{
	CSVParser parser("abc, def  ,,  ada,  \" teste \"");
	parser.parse();

	if (parser[0] != "abc")	
	{
		cerr << "First token expected is <abc> but <"  << parser[0] << ">" << endl;
		return 1;
	}

	if (parser[1] != "def")	return 1;
	{
		cerr << "Second token expected is <def> but <" << parser[1] << ">" << endl;
		return 1;
	}

	return 0;
}

#endif