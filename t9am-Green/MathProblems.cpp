#include "MathProblems.h"
#include <random>


MathProblems::MathProblems() {
	Level1["15 + 7 = ?"] = "22";
	Level1["17 + 18 = ?"] = "35";
	Level1["63 + 54 = ?"] = "117";
	Level1["76 + 34 = ?"] = "100";
	Level1["23 + 48 = ?"] = "71";
	Level1["54 + 32 = ?"] = "86";
	Level1["37 + 82 = ?"] = "119";

	Level2["216 - 157 = ?"] = "59";
	Level2["231 - 43 = ?"] = "188";
	Level2["513 - 379 = ?"] = "134";
	Level2["57 - 43 = ?"] = "14";
	Level2["97 - 78 = ?"] = "19";
	Level2["143 - 57 = ?"] = "86";
	Level2["120 - 77 = ?"] = "43";
	Level2["136 - 29 = ?"] = "107";

	Level3["24 * 7 = ?"] = "168";
	Level3["34 * 5 = ?"] = "170";
	Level3["87 * 3 = ?"] = "261";
	Level3["34 * 6 = ?"] = "204";
	Level3["5 * 13 = ?"] = "65";
	Level3["81 * 11 = ?"] = "891";
	Level3["32 * 15 = ?"] = "480";
	Level3["41 * 13 = ?"] = "533";



	Level4["27 / 9 = ?"] = "3";
	Level4["155 / 5 = ?"] = "31";
	Level4["178 / 2 = ?"] = "89";
	Level4["(112 / 4) / 4 = ?"] = "7";
	Level4["1111 / 11 = ?"] = "101";
	Level4["435 / 15 = ?"] = "29";
	Level4["117 / 9 = ?"] = "13";
	Level4["272 / 16 = ?"] = "17";


	Level5["sqrt(225) = ?"] = "15";
	Level5["147 + 325 = ?"] = "472";
	Level5["769 - 547 = ?"] = "222";
	Level5["87 * 16 = ?"] = "1392";
	Level5["20 736 / 32 = ?"] = "648";
	Level5["4 245 - 3 476 = ?"] = "769";
	Level5["6 939 / 27 = ?"] = "257";
	Level5["875 / 15 = ?"] = "59";


	randomProblem1 = GetRandomProblem(Level1);
	randomProblem2 = GetRandomProblem(Level2);
	randomProblem3 = GetRandomProblem(Level3);
	randomProblem4 = GetRandomProblem(Level4);
	randomProblem5 = GetRandomProblem(Level5);
	ProblemsShown = {};
}

// Gets a random math problem from a certain level of math problems, provided as a parameter
map<string, string> MathProblems::GetRandomProblem(map<string, string> levelNumber) {
	map <string, string> randomProblem;
	bool problemIsAlreadyShown = false;

	map<string, string>::iterator it = levelNumber.begin();
	advance(it, rand() % levelNumber.size());
	
	if (problemIsAlreadyShown) {
		while (problemIsAlreadyShown) {
			advance(it, rand() % levelNumber.size());
			for (int i = 0; i < ProblemsShown.size(); i++) {
				if (ProblemsShown[i] == it->first)
					problemIsAlreadyShown = true;
				else
					problemIsAlreadyShown = false;
			}
			if (!problemIsAlreadyShown)
				break;
		}
	}

	ProblemsShown.push_back(it->first);
	randomProblem[it->first] = levelNumber[it->first];
	if (ProblemsShown.size() == levelNumber.size()) {
		ProblemsShown = {};
	}

	return randomProblem;
}

// Gets the math expresion from the current math problem
string MathProblems::GetCurrentProblem(map<string, string> currentProblem) {
	map<string, string>::iterator it = currentProblem.begin();
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
	case 3:
		randomProblem3 = GetRandomProblem(Level3);
		break;
	case 4:
		randomProblem4 = GetRandomProblem(Level4);
		break;
	case 5:
		randomProblem5 = GetRandomProblem(Level5);
		break;

	}
}
