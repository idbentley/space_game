#ifndef OPTIONMENU_H
#define OPTIONMENU_H

#include "Menu.h"
#include "Engine.h"
#include "SDL.h"
#define AUDIO 0
#define VIDEO 1
#define MAIN 2
#define NUMITEMS 3

class OptionMenu : public Menu{
	private:
		Menu *mainMenu;
		void initMenuOptionsVisuals();
		void renderMenuSelection(int select);
	protected:
	public:
		OptionMenu(Menu *);
		~OptionMenu();
		void execCommand();
		void renderMenu();
};

#endif

