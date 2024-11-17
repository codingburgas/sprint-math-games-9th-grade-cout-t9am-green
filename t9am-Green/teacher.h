#pragma once
#include "raylib.h"

class Teacher {
public:
	Teacher();
	// The teacher texture
	Texture2D texture;
	// The teacher hitbox
	Rectangle hitbox;
	// Draws the teacher on the screen
	void Draw();
	// Handles the teacher hitbox collisions and doesn't let the character go through it
	void Hitbox(Rectangle& CharacterCurrentRec, Rectangle &NextCharacterRec);
private:
};