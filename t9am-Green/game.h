#pragma once
#include "map.h"
#include "character.h"
#include "mapHItbox.h"
#include "menu.h"

class Game {
public:
	Game();
	Map map;
	//Draws all the objects of the game
	void Draw();
	//Updates the positions of the objects and checks for collisions
	void Update();
private:
	Character character;
	MapHitbox mapHitbox;
	Menu menu;
	bool MenuClosed;
};