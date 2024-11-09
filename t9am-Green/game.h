#pragma once
#include "map.h"
#include "character.h"
#include "mapHItbox.h"

class Game {
public:
	Game();
	Map map;
	void Draw();
	void Update();
private:
	Character character;
	MapHitbox mapHitbox;
};