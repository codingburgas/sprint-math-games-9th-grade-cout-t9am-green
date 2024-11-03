#include "character.h"

Character::Character() {
	movingRight = LoadTexture("Graphics/spriteRight.png");
	position = { 0.f, 0.f };
	frame = 0;
	source = { 0.f, 0.f, (float)movingRight.width / 4.f, (float)movingRight.height };
}

void Character::Draw() {
	DrawTextureRec(movingRight, source, position, WHITE);
}

void Character::Update() {
	if (IsKeyDown(KEY_D)) { //Moving right
		frame++;
		source.x = (float)frame * source.width;
		position.x += 10;
		WaitTime(updateTime);
	}
	else if (IsKeyDown(KEY_A)) { // Moving left
		frame++;
		source.x = (float)frame * source.width;
		position.x -= 10;
		WaitTime(updateTime);
	}
	else if (IsKeyDown(KEY_W)) { // Moving up
		frame++;
		source.x = (float)frame * source.width;
		position.y -= 10;
		WaitTime(updateTime);
	}
	else if (IsKeyDown(KEY_S)) { // Moving down
		frame++;
		source.x = (float)frame * source.width;
		position.y += 10;
		WaitTime(updateTime);
	}
	else { // Not moving
		source = { 0.f, 0.f, (float)movingRight.width / 4.f, (float)movingRight.height };
	}
}

Rectangle Character::getTextureRect() {
	return Rectangle{ position.x, position.y, source.width, source.height };
}

void Character::drawHitbox() {
	DrawRectangleLinesEx(getTextureRect(), 3, BLACK);
}

