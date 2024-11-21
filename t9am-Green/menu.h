#pragma once
#include "raylib.h"
#include "textBox.h"
#include <map>
#include <string>
#include "time.h"
using namespace std;

// Class that will draw and update all the menus in the game
class Menu {
public:
	Menu();
	Rectangle playButton;
	Rectangle exitButton;
	Rectangle interactionMenu;
	Rectangle submitButton;
	Rectangle interactionCloseButton;
	Rectangle gameWinWindow;
	Rectangle gameWinCloseButton;
	TextBox textBox;
	void Draw();
	void DrawInteractionMenu();
	void ShowRandomProblem(map <string, string> RandomProblem);
	void DrawWinWindow();
	bool CheckIfPlayIsClicked();
	bool CheckIfExitIsClicked();
	bool CheckIfInteractionClosed();
	bool IsCheckClicked();
	bool CheckIfWinCloseClicked();

};
