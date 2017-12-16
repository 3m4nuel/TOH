/* Description:
 * This file contains the data model
 * for the State as well as the Items
 * that can be contains in the States.
 *
 */

#ifndef STATE_H
#define STATE_H

#include <vector>
#include <queue>

using namespace std;

enum Disk { SMALL, MEDIUM, LARGE };

enum Rod { LEFT, MIDDLE, RIGHT, NONE };

class State
{
private:
   vector<Disk> leftRod;
   vector<Disk> middleRod;
   vector<Disk> rightRod;
public:
   vector<Disk> getLeftRod();
   void setLeftRod(vector<Disk> items);
   vector<Disk> getMiddleRod();
   void setMiddleRod(vector<Disk> items);
   vector<Disk> getRightRod();
   void setRightRod(vector<Disk> items);
};

bool isEqual(State *lState, State *rState);

State *getInitialState();

State *getGoalState();

#endif