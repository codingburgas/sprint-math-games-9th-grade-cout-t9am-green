#pragma once
#include "raylib.h"
#include <time.h>
#include "mapHItbox.h"

class Character {
public:
	Character();
	void Draw();                //Draws the character on the screen
	void Update();              //Updates the position of the character
	Rectangle getTextureRect(); //Returns the hitbox of the character
	void drawHitbox();          //Draws the hitbox of the character
private:
	Texture2D movingRight;      //Contains the spritesheet file of the character
	Vector2 position;           //Contains the position where the character is drawn
	int frame;                  //Contains the number of the current frame
	Rectangle source;           //Contains the part of the spritesheet with the current frame
	const float updateTime{1.f/12.f}; //The time between two frames
};