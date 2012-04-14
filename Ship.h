#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "Object.h"

using namespace std;

class Ship : public Object{
	protected:
		bool forward;
		bool backward;
		bool ccw;
		bool cw;
		int thrustFrameNum;
	public:
		Ship();
		~Ship();
		void thrust(int dir);
		void rotating(int dir);
		void stopThrusting(int dir);
		void stopRotating(int dir);
		void go();
};


#endif

