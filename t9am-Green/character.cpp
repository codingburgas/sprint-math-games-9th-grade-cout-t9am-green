#include "character.h"

Character::Character() {
	speed = 13;
	movingRight = LoadTexture("Graphics/spriteRight.png");
	movingLeft = LoadTexture("Graphics/spriteLeft.png");
	movingUp = LoadTexture("Graphics/spriteUp.png");
	movingDown = LoadTexture("Graphics/spriteDown.png"); 
	position = { 0.f, 0.f };
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

void Character::Update(float x, float y) { //These x and y variables will change only when the character is
	position.x = x;						   //trying to walk through the wall (look at the Update() function
	position.y = y;						   //in the game.cpp file and at the CheckForColliding function in
										   //the mapHitbox.cpp file.


	if (IsKeyDown(KEY_D)) { //Moving right
		frame++;
		source = { 0.f, 0.f, (float)movingRight.width / 4.f, (float)movingRight.height };
		source.x = (float)frame * source.width;
		position.x += speed;
		WaitTime(updateTime);
	}
	else if (IsKeyDown(KEY_A)) { // Moving left
		frame++;
		source = { 0.f, 0.f, (float)movingLeft.width / 4.f, (float)movingLeft.height };
		source.x = (float)frame * source.width;
		position.x -= speed;
		WaitTime(updateTime);
	}
	else if (IsKeyDown(KEY_W)) { // Moving up
		frame++;
		source = { 0.f, 0.f, (float)movingUp.width / 4.f, (float)movingUp.height };
		source.x = (float)frame * source.width;
		position.y -= speed;
		WaitTime(updateTime);
	}
	else if (IsKeyDown(KEY_S)) { // Moving down
		frame++;
		source = { 0.f, 0.f, (float)movingDown.width / 4.f, (float)movingDown.height };
		source.x = (float)frame * source.width;
		position.y += speed;
		WaitTime(updateTime);
	}
	else { // Not moving
		source = { 0.f, 0.f, (float)movingDown.width / 4.f, (float)movingDown.height };
	}
}

Rectangle Character::getTextureRect() {
	return Rectangle{ position.x, position.y, source.width, source.height };
}


