#include "MathProblems.h"
#include <random>


MathProblems::MathProblems() {
	Level1["15 + 7 = ?"] = "22";
	Level1["9 + 14 = ?"] = "23";
	Level1["43 + 12 = ?"] = "55";
	Level1["17 + 18 = ?"] = "35";
	Level1["62 + 41 = ?"] = "103";
	Level1["25 + 47 = ?"] = "72";
	Level1["63 + 54 = ?"] = "117";
	Level1["94 + 108 = ?"] = "202";
	Level1["37 + 82 = ?"] = "119";

	Level2["134 - 25 = ?"] = "109";
	Level2["250 - 47 = ?"] = "203";
	Level2["216 - 157 = ?"] = "59";
	Level2["412 - 367 = ?"] = "45";
	Level2["231 - 43 = ?"] = "188";
	Level2["513 - 379 = ?"] = "134";
	Level2["120 - 77 = ?"] = "43";
	Level2["136 - 29 = ?"] = "107";

	Level3["34 * 5 = ?"] = "170";

	Level4["27 / 9 = ?"] = "3";

	Level5["2^2 = ?"] = "4";
	randomProblem1 = GetRandomProblem(Level1);
	randomProblem2 = GetRandomProblem(Level2);
	randomProblem3 = GetRandomProblem(Level3);
	randomProblem4 = GetRandomProblem(Level4);
	randomProblem5 = GetRandomProblem(Level5);
	ProblemsShown = {};
}

// Gets a random math problem from a certain level of math problems, provided as a parameter
map<string, string> MathProblems::GetRandomProblem(map<string, string> levelNumber) {
	ProblemsShown = {};
	map <string, string> randomProblem;
	bool problemIsAlreadyShown = false;

	auto it = levelNumber.begin();
	advance(it, rand() % levelNumber.size());
	
	for (int i = 0; i < ProblemsShown.size(); i++) {
		if (ProblemsShown[i] == it->first)
			problemIsAlreadyShown = true;
		else
			problemIsAlreadyShown = false;
	}
	for (int i = 0; i < levelNumber.size(); i++)
	if (problemIsAlreadyShown)
		advance(it, rand() % levelNumber.size());
	else {
		ProblemsShown.push_back(it->first);
		randomProblem[it->first] = levelNumber[it->first];
		if (ProblemsShown.size() == levelNumber.size()) {
			ProblemsShown = {};
		}
		break;
	}
	return randomProblem;
}

// Gets the math expresion from the current math problem
string MathProblems::GetCurrentProblem(map<string, string> currentProblem) {
	auto it = currentProblem.begin();
	return it -> first;
}

// Changes the current problem to a random one from the same level of problems
void MathProblems::ChangeCurrentProblem(int level) {
	switch (level)
	{
	case 1:
		randomProblem1 = GetRandomProblem(Level1);
		break;
	case 2:
		randomProblem2 = GetRandomProblem(Level2);
		break;
	}
}
