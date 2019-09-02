
#include <iostream>

#include "configuration.h"


using namespace std;


#ifdef CONFIGURATION_TEST

int main(int argc, char* argv[])
{
	TConfiguration Configuration;

	cout << "source : " << Configuration["source"] << endl;
}

#endif
