#ifndef RENDER_H
#define RENDER_H
#include <vector>
#include "Object.h"
#include "SDL.h"
#include "Engine.h"
#include "SpriteLib.h"
using namespace std;
class Render{
	private:
	public:
		Render(){
		}
		~Render(){}
		//Renders the scene
		//objs: list of objects in scene
		void renderScene(vector<Object *> objs);
};

#endif
