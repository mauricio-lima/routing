
#include <iostream>
#include <string>
#include <fstream>

#include "csv-database.h"


using namespace std;





void PrefixHelp()
{
	cout << "Router System - Digitalk Software" << endl;
	cout << endl;
}


void CommandHelp()
{
	PrefixHelp();
	cout << "database - Comandos relacionados ao armazenamento dos dados de roteamento" << endl;
}


void CommandDatabaseOptionHelp()
{
	PrefixHelp();
	cout << "O comando 'database' deve ter opções entre as seguintes:" << endl;
	cout << endl;
	cout << "--list"   << endl;
	cout << " -l     " << "Lista o banco de dados na forma como está armazenado" << endl;
}


void CommandDatabaseOptionList()
{
	ifstream	database("database.csv");
	string		line;
	
	while (getline(database, line))
	{
		cout << line << endl;
	}
}


int CommandDatabase(int argc, char* argv[])
{
	string	option;
	int		index;

	if (argc < 3)
	{
		CommandDatabaseOptionHelp();
		return 1;
	}

	index = 2;
	while (true)
	{
		option = argv[index];

		if ((option == "--help") || (option == "-h"))
		{
			CommandDatabaseOptionHelp();
			return 0;
		}

		if ((option == "--list") || (option == "-l"))
		{
			CommandDatabaseOptionList();
			return 0;
		}

		index++;
		if (index >= argc) break;
	}

	return 0;
}


int Commands(int argc, char* argv[])
{
	string	option;

	if (argc < 2)
	{
		CommandHelp();
		return 0;
	}
	option = argv[1];

	if ((option == "--help") || (option == "-h"))
	{
		CommandHelp();
		return 0;
	}

	if (string(argv[1]) == "database")
	{
		return CommandDatabase(argc, argv);
	}

	cout << "O comando '" << option << "' não é um comando válido. Use " << endl;
	cout << endl;
	cout << "   router --help" << endl;
	cout << endl;
	cout << "para exibir os comandos disponíveis." << endl;
	cout << endl;
	cout << endl;

	return 1;
}


int main(int argc, char* argv[])
{
	return Commands(argc, argv);
}

