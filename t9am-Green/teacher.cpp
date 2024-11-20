#include "teacher.h"

Teacher::Teacher()
{
	texture = LoadTexture("Graphics/TeacherTexture.png");
	heartTexture = LoadTexture("Graphics/heart.png");
	hitbox = { (float)GetScreenWidth() / 2 + (GetScreenWidth() / 2) / 2 + 100, (float)GetScreenHeight() / 2, (float)texture.width, (float)texture.height };
	interactingHitbox = { hitbox.x - 30, hitbox.y - 30, hitbox.width + 60, hitbox.height + 60 };
	healthTeacher1 = 3;
	healthTeacher2 = 3;
	healthTeacher3 = 3;
	healthTeacher4 = 3;
	healthTeacher5 = 3;
}

// Draws a teacher in the screen
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
// Checks if the player is trying to interact with a teacher
bool Teacher::CheckIfInteracting(Rectangle CharacterRec, bool& menuOpened)
{
	if (CheckCollisionRecs(CharacterRec, interactingHitbox) and IsKeyPressed(KEY_E)) {
		menuOpened = true;
		return true;
	}
	else
		return false;
}