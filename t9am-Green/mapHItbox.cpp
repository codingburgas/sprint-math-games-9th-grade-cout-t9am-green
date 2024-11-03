#include "mapHItbox.h"

mapHitbox::mapHitbox() {
	upperBound = { 0.f, 0.f, 844.f, 132.f };
	leftBound = { 0.f, paddingUp, 56.f, 500.f };
	rightBound = { leftBound.width + upperBound.width, 0.f, 56.f, 500.f };
	bottomBound = { 0.f, leftBound.height, 788.f, 52.f };
}

void mapHitbox::drawHitbox(Rectangle collidingObject) {
	bool isCollidingUp = false;
	bool isCollidingLeft = false;
	bool isCollidingRight = false;
	bool isCollidingDown = false;

	DrawRectangleLinesEx(upperBound, 3, BLACK);
	if (CheckCollisionRecs(upperBound, collidingObject))
		isCollidingUp = true;

	DrawRectangleLinesEx(leftBound, 3, BLACK);
	if (CheckCollisionRecs(leftBound, collidingObject))
		isCollidingLeft = true;

	DrawRectangleLinesEx(rightBound, 3, BLACK);
	if (CheckCollisionRecs(rightBound, collidingObject))
		isCollidingRight = true;

	DrawRectangleLinesEx(bottomBound, 3, BLACK);
	if (CheckCollisionRecs(bottomBound, collidingObject))
		isCollidingDown = true;

	if (isCollidingUp)
		collidingObject.y += 10;

	if (isCollidingLeft)
		collidingObject.x += 10;

	if (isCollidingRight)
		collidingObject.x -= 10;

	if (isCollidingDown)
		collidingObject.y -= 10;
}
