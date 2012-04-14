#ifndef STATOBJ_H
#define STATOBJ_H

#include "Object.h"
#include "Vec2.h"

using namespace std;
class StatObj : public Object{
	protected:
	public:
		StatObj(Vec2 p, Vec2 d, Vec2 v, float mV, float rMV, float mA, float rMA, int nS, string sM, float r);
	   	~StatObj();
};

#endif
