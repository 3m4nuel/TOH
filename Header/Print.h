/* Description:
 * This file provides methods to print
 * information onto the console.
 *
 */

#ifndef PRINT_H
#define PRINT_H

#include "Node.h"
#include <queue>
#include <vector>

#include "State.h"
#include "Node.h"
#include "Action.h"
#include "Checks.h"

using namespace std;

/* Methods to print to screen */
string getItemChar(Disk item);

void printItems(Node *node);

void printFrontier(priority_queue<Node*, vector<Node*>, CompareNodes> frontier);

void printExpand(Node *node);

void printGenerated(Node *node, const char *regenerated, Node *expandedNode);

#endif