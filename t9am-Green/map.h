#pragma once
#include "raylib.h"

class Map {
public:
	Map();
	void Draw();
private:
	Texture2D mapTexture;
	Texture2D doorTexture;
	Rectangle door;
};