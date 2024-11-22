#include "raylib.h"
#include "game.h"

int main() {
	// Initializes the window
	InitWindow(900, 500, "Count the Teacher");

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