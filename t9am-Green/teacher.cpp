#include "teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher()
{
	texture = LoadTexture("Graphics/TeacherTexture.png");
	hitbox = { (float)GetScreenWidth() / 2 + (GetScreenWidth() / 2) / 2 + 100, (float)GetScreenHeight() / 2, (float)texture.width, (float)texture.height };
}

// Draws the teacher in the screen
void Teacher::Draw()
{
	DrawTexture(texture, hitbox.x, hitbox.y, WHITE);
}

// Handles the teacher hitbox and its collisions with the player
void Teacher::Hitbox(Rectangle& CharacterCurrentRec, Rectangle& NextCharacterRec) {
	if (CheckCollisionRecs(NextCharacterRec, hitbox)) {
		NextCharacterRec = CharacterCurrentRec;
		
	}
}


