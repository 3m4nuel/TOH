#include <list>

#include "Action.h"
#include "Node.h"
#include "State.h"

/* List of test to run against. */
inline list<State*> getTestInitialStates()
{
	list<State*> states;

	vector<Disk> initialLeftRod1;
	initialLeftRod1.push_back(LARGE);
	initialLeftRod1.push_back(MEDIUM);
	initialLeftRod1.push_back(SMALL);
	vector<Disk> initialMiddleRod1;
	vector<Disk> initialRightRod1;

	State *state1 = new State();
	state1->setLeftRod(initialLeftRod1);
	state1->setMiddleRod(initialMiddleRod1);
	state1->setRightRod(initialRightRod1);

	vector<Disk> initialLeftRod2;
	vector<Disk> initialMiddleRod2;
	initialMiddleRod2.push_back(LARGE);
	initialMiddleRod2.push_back(MEDIUM);
	initialMiddleRod2.push_back(SMALL);
	vector<Disk> initialRightRod2;

	State *state2 = new State();
	state2->setLeftRod(initialLeftRod2);
	state2->setMiddleRod(initialMiddleRod2);
	state2->setRightRod(initialRightRod2);

	vector<Disk> initialLeftRod3;
	vector<Disk> initialMiddleRod3;
	vector<Disk> initialRightRod3;
	initialRightRod3.push_back(LARGE);
	initialRightRod3.push_back(MEDIUM);
	initialRightRod3.push_back(SMALL);

	State *state3 = new State();
	state3->setLeftRod(initialLeftRod3);
	state3->setMiddleRod(initialMiddleRod3);
	state3->setRightRod(initialRightRod3);

	vector<Disk> initialLeftRod4;
	initialLeftRod4.push_back(SMALL);
	vector<Disk> initialMiddleRod4;
	vector<Disk> initialRightRod4;
	initialRightRod4.push_back(LARGE);
	initialRightRod4.push_back(MEDIUM);

	State *state4 = new State();
	state4->setLeftRod(initialLeftRod4);
	state4->setMiddleRod(initialMiddleRod4);
	state4->setRightRod(initialRightRod4);

	vector<Disk> initialLeftRod5;
	initialLeftRod5.push_back(SMALL);
	vector<Disk> initialMiddleRod5;
	initialMiddleRod5.push_back(LARGE);
	initialMiddleRod5.push_back(MEDIUM);
	vector<Disk> initialRightRod5;

	State *state5 = new State();
	state5->setLeftRod(initialLeftRod5);
	state5->setMiddleRod(initialMiddleRod5);
	state5->setRightRod(initialRightRod5);

	vector<Disk> initialLeftRod6;
	initialLeftRod6.push_back(SMALL);
	vector<Disk> initialMiddleRod6;
	initialMiddleRod6.push_back(MEDIUM);
	vector<Disk> initialRightRod6;
	initialRightRod6.push_back(LARGE);

	State *state6 = new State();
	state6->setLeftRod(initialLeftRod6);
	state6->setMiddleRod(initialMiddleRod6);
	state6->setRightRod(initialRightRod6);

	vector<Disk> initialLeftRod7;
	initialLeftRod7.push_back(MEDIUM);
	vector<Disk> initialMiddleRod7;
	vector<Disk> initialRightRod7;
	initialRightRod7.push_back(LARGE);
	initialRightRod7.push_back(SMALL);

	State *state7 = new State();
	state7->setLeftRod(initialLeftRod7);
	state7->setMiddleRod(initialMiddleRod7);
	state7->setRightRod(initialRightRod7);

	vector<Disk> initialLeftRod8;
	initialLeftRod8.push_back(MEDIUM);
	vector<Disk> initialMiddleRod8;
	initialMiddleRod8.push_back(LARGE);
	initialMiddleRod8.push_back(SMALL);
	vector<Disk> initialRightRod8;

	State *state8 = new State();
	state8->setLeftRod(initialLeftRod8);
	state8->setMiddleRod(initialMiddleRod8);
	state8->setRightRod(initialRightRod8);

	vector<Disk> initialLeftRod9;
	initialLeftRod9.push_back(MEDIUM);
	vector<Disk> initialMiddleRod9;
	initialMiddleRod9.push_back(SMALL);
	vector<Disk> initialRightRod9;
	initialRightRod9.push_back(LARGE);

	State *state9 = new State();
	state9->setLeftRod(initialLeftRod9);
	state9->setMiddleRod(initialMiddleRod9);
	state9->setRightRod(initialRightRod9);

	vector<Disk> initialLeftRod10;
	initialLeftRod10.push_back(LARGE);
	vector<Disk> initialMiddleRod10;
	vector<Disk> initialRightRod10;
	initialRightRod10.push_back(MEDIUM);
	initialRightRod10.push_back(SMALL);

	State *state10 = new State();
	state10->setLeftRod(initialLeftRod10);
	state10->setMiddleRod(initialMiddleRod10);
	state10->setRightRod(initialRightRod10);

	vector<Disk> initialLeftRod11;
	initialLeftRod11.push_back(LARGE);
	vector<Disk> initialMiddleRod11;
	initialMiddleRod11.push_back(MEDIUM);
	initialMiddleRod11.push_back(SMALL);
	vector<Disk> initialRightRod11;

	State *state11 = new State();
	state11->setLeftRod(initialLeftRod11);
	state11->setMiddleRod(initialMiddleRod11);
	state11->setRightRod(initialRightRod11);

	vector<Disk> initialLeftRod12;
	initialLeftRod12.push_back(LARGE);
	vector<Disk> initialMiddleRod12;
	initialMiddleRod12.push_back(SMALL);
	vector<Disk> initialRightRod12;
	initialRightRod12.push_back(MEDIUM);

	State *state12 = new State();
	state12->setLeftRod(initialLeftRod12);
	state12->setMiddleRod(initialMiddleRod12);
	state12->setRightRod(initialRightRod12);

	vector<Disk> initialLeftRod13;
	initialLeftRod13.push_back(LARGE);
	vector<Disk> initialMiddleRod13;
	initialMiddleRod13.push_back(MEDIUM);
	vector<Disk> initialRightRod13;
	initialRightRod13.push_back(SMALL);

	State *state13 = new State();
	state13->setLeftRod(initialLeftRod13);
	state13->setMiddleRod(initialMiddleRod13);
	state13->setRightRod(initialRightRod13);

	states.push_back(state1);
	states.push_back(state2);
	states.push_back(state3);
	states.push_back(state4);
	states.push_back(state5);
	states.push_back(state6);
	states.push_back(state7);
	states.push_back(state8);
	states.push_back(state9);
	states.push_back(state10);
	states.push_back(state11);
	states.push_back(state12);
	states.push_back(state13);

	return states;
}

vector<Node*> getInitialNodes()
{
	vector<Node *> initialNodes;
	list<State*> initialStates = getTestInitialStates();
	
	list<State*>::iterator it;
	for (it = initialStates.begin(); it != initialStates.end(); it++)
	{
		Node *initialNode = new Node();
		initialNode->setState(*it);
		initialNode->setActualCost(0);
		initialNode->setHeuristicCost(getHeuristicValue(*it));
		initialNodes.push_back(initialNode);
	}

	return initialNodes;
}
