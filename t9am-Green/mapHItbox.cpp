#include "mapHItbox.h"

mapHitbox::mapHitbox() {
	upperBound = { 0.f, 0.f, 844.f, 132.f };
	leftBound = { 0.f, paddingUp, 56.f, 500.f };
	rightBound = { upperBound.width, 0.f, 56.f, 500.f };
	bottomBound = { 0.f, leftBound.height - 52, upperBound.width, 52.f };
}

void mapHitbox::Hitbox(Rectangle &collidingObject) {
	bool isCollidingUp = false;
	bool isCollidingLeft = false;
	bool isCollidingRight = false;
	bool isCollidingDown = false;

	if (CheckCollisionRecs(upperBound, collidingObject))
		isCollidingUp = true;

	if (CheckCollisionRecs(leftBound, collidingObject))
		isCollidingLeft = true;

	if (CheckCollisionRecs(rightBound, collidingObject))
		isCollidingRight = true;

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
