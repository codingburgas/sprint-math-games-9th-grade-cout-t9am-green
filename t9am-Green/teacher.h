#pragma once
#include "raylib.h"

// Class that has all the needed values for a teacher 
class Teacher {
public:
	Teacher();
	void Draw();
	// Handles the teacher hitbox collisions and doesn't let the character go through it
	void Hitbox(Rectangle& CharacterCurrentRec, Rectangle &NextCharacterRec);
	bool CheckIfInteracting(Rectangle CharacterRec, bool &menuOpened);
	Texture2D texture;
	Texture2D heartTexture;
	Rectangle hitbox;
	Rectangle interactingHitbox;
	int healthTeacher1;
	int healthTeacher2;
	int healthTeacher3;
	int healthTeacher4;
	int healthTeacher5;
private:
};