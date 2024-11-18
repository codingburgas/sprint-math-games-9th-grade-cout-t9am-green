#pragma once
#include "raylib.h"

class Teacher {
public:
	Teacher();
	void Draw();
	// Handles the teacher hitbox collisions and doesn't let the character go through it
	void Hitbox(Rectangle& CharacterCurrentRec, Rectangle &NextCharacterRec);
	bool CheckIfInteracting(Rectangle CharacterRec, bool &menuOpened);
	Texture2D texture;
	Rectangle hitbox;
	Rectangle interactingHitbox;
private:
};