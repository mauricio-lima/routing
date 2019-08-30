
#include <string>

#include "nodes.h"


TNode& TNodes::add(std::string name)
{
	return *(new TNode(name));
}


TNode::TNode(std::string name)
{

}