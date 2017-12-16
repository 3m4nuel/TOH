#include "stdafx.h"

#include "Print.h"

#include <iostream>

/* Methods to print to screen */
inline string getItemChar(Disk item)
{
	if (item == SMALL)
		return "Small";
	if (item == MEDIUM)
		return "Medium";
	if (item == LARGE)
		return "Large";

	return "";
}

inline void printItems(Node *node)
{
	vector<Disk> leftItems;
	vector<Disk> middleItems;
	vector<Disk> rightItems;
	vector<Disk>::iterator it;

	cout << "[";
	leftItems = node->getState()->getLeftRod();
	for (it = leftItems.begin(); it != leftItems.end(); it++)
	{
		cout << getItemChar(*it).c_str();
	}

	cout << "|";

	middleItems = node->getState()->getMiddleRod();
	for (it = middleItems.begin(); it != middleItems.end(); it++)
	{
		cout << getItemChar(*it).c_str();
	}

	cout << "|";

	rightItems = node->getState()->getRightRod();
	for (it = rightItems.begin(); it != rightItems.end(); it++)
	{
		cout << getItemChar(*it).c_str();
	}
	cout << "] ";
	cout << "h=" << node->getHeuristicCost() << " ";
	cout << "g=" << node->getActualCost() << " ";
	cout << "f=" << node->getPathCost() << " ";
}

void printFrontier(priority_queue<Node*, vector<Node*>, CompareNodes> frontier)
{
	cout << "Fontier nodes are: ";

	priority_queue<Node*, vector<Node*>, CompareNodes> copiedFrontier = frontier;

	while (!copiedFrontier.empty())
	{
		printItems(copiedFrontier.top());
		copiedFrontier.pop();
	}
	cout << "\n";
}

void printExpand(Node *node)
{
	cout << "Expand: ";
	printItems(node);
	cout << "\n";
}

void printGenerated(Node *node, const char *regenerated, Node *expandedNode)
{
	const char *updatedF = node->getPathCost() != expandedNode->getPathCost() ? "Yes" : "No";

	cout << "Generated: \n";
	cout << "\tState and Value is ";
	printItems(node);
	cout << "\n";
	cout << "\tRegenerated is ";
	cout << "\t" << regenerated;
	cout << "\n";
	cout << "\tUpdated f?";
	cout << "\t" << updatedF;
	cout << "\n";
}
