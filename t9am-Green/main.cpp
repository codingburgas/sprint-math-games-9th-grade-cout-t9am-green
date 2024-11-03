#include "raylib.h"
#include "character.h"
#include "mapHItbox.h"

int main() {
	InitWindow(900, 500, "test");

	Texture2D map = LoadTexture("Graphics/map1.png"); //Contains the map texture
	Texture2D door = LoadTexture("Graphics/door1.png"); //Contains the door texture

	Character character;
	mapHitbox mapHitbox;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		character.Update(); //Updates the character position

		BeginDrawing();

		ClearBackground(WHITE);
		DrawTexture(map, 0, 0, WHITE);
		mapHitbox.drawHitbox(character.getTextureRect());

		DrawTexture(door, 500, 70, WHITE); //Draws the door

		character.Draw(); // Draws the character
		character.drawHitbox(); // Draws the character hitbox

		EndDrawing();

	}
	CloseWindow();
}