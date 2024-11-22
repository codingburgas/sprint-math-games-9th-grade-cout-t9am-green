#pragma once
#include "map.h"
#include "character.h"
#include "mapHItbox.h"
#include "menu.h"
#include "MathProblems.h"

// Class that combines all the other classes and parts of the game
class Game {
public:
	Game();
	Map map;
	bool exitGame;
	void Draw();
	void Update();
	int IsProblemSolved(string currentProblem);
	void DamagePlayerOrTeacher(int problemCorrect);
private:
	Character character;
	MapHitbox mapHitbox;
	Menu menu;
	MathProblems AllMathProblems;
	bool MenuClosed;
	bool MenuToInteractOpened;
	bool gameOverMenuOpened;
	bool gameWinMenuOpened;
	bool PauseMenuOpened;
	bool ControlsMenuOpened;
};