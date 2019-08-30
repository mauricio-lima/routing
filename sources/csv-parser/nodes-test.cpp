#include <iostream>

#include "nodes.h"

using namespace std;


#ifdef NODES_TEST

int main(int argc, char* argv[])
{
	TNodes nodes;

	
	TNode alfa = nodes.add("abc");
	TNode beta = nodes.add("def");

	return 0;
}

#endif