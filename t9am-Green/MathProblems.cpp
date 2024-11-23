#include "MathProblems.h"


MathProblems::MathProblems() {
	Level1["15 + 7 = ?"] = "22";
	Level1["17 + 18 = ?"] = "35";
	Level1["63 + 54 = ?"] = "117";
	Level1["76 + 34 = ?"] = "100";
	Level1["23 + 48 = ?"] = "71";
	Level1["54 + 32 = ?"] = "86";
	Level1["37 + 82 = ?"] = "119";
	Level1["34 + 56 = ?"] = "90";
	Level1["78 + 29 = ?"] = "107";
	Level1["123 + 87 = ?"] = "210";
	Level1["245 + 376 = ?"] = "621";
	Level1["59 + 84 = ?"] = "143";
	Level1["432 + 218 = ?"] = "650";
	Level1["67 + 45 = ?"] = "112";
	Level1["891 + 234 = ?"] = "1125";
	Level1["308 + 492 = ?"] = "800";
	Level1["150 + 275 = ?"] = "425";


	Level2["216 - 157 = ?"] = "59";
	Level2["231 - 43 = ?"] = "188";
	Level2["513 - 379 = ?"] = "134";
	Level2["57 - 43 = ?"] = "14";
	Level2["97 - 78 = ?"] = "19";
	Level2["143 - 57 = ?"] = "86";
	Level2["120 - 77 = ?"] = "43";
	Level2["136 - 29 = ?"] = "107";
	Level2["78 - 34 = ?"] = "44";
	Level2["125 - 87 = ?"] = "38";
	Level2["456 - 123 = ?"] = "333";
	Level2["592 - 318 = ?"] = "247";
	Level2["84 - 59 = ?"] = "25";
	Level2["243 - 76 = ?"] = "167";
	Level2["900 - 456 = ?"] = "444";
	Level2["731 - 412 = ?"] = "319";
	Level2["654 - 298 = ?"] = "356";
	Level2["500 - 375 = ?"] = "125";


	Level3["24 * 7 = ?"] = "168";
	Level3["34 * 5 = ?"] = "170";
	Level3["87 * 3 = ?"] = "261";
	Level3["34 * 6 = ?"] = "204";
	Level3["5 * 13 = ?"] = "65";
	Level3["81 * 11 = ?"] = "891";
	Level3["32 * 15 = ?"] = "480";
	Level3["41 * 13 = ?"] = "533";
	Level3["7 * 8 = ?"] = "56";
	Level3["12 * 6 = ?"] = "72";
	Level3["9 * 15 = ?"] = "135";
	Level3["14 * 13 = ?"] = "182";
	Level3["25 * 4 = ?"] = "100";
	Level3["18 * 7 = ?"] = "126";
	Level3["5 * 32 = ?"] = "160";
	Level3["11 * 9 = ?"] = "99";
	Level3["16 * 12 = ?"] = "192";
	Level3["8 * 27 = ?"] = "216";


	Level4["27 / 9 = ?"] = "3";
	Level4["155 / 5 = ?"] = "31";
	Level4["178 / 2 = ?"] = "89";
	Level4["(112 / 4) / 4 = ?"] = "7";
	Level4["1,111 / 11 = ?"] = "101";
	Level4["435 / 15 = ?"] = "29";
	Level4["117 / 9 = ?"] = "13";
	Level4["272 / 16 = ?"] = "17";
	Level4["784 / 8 = ?"] = "98";
	Level4["936 / 12 = ?"] = "78";
	Level4["625 / 25 = ?"] = "25";
	Level4["1,296 / 36 = ?"] = "36";
	Level4["2,464 / 16 = ?"] = "154";
	Level4["5,184 / 27 = ?"] = "192";
	Level4["3,850 / 35 = ?"] = "110";
	Level4["6,048 / 42 = ?"] = "144";
	Level4["8,100 / 90 = ?"] = "90";
	Level4["12,672 / 96 = ?"] = "132";


	Level5["sqrt(225) = ?"] = "15";
	Level5["147 + 325 = ?"] = "472";
	Level5["769 - 547 = ?"] = "222";
	Level5["87 * 16 = ?"] = "1392";
	Level5["20 736 / 32 = ?"] = "648";
	Level5["4 245 - 3 476 = ?"] = "769";
	Level5["6 939 / 27 = ?"] = "257";
	Level5["(345 + 456) * 2 = ?"] = "1602";
	Level5["1,200 / (40 - 20) = ?"] = "60";
	Level5["(1,000 - 345) / 5 = ?"] = "131";
	Level5["(56 * 18) - 500 = ?"] = "508";
	Level5["(450 + 600) / 30 = ?"] = "35";
	Level5["(2,400 / 12) + 150 = ?"] = "350";
	Level5["(72 * 5) / 12 = ?"] = "30";
	Level5["(4,000 - 1,500) * 3 = ?"] = "7500";
	Level5["(600 / 8) * 10 = ?"] = "750";
	Level5["(800 + 1,000) / 25 = ?"] = "72";


	randomProblem1 = GetRandomProblem(Level1);
	randomProblem2 = GetRandomProblem(Level2);
	randomProblem3 = GetRandomProblem(Level3);
	randomProblem4 = GetRandomProblem(Level4);
	randomProblem5 = GetRandomProblem(Level5);
}

// Gets a random math problem from a certain level of math problems, provided as a parameter
map<string, string> MathProblems::GetRandomProblem(map<string, string> levelNumber) {
	map <string, string> randomProblem;
	bool problemIsAlreadyShown = false;

	map<string, string>::iterator it = levelNumber.begin();

	srand(time(NULL));
	advance(it, rand() % levelNumber.size());

	for (int i = 0; i < ProblemsShown.size(); i++) {
		if (ProblemsShown[i] == it->first) {
			problemIsAlreadyShown = true;
			break;
		}
		else
			problemIsAlreadyShown = false;
	}

	if (problemIsAlreadyShown == true) {
		while (problemIsAlreadyShown) {
			it = levelNumber.begin();
			advance(it, rand() % levelNumber.size());
			for (int i = 0; i < ProblemsShown.size(); i++) {
				if (ProblemsShown[i] == it->first) {
					problemIsAlreadyShown = true;
					break;
				}
				else
					problemIsAlreadyShown = false;
			}
			if (!problemIsAlreadyShown)
				break;
		}
	}
	
	ProblemsShown.push_back(it->first);
	randomProblem[it->first] = levelNumber[it->first];

	for (int i = 0; i < ProblemsShown.size(); i++)
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
