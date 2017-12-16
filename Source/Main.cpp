/* Final Project, Puzzle System: A* on Tower of Hanoi
 * Author: Emmanuel A. Castillo
 * Description:
 * An A* algorithm is implemented against the Tower of Hanoi problem.
 * With the provided initial state, nodes are expanded and other nodes
 * are generated until the goal state is reached. Valid states
 * are those where the disks are stacked up with the larger disk
 * on the bottom and smaller disk towards the top. Only one
 * disk can be moved at a time.
 *
 */
#include "stdafx.h"

#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

#include "Action.h"
#include "Checks.h"
#include "Node.h"
#include "Print.h"
#include "State.h"
#include "Test.h"

using namespace std;

/* Goal state and Actions */
State *goalState = getGoalState();
list<Action*> actions = getActions();

int main(int argc, char *argv[])
{
	/* Program runs with tests if "TEST" argument is specified. This    *
	 * does an iteration of different initial states against the program */
	bool runTest = false;

	if (argc == 2)
	{
		string arg(argv[1]);
		if (arg == "TEST")
			runTest = true;
	}

	vector<Node*> initialStates;

	if (runTest)
		initialStates = getInitialNodes();
	else
		initialStates.push_back(getInitialNode());

	for (unsigned int index = 0; index < initialStates.size(); index++)
	{
		if (runTest)
			cout << "TEST " << (index + 1) << " RUNNING....\n\n";

		/* Frontier is initialize to a priority queue that puts the *
		 * node with the lowest path cost on top of the queue.      */
		priority_queue<Node*, vector<Node*>, CompareNodes> frontier;
		frontier.push(initialStates.at(index));

		/* Explored states are kept track to determine whether they *
		* should be added to the frontier.                         */
		vector<State*> exploredStates;

		/* Frontier is loop through searching for the goal state or *
		* until all nodes are searched through on the frontier.    */
		do
		{
			printFrontier(frontier);

			if (frontier.size() <= 0)
			{
				cout << "No Goal Found.\n\n";
				break;
			}

			/* The node with the lowest cost is expanded its children *
			* is added to the frontier if it is a valid state        */
			Node *expandedFrontierNode = frontier.top();

			printExpand(expandedFrontierNode);

			frontier.pop();
			exploredStates.push_back(expandedFrontierNode->getState());

			if (isEqual(expandedFrontierNode->getState(), goalState))
			{
				cout << "Goal Found.\n\n";
				break;
			}
			else
			{
				Node *possibleChildNode;
				list<Action*>::iterator it;
				/* As long as the goal is found, the expanded node's     *
				* children are added to the frontier based on the       *
				* possible actions that can occur on the currents state */
				for (it = actions.begin(); it != actions.end(); it++)
				{
					possibleChildNode = (*it)->doAction(expandedFrontierNode);
					/* If a null pointer is returned, that means the state   *
					* transition from the action is not a valid state       */
					if (possibleChildNode == NULL)
					{
						continue;
					}
					else
					{
						/* Children nodes are added to the frontier if it has not been explored yet and  *
						* it is not in the frontier                                                     */
						if (!isStateExistInVector(exploredStates, possibleChildNode->getState()) &&
							!isStateExistInQueue(frontier, possibleChildNode->getState()))
						{
							printGenerated(possibleChildNode, "No", expandedFrontierNode);
							frontier.push(possibleChildNode);
						}
						/* Children node is swapped if its state exist in the frontier already and *
						* it has a better cost than the one in the frontier                       */
						else if (isStateExistInQueue(frontier, possibleChildNode->getState()))
						{
							if (isBetterPathCostNode(frontier, possibleChildNode))
							{
								printGenerated(possibleChildNode, "Yes", expandedFrontierNode);
								swapNode(frontier, possibleChildNode);
							}
						}
					}
				}
			}
		} while (true);
	}
}
