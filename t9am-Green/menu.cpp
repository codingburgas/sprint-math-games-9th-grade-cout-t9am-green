#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
	playButton = { (float)GetScreenWidth() / 2 - 75,(float)GetScreenHeight() / 2 - 25, 150, 50 };
	exitButton = { (float)GetScreenWidth() / 2 - 75,(float)GetScreenHeight() / 2 + 2 * playButton.height - 25, 150, 50 };
}

void Menu::Draw() {
	ClearBackground(BLACK);
	DrawRectangleRec(playButton, GREEN);
	DrawTextEx(GetFontDefault(), "Play", { playButton.x + MeasureTextEx(GetFontDefault(), "Play", 20, 5).x / 2, playButton.y }, 45, 5, WHITE);
	DrawRectangleRec(exitButton, RED);
	DrawTextEx(GetFontDefault(), "Exit", { exitButton.x + MeasureTextEx(GetFontDefault(), "Exit", 30, 5).x / 2, exitButton.y }, 45, 5, WHITE);
	DrawText("Count the Teacher", (float)GetScreenWidth() / 2 - 150, 40.f, 30, WHITE);
}

bool Menu::CheckIfPlayIsClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), playButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 1;
	else
		return 0;
}
