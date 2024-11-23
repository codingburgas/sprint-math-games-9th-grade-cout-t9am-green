#pragma once
#include "raylib.h"

// Class that has all the needed values for a teacher 
class Teacher {
public:
	Teacher();
	void Draw();
	// Handles the teacher hitbox collisions and doesn't let the character go through it
	void Hitbox(Rectangle& CharacterCurrentRec, Rectangle &NextCharacterRec);
	void drawEButton();
	void setCollidingState(bool collidingState);
	bool CheckIfInteracting(Rectangle CharacterRec, bool &menuOpened);
	bool CheckCollision(Rectangle CharacterRec);
	Texture2D texture;
	Texture2D heartTexture;
	Texture2D eTexture;
	Rectangle hitbox;
	Rectangle interactingHitbox;
	int healthTeacher1;
	int healthTeacher2;
	int healthTeacher3;
	int healthTeacher4;
	int healthTeacher5;
private:
	bool isColliding;
};