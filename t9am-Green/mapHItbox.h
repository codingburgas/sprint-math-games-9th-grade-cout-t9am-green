#pragma once
#include "raylib.h"

class MapHitbox {
public:
	MapHitbox();
	// The rectangles of the area of the map, where the character cannot go to
	Rectangle upperBound;
	Rectangle leftBound;
	Rectangle bottomBound;
	Rectangle rightBound;
	//Checks for collisions with the map borders and doesn't let the character go through them
	void CheckForColliding(Rectangle &collidingObject);
private:
	const float paddingUp = 132;
	const float paddingSide = 56;
	const float paddingDown = 52;
};