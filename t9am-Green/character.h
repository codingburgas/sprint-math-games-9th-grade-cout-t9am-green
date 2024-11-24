#pragma once
#include "raylib.h"
#include <time.h>
#include "mapHItbox.h"

// Class with all the needed variables and functions to draw and update the character
class Character {
public:
	Character();
	void Draw();
	void Update(float NewX, float NewY);
	Rectangle getTextureRect();
	// Returns the hitbox of the character after one step
	Rectangle getCharacterNextRect();
	void drawHealth();
	Vector2 position;
	Texture2D heartTexture;
	int health;
private:
	int speed;
	Texture2D movingRight;      
	Texture2D movingLeft;
	Texture2D movingUp;
	Texture2D movingDown;
	int frame;
	//Contains the part of the spritesheet with the current frame
	Rectangle source;
	//The time between two frames (delta time)
	const float updateTime{1.f/12.f};
};