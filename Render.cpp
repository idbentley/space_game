#include "Render.h"
void Render::renderScene(vector<Object *> objs){
	Engine *engine = Engine::getInstance();
	for(unsigned int i = 0; i < objs.size(); i++){
		SpriteLib *spriteLib = SpriteLib::getInstance();
		spriteLib->renderSprite(static_cast<int>(objs[i]->getPos()[0]), static_cast<int>(objs[i]->getPos()[1]), objs[i]->getSpriteNum(), objs[i]->getSpriteMode(), objs[i]->getNumStates(), 60, spriteLib->getSprite(objs[i]->getSpriteMap()));
	}
	SDL_Flip(engine->getScreen()->getScreenSurface());
}
