#include "StatObj.h"

StatObj::StatObj(Vec2 p, Vec2 d, Vec2 v, float mV, float rMV, float mA, float rMA, int nS, string sM, float r){
	pos = p;
	dir = d;
	vel = v;
	maxVel = mV;
	revMaxVel = rMV;
	maxAcc = mA;
	revMaxAcc = rMA;
	spritemap = sM;
	rad = r;
	numStates = nS;
	spriteMode = 0;
}
StatObj::~StatObj(){
}
