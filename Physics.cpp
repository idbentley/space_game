#include "Physics.h"

void Physics::applyPhysics(vector<Object *> objs){
	curTime = SDL_GetTicks();
	movement(objs, curTime - prevTime);
	collisions(objs);
	prevTime = curTime;
}

/*
 * Loops over a list of objects and does basic movement calculations.
 */
void Physics::movement(vector<Object *>objs, int dt){
	for(unsigned int i = 0; i < objs.size(); i++)
		objMovement(objs[i], dt);
}

/*
 * Does basic movement calculations on an object.
 */
void Physics::objMovement(Object *obj, int dt){
	if(obj->getMaxVel() < ((obj->getVel() + obj->getAcc()).mag()))
		obj->setVel((obj->getVel() + obj->getAcc()).normalize()*obj->getMaxVel());
	else
		obj->setVel(obj->getVel() + obj->getAcc()*dt);
	obj->setPos(obj->getPos()+obj->getVel());
}

/*
 * Loops over the objects checking for collisions.
 * TODO: This is not done recursively as it ought to be!
 */
void Physics::collisions(vector<Object *> objs){
	for(unsigned int i = 0; i < objs.size(); i++){
		vector<Object *> temp;
		temp.push_back(objs[i]);
		for(unsigned int j = 0; j < objs.size(); j++){
			if(checkCollision(objs[i], objs[j])){
				temp.push_back(objs[j]);
			}
		}
		if(temp.size()>1)
			doCollision(temp);
	}
}

/*
 * Checks whether two objects are colliding.
 */
inline bool Physics::checkCollision(Object *obj1, Object *obj2){
		return (obj1->getRad()+obj2->getRad() < obj1->getPos().dist(obj2->getPos()));
}

/*
 * applies the collision forces between a list of objects.
 */
void Physics::doCollision(vector<Object *> objs){
	if(objs.size() == 2){
		//TODO two object collision
	}else if(objs.size() == 3){
		//TODO three object collision
	}else{
		//TODO general collision	
	}
}
