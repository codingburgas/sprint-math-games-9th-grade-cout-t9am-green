#include "raylib.h"
#include "game.h"

using namespace std;

int main() {
	// Initializes the window
	InitWindow(900, 500, "test");

	// Makes game object
	Game game;
	// Sets amount of frames per second
	SetTargetFPS(60);

	// The game loop where everything happens
	while (!WindowShouldClose()) {

		// Function to begin drawing
		BeginDrawing();

		// Makes the backkground white after every iteration
		ClearBackground(WHITE);

		// Updates the positions of all the game objects and checks for collisions
		game.Update();
		// Draws all the game objects with their updated positions
		game.Draw();

		// Exits the game loop and closes the game window if the exit button in the menu is clicked
		if (game.exitGame)
			break;

		// Function to finish drawing
		EndDrawing();

	}
	// Closes the window
	CloseWindow();
}