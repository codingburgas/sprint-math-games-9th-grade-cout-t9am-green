#pragma once
#include "raylib.h"

class MapHitbox {
public:
	MapHitbox();
	Rectangle upperBound;
	Rectangle leftBound;
	Rectangle bottomBound;
	Rectangle rightBound;
	// The rectangles of the area of the map, where the character cannot go to
	void CheckForColliding(Rectangle &collidingObject);
	//Checks for collisions with the map borders and doesn't let the character go through them
private:
	const float paddingUp = 132;
	const float paddingSide = 56;
	const float paddingDown = 52;
};