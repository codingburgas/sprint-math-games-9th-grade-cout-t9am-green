#include "teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher()
{
	texture = LoadTexture("Graphics/TeacherTexture.png");
	hitbox = { (float)GetScreenWidth() / 2 + (GetScreenWidth() / 2) / 2 + 100, (float)GetScreenHeight() / 2, (float)texture.width, (float)texture.height };
	interactingHitbox = { hitbox.x - 30, hitbox.y - 30, hitbox.width + 60, hitbox.height + 60 };
}

// Draws the teacher in the screen
void Teacher::Draw()
{
	DrawTexture(texture, hitbox.x, hitbox.y, WHITE);
	DrawRectangleLinesEx(interactingHitbox, 2, BLACK);
}

// Handles the teacher hitbox and its collisions with the player
void Teacher::Hitbox(Rectangle& CharacterCurrentRec, Rectangle& NextCharacterRec) {
	if (CheckCollisionRecs(NextCharacterRec, hitbox)) {
		NextCharacterRec = CharacterCurrentRec;
		
	}
}

bool Teacher::CheckIfInteracting(Rectangle CharacterRec, bool& menuOpened)
{
	if (CheckCollisionRecs(CharacterRec, interactingHitbox) and IsKeyPressed(KEY_E)) {
		menuOpened = true;
		return true;
	}
	else
		return false;
}