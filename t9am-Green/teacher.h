#pragma once
#include "raylib.h"

class Teacher {
public:
	Teacher();
	Texture2D texture;
	Rectangle hitbox;
	void Draw();
	// Handles the teacher hitbox collisions and doesn't let the character go through it
	void Hitbox(Rectangle& CharacterCurrentRec, Rectangle &NextCharacterRec);
private:
};