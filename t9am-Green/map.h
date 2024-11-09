#pragma once
#include "raylib.h"

class Map {
public:
	Map();
	void Draw();
	void UpdateDoor(Rectangle CollidingObject);

private:
	Texture2D mapTexture;
	Texture2D doorNotCollidingTexture;
	Texture2D doorCollidingTexture;
	Texture2D doorCurrentTexture;
	Rectangle door;
};