
PROG = space_game

LDLIBS = $(shell sdl-config --libs) -lSDL_ttf
CFLAGS = $(shell sdl-config --cflags) -g  -ggdb -O0 -Wall

#OBJS = start.o Engine.o EventHandler.o Screen.o Menu.o MainMenu.o OptionMenu.o Physics.o Object.o Ship.o Render.o Vec2.o SpriteLib.o StatObj.o Config.o
#HDRS = Engine.h EventHandler.h Screen.h Menu.h MainMenu.h OptionMenu.h Physics.h Object.h Ship.h Render.h Vec2.h SpriteLib.h StatObj.h Config.h
OBJS = start.o Engine.o EventHandler.o Screen.o Menu.o MainMenu.o OptionMenu.o Physics.o Object.o Ship.o Render.o Vec2.o SpriteLib.o StatObj.o Config.o Util.o
HDRS = Engine.h EventHandler.h Screen.h Menu.h MainMenu.h OptionMenu.h Physics.h Object.h Ship.h Render.h Vec2.h SpriteLib.h StatObj.h Config.h Util.h

all: $(PROG) $(OBJS)

$(PROG):  $(OBJS) 
	$(CXX) $(OBJS) $(LDLIBS) -o $(PROG)

%.o: %.cpp  
	$(CXX) -c $(CFLAGS)  $<

clean: 
	rm -rf *.o $(PROG)
