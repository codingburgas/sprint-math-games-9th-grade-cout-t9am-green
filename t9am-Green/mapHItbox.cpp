#include "mapHItbox.h"

MapHitbox::MapHitbox() {
	upperBound = { 0.f, 0.f, 844.f, 92.f };
	leftBound = { 0.f, paddingUp, 56.f, 500.f };
	rightBound = { upperBound.width, 0.f, 56.f, 500.f };
	bottomBound = { 0.f, leftBound.height - 52, upperBound.width, 52.f };
}

void MapHitbox::CheckForColliding(Rectangle &collidingObject) { //Here a reference is used to change the 
	bool isCollidingUp = false;									//actual position of the colliding object
	bool isCollidingLeft = false;								//(the character) and not of its copy.
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
		collidingObject.y += 13;

	if (isCollidingLeft)
		collidingObject.x += 13;

	if (isCollidingRight)
		collidingObject.x -= 13;

	if (isCollidingDown)
		collidingObject.y -= 13;
}
