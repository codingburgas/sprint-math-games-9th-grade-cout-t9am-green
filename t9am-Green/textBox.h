#pragma once
#include "raylib.h"
constexpr auto MAX_INPUT_CHARS = 9;

// Class that has all the needed values for the textbox 
class TextBox {
public:
	TextBox();
	void Draw();
	void Update();
	char text[MAX_INPUT_CHARS + 1] = "\0";
	int letterCounter;
	Rectangle textbox;
	bool textboxActive;
private:
	void UpdateTheText();
};