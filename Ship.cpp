#include "Ship.h"

Ship::Ship(){
	pos = Vec2(200.0f, 200.0f);
	dir = Vec2(0.0f, 1.0f);
	vel = Vec2(0.0f, 0.0f);
	acc = Vec2(0.0f, 0.0f);
	maxVel = 5.0f;
	revMaxVel = 1.0f;
	revMaxAcc = 0.05;
	maxAcc = 0.1f;
	rad = 1.0f;
	spritemap = "sprites/ship.bmp";
	numStates = 4;
	forward = false;
	backward = false;
	cw = false;
	ccw = false;
	spriteMode = 0;
}
Ship::~Ship(){}

void Ship::thrust(int dir){
	if(dir == 0){
		if(spriteMode <= 1)
			spriteMode = 1;
		thrustFrameNum = 0;
		forward = true;
	}else{
		backward = true;
	}
}
void Ship::rotating(int dir){
	if(dir == 0){
		ccw = true;
	}else{
		cw = true;
	}
}
void Ship::stopThrusting(int dir){
	if(dir == 0){
		spriteMode = 0;
		forward = false;
	}else{
		backward = false;
	}
	if(!forward && !backward){
		acc = Vec2(0, 0);
	}
}
void Ship::stopRotating(int dir){
	if(dir == 0)
		ccw = false;
	else
		cw = false;
}
void Ship::go(){
	if(!(forward&&backward)){
		if(forward&&acc.mag() < maxAcc){
			if(thrustFrameNum > 10){
				if(thrustFrameNum % 2 == 0){
					spriteMode = 2;
				}else{
					spriteMode = 3;
				}
			}
			thrustFrameNum++;
			acc = acc+(dir.normalize()*-0.01f);
		}else if(forward&&acc.mag() >= maxAcc){
			acc = (acc+(dir.normalize()*-0.01f)).normalize()*maxAcc;
		}
		if(backward&&acc.mag() < revMaxAcc){
			acc = acc+(dir.normalize()*0.0005f);
		}else if(backward&&acc.mag() >= revMaxAcc){
			acc = (acc+(dir.normalize()*0.0005f)).normalize()*maxAcc;
		}

	}
	if(ccw){
		dir = dir.rotate((M_PI/64.0));
	}
	if(cw)
		dir = dir.rotate(-(M_PI/64.0));

}
