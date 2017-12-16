/* Description:
 * This file contains the base class and implementation
 * of Actions that can occur on states within
 * the Tower of Hanoi problem.
 *
 */

#ifndef ACTION_H
#define ACTION_H

#include "Node.h"
#include <list>

int getHeuristicValue(State *newState);

class Action
{
public:
   virtual Node *doAction(Node *parentNode) = 0;
};

class SmallGoMiddleRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class SmallGoRightRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class SmallGoLeftRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class MediumGoMiddleRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class MediumGoRightRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class MediumGoLeftRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class LargeGoMediumRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class LargeGoRightRod : public Action
{
public:
   Node *doAction(Node *parentNode);
};

class LargeGoLeftRod : public Action
{
public:
	Node *doAction(Node *parentNode);
};

list<Action *> getActions();

#endif