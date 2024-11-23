#pragma once
#include <map>
#include <string>
#include <vector>
#include <random>
using namespace std;

// Class that has all the math problems of the game and the needed functions to interact with them
class MathProblems {
public:
	MathProblems();
	map <string, string> GetRandomProblem(map <string, string> levelNumber);
	string GetCurrentProblem(map <string, string> currentProblem);
	void ChangeCurrentProblem(int level);
	map <string, string> Level1;
	map <string, string> Level2;
	map <string, string> Level3;
	map <string, string> Level4;
	map <string, string> Level5;
	map <string, string> randomProblem1;
	map <string, string> randomProblem2;
	map <string, string> randomProblem3;
	map <string, string> randomProblem4;
	map <string, string> randomProblem5;
private:
	// Contains all the problems that already has been shown to prevent repeating the same math problem
	vector<string> ProblemsShown;
};