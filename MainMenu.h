#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"
#include "Engine.h"
#include "OptionMenu.h"
#include "SDL.h"
#define BEGIN 0
#define OPTIONS 1
#define EXIT 2
#define NUMITEMS 3

class MainMenu : public Menu{
	private:
		Menu *optionsMenu;
		void initMenuOptionsVisuals();
		void renderMenuSelection(int select);
	protected:
	public:
		MainMenu();
		~MainMenu();
		void execCommand();
		void renderMenu();
};

#endif
