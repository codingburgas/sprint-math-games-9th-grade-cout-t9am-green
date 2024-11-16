#include "teacher.h"

Teacher::Teacher()
{
	texture = LoadTexture("Graphics/TeacherTexture.png");
	hitbox = { (float)GetScreenWidth() / 2 + (GetScreenWidth() / 2) / 2, (float)GetScreenHeight() / 2, (float)texture.width, (float)texture.height };
	initializeHitboxBounds(hitbox);
}

void Teacher::Draw()
{
	DrawTexture(texture, GetScreenWidth() / 2 + (GetScreenWidth() / 2) / 2, GetScreenHeight() / 2, WHITE);
}

void Teacher::initializeHitboxBounds(Rectangle hitbox) {
	hitboxBounds[0] = hitboxBoundUp(hitbox);
	hitboxBounds[1] = hitboxBoundRight(hitbox);
	hitboxBounds[2] = hitboxBoundDown(hitbox);
	hitboxBounds[3] = hitboxBoundLeft(hitbox);
}

void Teacher::Hitbox(Rectangle& collidingObject) {
	int characterSpeed = 13;
	if (CheckCollisionRecs(collidingObject, hitboxBounds[0]))
		collidingObject.y -= characterSpeed;
	else if (CheckCollisionRecs(collidingObject, hitboxBounds[1]))
		collidingObject.x += characterSpeed;
	else if (CheckCollisionRecs(collidingObject, hitboxBounds[2]))
		collidingObject.y += characterSpeed;
	else if (CheckCollisionRecs(collidingObject, hitboxBounds[3]))
		collidingObject.x -= characterSpeed;
}
