#pragma once
#include <raylib.h>
class Menu {
public:
	Menu();
	Rectangle playButton;
	Rectangle exitButton;
	// Draws the menu
	void Draw();
	// Checks if the player clicks on the play button
	bool CheckIfPlayIsClicked();
	// Checks if the player clicks on the exit button
	bool CheckIfExitIsClicked();
};
