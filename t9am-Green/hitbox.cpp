#include "hitbox.h"

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
