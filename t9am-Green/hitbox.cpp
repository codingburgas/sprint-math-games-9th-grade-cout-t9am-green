#include "hitbox.h"

// Hitboxes will be made of 4 rectangles for each side of the hitbox so that if the character collides with each side, he will be pushed
// in the opposite direction.

Rectangle hitboxBoundUp(Rectangle hitbox) {

	return Rectangle{ hitbox.x + hitbox.width/4, hitbox.y, hitbox.width/2, 1 };
}

Rectangle hitboxBoundRight(Rectangle hitbox) {
	return Rectangle{ hitbox.x + hitbox.width, hitbox.y + hitbox.height / 4, 1, hitbox.height/2 };
}

Rectangle hitboxBoundDown(Rectangle hitbox) {

	return Rectangle{ hitbox.x + hitbox.width/4, hitbox.y + hitbox.height, hitbox.width/2, 1 };
}

Rectangle hitboxBoundLeft(Rectangle hitbox) {
	return Rectangle{ hitbox.x, hitbox.y + hitbox.height/4, 1, hitbox.height/2 };
}
