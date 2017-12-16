#include <algorithm>
#include <list>
#include <vector>

#include "Action.h"
#include "State.h"

using namespace std;

bool isRodContainLargerDisk(Disk rightRodDisk, Disk diskToTestAgainst)
{
	if (rightRodDisk == SMALL)
		return (diskToTestAgainst == MEDIUM || diskToTestAgainst == LARGE);
	else if (rightRodDisk == MEDIUM)
		return (diskToTestAgainst == LARGE);

	return false;
}

int getHeuristicValue(State *newState)
{
	int h1 = newState->getLeftRod().size() + newState->getMiddleRod().size();
	int h2 = 0;
	
	vector<Disk> rightRod = newState->getRightRod();
	vector<Disk> middleRod = newState->getMiddleRod();
	vector<Disk> leftRod = newState->getLeftRod();

	vector<Disk>::iterator rightRodIt;
	vector<Disk>::iterator middleRodIt;
	vector<Disk>::iterator leftRodIt;

	for (rightRodIt = rightRod.begin(); rightRodIt != rightRod.end(); rightRodIt++)
	{
		for (middleRodIt = middleRod.begin(); middleRodIt != middleRod.end(); middleRodIt++)
			if (isRodContainLargerDisk(*rightRodIt, *middleRodIt))
			{
				h2++;
				break;
			}

		for (leftRodIt = leftRod.begin(); leftRodIt != leftRod.end(); leftRodIt++)
			if (isRodContainLargerDisk(*rightRodIt, *leftRodIt))
			{
				h2++;
				break;
			}
	}

	return h1 + (2*h2);
}

inline Node *getChildNode(Node *parentNode, State *newState)
{
	int g = parentNode->getActualCost();
	int h = getHeuristicValue(newState);

	Node *node = new Node();
	node->setState(newState);
	node->setParentNode(parentNode);
	node->setActualCost(g);
	node->setHeuristicCost(h);

	return node;
}

inline State *getNewState(Node *parentNode, Disk diskToMove, Rod fromRod, Rod toRod)
{
	/* Set new rod based on current state to new state based on the rod that is going to remove a disk. */
	vector<Disk> rodDiskWillBeRemovedFrom;

	if (fromRod == LEFT)
		rodDiskWillBeRemovedFrom = parentNode->getState()->getLeftRod();
	else if (fromRod == MIDDLE)
		rodDiskWillBeRemovedFrom = parentNode->getState()->getMiddleRod();
	else if (fromRod == RIGHT)
		rodDiskWillBeRemovedFrom = parentNode->getState()->getRightRod();

	/* Remove disk from rod where the disk is moving from */
	for (unsigned i = 0; i < rodDiskWillBeRemovedFrom.size(); i++) {
		if (rodDiskWillBeRemovedFrom.at(i) == diskToMove)
		{
			rodDiskWillBeRemovedFrom.erase(rodDiskWillBeRemovedFrom.begin() + i);
			i--;
		}
	}

	/* Set new rod based on current state to new state based on the rod that is going to add a disk. */
	vector<Disk> rodDiskWillMoveTo;

	if (toRod == LEFT)
		rodDiskWillMoveTo = parentNode->getState()->getLeftRod();
	else if (toRod == MIDDLE)
		rodDiskWillMoveTo = parentNode->getState()->getMiddleRod();
	else if (toRod == RIGHT)
		rodDiskWillMoveTo = parentNode->getState()->getRightRod();

	/* Add disk to rod where the disk is moving to */
	rodDiskWillMoveTo.push_back(diskToMove);

	/* Set new state based on updates on rods and disk locations on previous state done above. */
	State *newState = new State();

	/* Add rod where disk was removed from. */
	if (fromRod == LEFT)
		newState->setLeftRod(rodDiskWillBeRemovedFrom);
	else if (fromRod == MIDDLE)
		newState->setMiddleRod(rodDiskWillBeRemovedFrom);
	else if (fromRod == RIGHT)
		newState->setRightRod(rodDiskWillBeRemovedFrom);

	/* Add rod where disk was moved to. */
	if (toRod == LEFT)
		newState->setLeftRod(rodDiskWillMoveTo);
	else if (toRod == MIDDLE)
		newState->setMiddleRod(rodDiskWillMoveTo);
	else if (toRod == RIGHT)
		newState->setRightRod(rodDiskWillMoveTo);

	/* Set one rod to new state based on the rod that is not being changed. */
	if (fromRod != LEFT && toRod != LEFT)
		newState->setLeftRod(parentNode->getState()->getLeftRod());
	else if (fromRod != MIDDLE && toRod != MIDDLE)
		newState->setMiddleRod(parentNode->getState()->getMiddleRod());
	else if (fromRod != RIGHT && toRod != RIGHT)
		newState->setRightRod(parentNode->getState()->getRightRod());

	return newState;
}

inline Rod getDiskRodLocation(Disk disk, State *currentState)
{
	vector<Disk> leftRod = currentState->getLeftRod();
	vector<Disk> middleRod = currentState->getMiddleRod();
	vector<Disk> rightRod = currentState->getRightRod();

	vector<Disk>::iterator it;

	for (it = leftRod.begin(); it != leftRod.end(); it++)
		if ((*it) == disk)
			return LEFT;

	for (it = middleRod.begin(); it != middleRod.end(); it++)
		if ((*it) == disk)
			return MIDDLE;

	for (it = rightRod.begin(); it != rightRod.end(); it++)
		if ((*it) == disk)
			return RIGHT;

	return NONE;
}

inline bool isValidForDiskToMoveToRod(State *state, Disk diskToMove, Rod rodDiskWillMoveTo)
{
	/* Since the SMALL disk is the smallest disk, it can move any where */
	if (diskToMove == SMALL)
		return true;

	vector<Disk> rodToCheck;

	if (rodDiskWillMoveTo == LEFT)
		rodToCheck = state->getLeftRod();
	else if (rodDiskWillMoveTo == MIDDLE)
		rodToCheck = state->getMiddleRod();
	else if (rodDiskWillMoveTo == RIGHT)
		rodToCheck = state->getRightRod();

	/* Disks can be placed in a rod with no disks currently placed in it. */
	if (rodToCheck.size() == 0)
		return true;

	/* The top disk on a rod is only needed to compare whether another disk can move to that rod. */
	if (diskToMove == MEDIUM)
		return !(rodToCheck.at(rodToCheck.size() - 1) == SMALL);

	if (diskToMove == LARGE)
		return !(rodToCheck.at(rodToCheck.size() - 1) == MEDIUM || rodToCheck.at(rodToCheck.size() - 1) == SMALL);

	return true;
}

inline Node *generateNode(Node *parentNode, Disk diskToMove, Rod rodDiskWillMoveTo)
{
	Rod diskLocation = getDiskRodLocation(diskToMove, parentNode->getState());

	if (diskLocation == rodDiskWillMoveTo || diskLocation == NONE)
		return NULL;

	if (!isValidForDiskToMoveToRod(parentNode->getState(), diskToMove, rodDiskWillMoveTo))
		return NULL;

	State* newState = getNewState(parentNode, diskToMove, diskLocation, rodDiskWillMoveTo);

	return getChildNode(parentNode, newState);
}

Node *SmallGoMiddleRod::doAction(Node *parentNode)
{
	return generateNode(parentNode, SMALL, MIDDLE);
}

Node *SmallGoRightRod::doAction(Node *parentNode)
{
	return generateNode(parentNode, SMALL, RIGHT);
}

Node *SmallGoLeftRod::doAction(Node *parentNode)
{
	return generateNode(parentNode, SMALL, LEFT);
}

Node *MediumGoMiddleRod::doAction(Node *parentNode)
{
	return generateNode(parentNode, MEDIUM, MIDDLE);
}

Node *MediumGoRightRod::doAction(Node *parentNode)
{
	return generateNode(parentNode, MEDIUM, RIGHT);
}

Node *MediumGoLeftRod::doAction(Node *parentNode)
{
	return generateNode(parentNode, MEDIUM, LEFT);
}

Node *LargeGoMediumRod::doAction(Node *parentNode)
{
	return generateNode(parentNode, LARGE, MIDDLE);
}

Node *LargeGoRightRod::doAction(Node * parentNode)
{
	return generateNode(parentNode, LARGE, RIGHT);
}

Node * LargeGoLeftRod::doAction(Node * parentNode)
{
	return generateNode(parentNode, LARGE, LEFT);
}

list<Action*> getActions()
{
   list<Action*> actions;

   actions.push_back(new SmallGoMiddleRod());
   actions.push_back(new SmallGoRightRod());
   actions.push_back(new SmallGoLeftRod());
   actions.push_back(new MediumGoMiddleRod());
   actions.push_back(new MediumGoRightRod());
   actions.push_back(new MediumGoLeftRod());
   actions.push_back(new LargeGoMediumRod());
   actions.push_back(new LargeGoRightRod());
   actions.push_back(new LargeGoLeftRod());

   return actions;
}
