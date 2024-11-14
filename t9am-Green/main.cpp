#include "raylib.h"
#include "game.h"

using namespace std;

int main() {
	InitWindow(900, 500, "test");

	Game game;
	SetTargetFPS(60);

	game.map.initializeDoorsHitboxes(5);

	while (!WindowShouldClose()) {

		BeginDrawing();

		ClearBackground(WHITE);
		
		game.Draw();
		game.Update();

		EndDrawing();

	}
	CloseWindow();
}