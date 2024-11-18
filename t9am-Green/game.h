#pragma once
#include "map.h"
#include "character.h"
#include "mapHItbox.h"
#include "menu.h"

// Class that combines all the other classes and parts of the game
class Game {
public:
	Game();
	Map map;
	bool exitGame;
	void Draw();
	void Update();
private:
	Character character;
	MapHitbox mapHitbox;
	Menu menu;
	bool MenuClosed;
};