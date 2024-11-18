#pragma once
#include <raylib.h>

// Class that will draw and update all the menus in the game
class Menu {
public:
	Menu();
	Rectangle playButton;
	Rectangle exitButton;
	void Draw();
	bool CheckIfPlayIsClicked();
	bool CheckIfExitIsClicked();
};
