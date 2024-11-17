#include "mapHItbox.h"

MapHitbox::MapHitbox() {
	upperBound = { 0.f, 0.f, 844.f, 92.f };
	leftBound = { 0.f, paddingUp, 56.f, 500.f };
	rightBound = { upperBound.width, 0.f, 56.f, 500.f };
	bottomBound = { 0.f, leftBound.height - 52, upperBound.width, 52.f };
}
// Checks for collisions with the map border and changes the player position
void MapHitbox::CheckForColliding(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec) {
	bool isColliding = false;

	if (CheckCollisionRecs(upperBound, CharacterNextRec))
		isColliding = true;

	if (CheckCollisionRecs(leftBound, CharacterNextRec))
		isColliding = true;

	if (CheckCollisionRecs(rightBound, CharacterNextRec))
		isColliding = true;

	if (CheckCollisionRecs(bottomBound, CharacterNextRec))
		isColliding = true;

	if (isColliding)
		CharacterNextRec = CharacterCurrentRec;
}
