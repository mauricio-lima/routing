
#include <iostream>
#include <string>
#include <fstream>

#include "configuration.h"

#include "router-database.h"
#include "csv-database.h"


using namespace std;


TConfiguration Configuration;


void PrefixHelp()
{
	cout << "Router System - Digitalk Software" << endl;
	cout << endl;
}


void CommandHelp()
{
	PrefixHelp();
	cout << "database - Comandos relacionados ao armazenamento dos dados de roteamento" << endl;
	cout << "track    - Avalia rotas baseada nos parâmetros"                            << endl;
}


void CommandDatabaseOptionHelp()
{
	PrefixHelp();
	cout << "O comando 'database' deve ter op��es entre as seguintes:" << endl;
	cout << endl;
	cout << "--list"   << endl;
	cout << " -l     " << "Lista o banco de dados na forma como est� armazenado" << endl;
}


void CommandDatabaseOptionList()
{
	ifstream	database(Configuration["source"]);
	string		line;
	
	while (getline(database, line))
	{
		cout << line << endl;
	}
}


void CommandDatabaseOptionSource(string source)
{
	
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

		if ((option == "--source") || (option == "-s"))
		{
			string source = argv[++index];
			CommandDatabaseOptionSource(source);
		}

		index++;
		if (index >= argc) break;
	}

	return 0;
}


void CommandTrackOptionHelp()
{
	PrefixHelp();
	cout << "O comando 'track' deve ter opções entre as seguintes:"      << endl;
	cout << endl;
	cout << "--show"   << endl;
	cout << " -s     " << "Mostra a estrutura de rastreamento das rotas" << endl;
}


void CommandTrackOptionShow()
{
	TCSVDatabase*	database;

	database = new TCSVDatabase(Configuration["source"]);
}


int CommandTrack(int argc, char* argv[])
{
	string	option;
	int		index;

	if (argc < 3)
	{
		CommandTrackOptionHelp();
		return 1;
	}

	index = 2;
	while (true)
	{
		option = argv[index];

		if ((option == "--help") || (option == "-h"))
		{
			CommandTrackOptionHelp();
			return 0;
		}

		if ((option == "--show") || (option == "-s"))
		{
			CommandTrackOptionShow();
			return 0;
		}
	}
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

	cout << "O comando '" << option << "' n�o � um comando v�lido. Use " << endl;
	cout << endl;
	cout << "   router --help" << endl;
	cout << endl;
	cout << "para exibir os comandos dispon�veis." << endl;
	cout << endl;
	cout << endl;

	return 1;
}


int main(int argc, char* argv[])
{
	return Commands(argc, argv);
}

