#ifndef OBJECT_H
#define OBJECT_H
//UGGGG
#define NUMSEGS 60

#include <iostream>
#include "Vec2.h"
#include <cmath>
using namespace std;
class Object{
	protected:
		Vec2 pos;
		Vec2 dir;
		Vec2 vel;
		Vec2 acc;
		float maxVel;
		float revMaxVel;
		float maxAcc;
		float revMaxAcc;
		float rad;
		int numStates;
		string spritemap;
		int spriteMode;
	public:
		Object(){}
		virtual ~Object(){}
		

		/*
		 * Accessors and Mutators
		 */
		void setPos(Vec2 p){ pos = p; }
		void setDir(Vec2 d){ dir = d; }
		void setVel(Vec2 v){ vel = v; }
		void setAcc(Vec2 a){ acc = a; }
		void setMaxVel(float mV){ maxVel = mV; }
		void setRad(float r){rad = r; }
		void setSpritemap(string s){spritemap = s;}
		Vec2 getPos(){ return pos; }
		Vec2 getDir(){ return dir; }
		Vec2 getVel(){ return vel; }
		Vec2 getAcc(){ return acc; }
		float getMaxVel(){ return maxVel; }
		float getRad(){return rad;}
		string getSpriteMap(){return spritemap;}
		int getSpriteNum();
		int getNumStates(){ return numStates; }
		int getSpriteMode(){ return spriteMode;}
		void setSpriteMode(int sM){ spriteMode = sM;}
};
#endif
