#pragma once
#include "raylib.h"
#include "hitbox.h"

class Teacher {
public:
	Teacher();
	Texture2D texture;
	Rectangle hitbox;
	Rectangle hitboxBounds[4];
	void Draw();
	void initializeHitboxBounds(Rectangle hitbox);
	void Hitbox(Rectangle &collidingObject); 
		
private:
};