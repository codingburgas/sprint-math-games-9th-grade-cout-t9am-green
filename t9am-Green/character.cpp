#include "character.h"

Character::Character() {
	speed = 13;
	movingRight = LoadTexture("Graphics/spriteRight.png");
	movingLeft = LoadTexture("Graphics/spriteLeft.png");
	movingUp = LoadTexture("Graphics/spriteUp.png");
	movingDown = LoadTexture("Graphics/spriteDown.png"); 
	position = { 100.f, 0.f };
	frame = 0;
}

void Character::Draw() {
	if (IsKeyDown(KEY_D)) {
		DrawTextureRec(movingRight, source, position, WHITE);
	}
	else if (IsKeyDown(KEY_A)) {
		DrawTextureRec(movingLeft, source, position, WHITE);
	}
	else if (IsKeyDown(KEY_W)) {
		DrawTextureRec(movingUp, source, position, WHITE);
	}
	else if (IsKeyDown(KEY_S)) {
		DrawTextureRec(movingDown, source, position, WHITE);
	}
	else {
		DrawTextureRec(movingDown, source, position, WHITE);
	}
}
// These x and y variables will change only when the character is trying to walk through the wall (look at the Update()
// function in the game.cpp file and at the CheckForColliding function in the mapHitbox.cpp file.
void Character::Update(float x, float y) { 
	position.x = x;						   
	position.y = y;						   
										   

//Moving right
	if (IsKeyDown(KEY_D)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingRight.width / 4.f, (float)movingRight.height };
		source.x = (float)frame * source.width;
		position.x += speed;
		WaitTime(updateTime);
	}
	// Moving left
	else if (IsKeyDown(KEY_A)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingLeft.width / 4.f, (float)movingLeft.height };
		source.x = (float)frame * source.width;
		position.x -= speed;
		WaitTime(updateTime);
	}
	// Moving up
	else if (IsKeyDown(KEY_W)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingUp.width / 4.f, (float)movingUp.height };
		source.x = (float)frame * source.width;
		position.y -= speed;
		WaitTime(updateTime);
	}
	// Moving down
	else if (IsKeyDown(KEY_S)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingDown.width / 4.f, (float)movingDown.height };
		source.x = (float)frame * source.width;
		position.y += speed;
		WaitTime(updateTime);
	}
	// Not moving
	else { 
		source = { 0.f, 0.f, (float)movingDown.width / 4.f, (float)movingDown.height };
	}
}

Rectangle Character::getTextureRect() {
	return Rectangle{ position.x, position.y, source.width, source.height };
}
