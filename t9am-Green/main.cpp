#include "raylib.h"
#include "game.h"

using namespace std;

int main() {
	// Initializes the window
	InitWindow(900, 500, "test");

	Game game;
	// Sets amount of frames per second
	SetTargetFPS(60);

	// The game loop where everything happens
	while (!WindowShouldClose()) {

		BeginDrawing();

		ClearBackground(WHITE);

		game.Update();
		game.Draw();

		// Exits the game loop and closes the game window if the exit button in the menu is clicked
		if (game.exitGame)
			break;

		EndDrawing();

	}
	CloseWindow();
}