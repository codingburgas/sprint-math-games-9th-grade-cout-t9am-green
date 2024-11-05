#pragma once
#include "raylib.h"

class mapHitbox {
public:
	mapHitbox();
	Rectangle upperBound;
	Rectangle leftBound;
	Rectangle bottomBound;
	Rectangle rightBound;
	// The rectangles of the area of the map, where the character cannot go to
	void Hitbox(Rectangle &collidingObject);
	//Draws the outlines of those rectangles
private:
	const float paddingUp = 132;
	const float paddingSide = 56;
	const float paddingDown = 52;
	//The paddings of the area where the character can go to
};