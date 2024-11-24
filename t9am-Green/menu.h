#pragma once
#include "raylib.h"
#include "textBox.h"
#include <map>
#include <string>
using namespace std;

// Class that will draw and update all the menus in the game
class Menu {
public:
	Menu();
	Rectangle interactionMenu;
	TextBox textBox;
	void Draw();
	void DrawInteractionMenu();
	void ShowRandomProblem(map <string, string> RandomProblem);
	void DrawWinWindow();
	void DrawGameOverMenu();
	void DrawPauseMenu();
	void DrawControls();
	bool CheckIfPlayIsClicked();
	bool CheckIfControlsIsClicked();
	bool CheckIfExitIsClicked();
	bool CheckIfInteractionClosed();
	bool IsCheckClicked();
	bool CheckIfCloseClicked();
	bool CheckIfResumeClicked();
	bool CheckIfControlsClicked();
	bool CheckIfExitPauseClicked();
	bool CheckIfExitControlsClicked();
private:
	Rectangle playButton;
	Rectangle mainMenuControlsButton;
	Rectangle exitButton;
	Rectangle submitButton;
	Rectangle interactionCloseButton;
	Rectangle gameWinWindow;
	Rectangle gameCloseButton;
	Rectangle gameOverMenu;
	Rectangle pauseMenu;
	Rectangle resumeButton;
	Rectangle controlsButton;
	Rectangle exitGamePauseButton;
	Rectangle controlsMenu;
	Rectangle exitControlsMenuButton;
};
