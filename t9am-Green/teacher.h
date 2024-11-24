#pragma once
#include "raylib.h"
#include <vector>
using namespace std;

// Class that has all the needed values for a teacher 
class Teacher {
public:
	Teacher();
	void Draw(int currentLevel);
	// Handles the teacher hitbox collisions and doesn't let the character go through it
	void Hitbox(Rectangle& CharacterCurrentRec, Rectangle &NextCharacterRec);
	void DrawEButton();
	void SetCollidingState(bool collidingState);
	bool CheckIfInteracting(Rectangle CharacterRec, bool &menuOpened);
	bool CheckCollision(Rectangle CharacterRec);
	vector<Texture2D> teachersTextures;
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