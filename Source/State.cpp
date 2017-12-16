#include "stdafx.h"

#include <algorithm>
#include <queue>
#include <vector>

#include "State.h"

using namespace std;

bool isEqual(State *lState, State *rState)
{
   vector<Disk> lVectorLeftRod = lState->getLeftRod();
   vector<Disk> rVectorLeftRod = rState->getLeftRod();

   sort(lVectorLeftRod.begin(), lVectorLeftRod.end());
   sort(rVectorLeftRod.begin(), rVectorLeftRod.end());

   if (lVectorLeftRod != rVectorLeftRod)
      return false;

   vector<Disk> lVectorMiddleRod = lState->getMiddleRod();
   vector<Disk> rVectorMiddleRod = rState->getMiddleRod();

   sort(lVectorMiddleRod.begin(), lVectorMiddleRod.end());
   sort(rVectorMiddleRod.begin(), rVectorMiddleRod.end());

   if (lVectorLeftRod != rVectorLeftRod)
	   return false;

   vector<Disk> lVectorRightRod = lState->getRightRod();
   vector<Disk> rVectorRightRod = rState->getRightRod();

   sort(lVectorRightRod.begin(), lVectorRightRod.end());
   sort(rVectorRightRod.begin(), rVectorRightRod.end());

   return lVectorRightRod == rVectorRightRod;
}

State *getInitialState()
{
   vector<Disk> initialLeftRod;
   initialLeftRod.push_back(LARGE);
   initialLeftRod.push_back(MEDIUM);
   initialLeftRod.push_back(SMALL);

   vector<Disk> initialMiddleRod;
   vector<Disk> initialRightRod;

   State *state = new State();
   state->setLeftRod(initialLeftRod);
   state->setMiddleRod(initialMiddleRod);
   state->setRightRod(initialRightRod);

   return state;
}

State *getGoalState()
{
   vector<Disk> goalLeftRod;

   vector<Disk> goalMiddleRod;

   vector<Disk> goalRightRod;
   goalRightRod.push_back(LARGE);
   goalRightRod.push_back(MEDIUM);
   goalRightRod.push_back(SMALL);

   State *state = new State();
   state->setLeftRod(goalLeftRod);
   state->setMiddleRod(goalMiddleRod);
   state->setRightRod(goalRightRod);

   return state;
}

vector<Disk> State::getLeftRod()
{
   return State::leftRod;
}

void State::setLeftRod(vector<Disk> items)
{
   State::leftRod = items;
}

vector<Disk> State::getMiddleRod()
{
	return State::middleRod;
}

void State::setMiddleRod(vector<Disk> items)
{
	State::middleRod = items;
}

vector<Disk> State::getRightRod()
{
   return State::rightRod;
}

void State::setRightRod(vector<Disk> items)
{
   State::rightRod = items;
}
