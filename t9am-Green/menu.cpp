#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
	// The positions and sizes of the menu elements
	playButton = { (float)GetScreenWidth() / 2 - 75,(float)GetScreenHeight() / 2 - 25, 150, 50 };
	exitButton = { (float)GetScreenWidth() / 2 - 75,(float)GetScreenHeight() / 2 + 2 * playButton.height - 25, 150, 50 };
}

// Draws the menu
void Menu::Draw() {
	// Draws the game title
	DrawText("Count the Teacher", (float)GetScreenWidth() / 2 - 150, 40.f, 30, WHITE);
	// Makes the menu background black
	ClearBackground(BLACK);
	// Draws the play button
	DrawRectangleRec(playButton, GREEN);
	// Draws the play text
	DrawTextEx(GetFontDefault(), "Play", { playButton.x + MeasureTextEx(GetFontDefault(), "Play", 20, 5).x / 2, playButton.y }, 45, 5, WHITE);
	// Draws the exit button
	DrawRectangleRec(exitButton, RED);
	// Draws the exit text
	DrawTextEx(GetFontDefault(), "Exit", { exitButton.x + MeasureTextEx(GetFontDefault(), "Exit", 30, 5).x / 2, exitButton.y }, 45, 5, WHITE);
}

// Returns true when we click on the play button
bool Menu::CheckIfPlayIsClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), playButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 1;
	else
		return 0;
}

// Returns true when we click on the exit button
bool Menu::CheckIfExitIsClicked()
{
	if (CheckCollisionPointRec(GetMousePosition(), exitButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 1;
	else
		return 0;
}
