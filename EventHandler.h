#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <iostream>
#include "SDL.h"
#include "Menu.h"
#include "Engine.h"

using namespace std;

class EventHandler{
	private:
			EventHandler();
			static EventHandler *instance;
	public:
			static EventHandler *getInstance();
			void processEvents();
			void processMenuEvents(Menu*);

};
#endif
