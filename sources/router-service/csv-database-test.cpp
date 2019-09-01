#include "csv-database.h"

#include <iostream>


using namespace std;


#ifdef CSV_DATABASE_TEST

int main(int argc, char* argv[])
{
	if (argc < 2)
	{ 
		cout << "O primeiro argumento deve ser o nome de um arquivo CSV sem linha de titulos e com tres colunas por linha" << endl;
		return 1;
	}


	TCSVDatabase database(argv[1]);
}


#endif