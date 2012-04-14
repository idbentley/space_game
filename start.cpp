#include "Engine.h"

int main(int argc, char **argv){
	Config *config = Config::getInstance();
	Engine *engine = Engine::getInstance();
	engine->initGame(config);
}
