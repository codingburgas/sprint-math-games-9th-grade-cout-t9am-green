#pragma once
#include <raylib.h>
class Menu {
public:
	Menu();
	Rectangle playButton;
	Rectangle exitButton;
	void Draw();
	bool CheckIfPlayIsClicked();

};
