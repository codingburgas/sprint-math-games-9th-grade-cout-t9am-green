#include "raylib.h"
#include "character.h"
#include "mapHItbox.h"
#include <iostream>

using namespace std;

int main() {
	InitWindow(900, 500, "test");

	Texture2D map = LoadTexture("Graphics/map1.png"); //Contains the map texture
	Texture2D door = LoadTexture("Graphics/door1.png"); //Contains the door texture

	Character character;
	mapHitbox mapHitbox;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		BeginDrawing();

		ClearBackground(WHITE);
		DrawTexture(map, 0, 0, WHITE);
		Rectangle characterRec = character.getTextureRect();
		mapHitbox.Hitbox(characterRec); //Doesn't let the character to leave the map
		

		DrawTexture(door, 500, 70, WHITE); //Draws the door

		character.Update(characterRec.x, characterRec.y); //Updates the character position
		character.Draw(); // Draws the character

		EndDrawing();

	}
	CloseWindow();
}