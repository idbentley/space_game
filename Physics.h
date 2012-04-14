#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>
#include "Object.h"
#include "SDL.h"

using namespace std;
class Physics{
	private:
		int curTime;
		int prevTime;
		void movement(vector<Object *> objs, int dt);
		void objMovement(Object *obj, int dt);
		void collisions(vector<Object *> objs);
		inline bool checkCollision(Object *obj1, Object *obj2);
		void doCollision(vector<Object *> objs);
	public:
		Physics(){
			prevTime = SDL_GetTicks();
		}
		~Physics(){}
		void applyPhysics(vector<Object *> objs);

};

#endif
