#include "Object.h"
int Object::getSpriteNum(){
	Vec2 v0 = Vec2(0.0f, 1.0f).normalize();
	Vec2 v1 = dir.normalize();
	float thetaR = atan2(v1[1],v1[0]) - atan2(v0[1],v0[0]);
	float thetaD = (thetaR * 180) / M_PI;
	float spriteNum = floor(thetaD)/(360.0f/NUMSEGS);
	if(spriteNum < 0)
		spriteNum += NUMSEGS;
	return static_cast<int>(spriteNum);
}
