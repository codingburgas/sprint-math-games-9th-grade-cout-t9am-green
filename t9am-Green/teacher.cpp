#include "teacher.h"

Teacher::Teacher()
{
	teachersTextures = {
		LoadTexture("Graphics/teacher1.png"),
		LoadTexture("Graphics/teacher2.png"),
		LoadTexture("Graphics/teacher3.png"),
		LoadTexture("Graphics/teacher4.png")
	};
	eTexture = LoadTexture("Graphics/E-button1.png");
	heartTexture = LoadTexture("Graphics/heart.png");
	hitbox = { (float)GetScreenWidth() / 2 + (GetScreenWidth() / 2) / 2 + 100 + 10, (float)GetScreenHeight() / 2, (float)teachersTextures[0].width , (float)teachersTextures[0].height - 20};
	interactingHitbox = { hitbox.x - 30, hitbox.y - 30, hitbox.width + 60, hitbox.height + 60 };
	healthTeacher1 = 3;
	healthTeacher2 = 3;
	healthTeacher3 = 3;
	healthTeacher4 = 3;
	healthTeacher5 = 3;
	isColliding = false;
}

// Draws a teacher in the screen
void Teacher::Draw(int currentLevel)
{
	switch (currentLevel)
	{
	case 1:
		DrawTexture(teachersTextures[0], (int)hitbox.x - 10, (int)hitbox.y, WHITE);
		break;
	case 2:
		DrawTexture(teachersTextures[1], (int)hitbox.x - 10, (int)hitbox.y, WHITE);
		break;
	case 3:
		DrawTexture(teachersTextures[2], (int)hitbox.x - 10, (int)hitbox.y, WHITE);
		break;
	case 4:
		DrawTexture(teachersTextures[3], (int)hitbox.x - 10, (int)hitbox.y, WHITE);
		break;
	case 5:
		DrawTexture(teachersTextures[0], (int)hitbox.x - 10, (int)hitbox.y, WHITE);
		break;
	}
}

// Handles the teacher hitbox and its collisions with the player
void Teacher::Hitbox(Rectangle& CharacterCurrentRec, Rectangle& NextCharacterRec) {
	if (CheckCollisionRecs(NextCharacterRec, hitbox)) {
		NextCharacterRec = CharacterCurrentRec;
		
	}
}
void Teacher::DrawEButton()
{
	if(isColliding)
	DrawTexture(eTexture, (int)hitbox.x + (int)hitbox.width - 10, (int)hitbox.y - (int)eTexture.height, WHITE);
}
void Teacher::SetCollidingState(bool collidingState)
{
	isColliding = collidingState;
}
// Checks if the player is trying to interact with a teacher
bool Teacher::CheckIfInteracting(Rectangle CharacterRec, bool& menuOpened)
{
	if (CheckCollision(CharacterRec) and IsKeyPressed(KEY_E)) {
		menuOpened = true;
		return true;
	}
	else
		return false;
}

bool Teacher::CheckCollision(Rectangle CharacterRec)
{
	if (CheckCollisionRecs(CharacterRec, interactingHitbox))
	return true;
	
	else
		return false;
}
