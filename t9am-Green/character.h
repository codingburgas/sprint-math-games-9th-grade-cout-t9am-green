#pragma once
#include "raylib.h"
#include <time.h>
#include "mapHItbox.h"

class Character {
public:
	Character();
	//Draws the character on the screen
	void Draw();
	//Updates the position of the character
	void Update(float x, float y);
	//Returns the hitbox of the character
	Rectangle getTextureRect();
	//Contains the position where the character is drawn
	Vector2 position;
	Texture2D heartTexture;
	int health;
	int getCharacterHealth();
	void drawHealth();
private:
	int speed;
	//Contains the spritesheet file of the character
	Texture2D movingRight;      
	Texture2D movingLeft;
	Texture2D movingUp;
	Texture2D movingDown;
	//Contains the number of the current frame
	int frame;
	//Contains the part of the spritesheet with the current frame
	Rectangle source;
	//The time between two frames
	const float updateTime{1.f/12.f};
};