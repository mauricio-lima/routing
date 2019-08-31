#pragma once

#include <string>
#include <vector>

class TNode;


class TLink
{
	public:
		TLink(TNode& to, TNode& from);
};


class TLinks
{
	private:
		std::vector<TLink> links;

	public:
		void add(TNode& to, TNode& from);
};

class TNodes
{
	public:
		TNode& add(std::string name = "");
};


class TNode
{
	public:
		std::string name;

		TNode(std::string name);

	private:
		TLinks links;

};
