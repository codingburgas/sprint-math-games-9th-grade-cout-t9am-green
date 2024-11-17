#include "character.h"

Character::Character() {
	source = { 0.f, 0.f, (float)movingDown.width / 4.f, (float)movingDown.height };
	speed = 13;
	// The next 4 lines load the textures of the character spritesheet
	movingRight = LoadTexture("Graphics/spriteRight.png");
	movingLeft = LoadTexture("Graphics/spriteLeft.png");
	movingUp = LoadTexture("Graphics/spriteUp.png");
	movingDown = LoadTexture("Graphics/spriteDown.png");
	heartTexture = LoadTexture("Graphics/heart.png");
	// The character's initial position
	position = { 100.f, 150.f};
	frame = 0;
	// The character's initial health
	health = 3;

}

// Draws the updated position of the character
void Character::Draw() {
	if (IsKeyDown(KEY_D)) { // When moving right
		DrawTextureRec(movingRight, source, position, WHITE);
	}
	else if (IsKeyDown(KEY_A)) {// When moving left
		DrawTextureRec(movingLeft, source, position, WHITE);
	}
	else if (IsKeyDown(KEY_W)) {// When moving up
		DrawTextureRec(movingUp, source, position, WHITE);
	}
	else if (IsKeyDown(KEY_S)) {// When moving down
		DrawTextureRec(movingDown, source, position, WHITE);
	}
	else {// When not moving 
		DrawTextureRec(movingDown, source, position, WHITE);
	}
}
// These x and y variables will be equal to the x and y coordinates of the hitbox of the character after one step.
void Character::Update(float x, float y) { 
	position.x = x;						   
	position.y = y;						   
										   

//Moving right
	if (IsKeyDown(KEY_D)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingRight.width / 4.f, (float)movingRight.height };
		source.x = (float)frame * source.width;
		position.x;
		WaitTime(updateTime);
	}
	// Moving left
	else if (IsKeyDown(KEY_A)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingLeft.width / 4.f, (float)movingLeft.height };
		source.x = (float)frame * source.width;
		position.x;
		WaitTime(updateTime);
	}
	// Moving up
	else if (IsKeyDown(KEY_W)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingUp.width / 4.f, (float)movingUp.height };
		source.x = (float)frame * source.width;
		position.y;
		WaitTime(updateTime);
	}
	// Moving down
	else if (IsKeyDown(KEY_S)) { 
		frame++;
		source = { 0.f, 0.f, (float)movingDown.width / 4.f, (float)movingDown.height };
		source.x = (float)frame * source.width;
		position.y;
		WaitTime(updateTime);
	}
	// Not moving
	else 
	{ 
		source = { 0.f, 0.f, (float)movingDown.width / 4.f, (float)movingDown.height };
	}
}

// Returns the current position of the character hitbox
Rectangle Character::getTextureRect() {
	return Rectangle{ position.x, position.y, source.width, source.height };
}

// Returns the position of the character hitbox after he makes one step
Rectangle Character::getCharacterNextRect() {
	Rectangle CharacterCurrentRect = getTextureRect();

	if (IsKeyDown(KEY_A))
		CharacterCurrentRect.x -= speed;
	else if (IsKeyDown(KEY_D))
		CharacterCurrentRect.x += speed;	
	else if (IsKeyDown(KEY_W))
		CharacterCurrentRect.y -= speed;
	else if (IsKeyDown(KEY_S))
		CharacterCurrentRect.y += speed;

	return CharacterCurrentRect;
}

// Draws the character health on the screen
void Character::drawHealth()
{
	for (int i = 0; i < health; i++)
	{
		DrawTexture(heartTexture, heartTexture.width * i, 0, WHITE);
	}
}
