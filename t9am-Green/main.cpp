#include "raylib.h"
#include "character.h"
#include "mapHItbox.h"
#include "map.h"
#include <iostream>

using namespace std;

int main() {
	InitWindow(900, 500, "test");

	Map map;
	Character character;
	mapHitbox mapHitbox;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		BeginDrawing();

		ClearBackground(WHITE);
		Rectangle characterRec = character.getTextureRect();
		
		mapHitbox.Hitbox(characterRec); //Doesn't let the character to leave the map
		
		map.Draw(); //Draws the map on the screen
		character.Update(characterRec.x, characterRec.y); //Updates the character position
		character.Draw(); // Draws the character
		EndDrawing();

	}
	CloseWindow();
}