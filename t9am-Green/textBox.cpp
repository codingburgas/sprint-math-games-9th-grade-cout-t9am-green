#include "textBox.h"

TextBox::TextBox() {
	letterCounter = 0;
	textbox = { GetScreenWidth() / 2.f - 100, 180, 225, 50 };
	textboxActive = false;
}

// Draws the textbox on the screen
void TextBox::Draw() {
	DrawRectangleRec(textbox, LIGHTGRAY);
	if (textboxActive)
		DrawRectangleLinesEx(textbox, 4, RED);
	else
		DrawRectangleLinesEx(textbox, 4, BLACK);
	DrawText(text, textbox.x + 5, textbox.y + 8, 40, BLACK);
}

// Updates the textbox borders when clicked and call a function to update the text string
void TextBox::Update() {
	if (CheckCollisionPointRec(GetMousePosition(), textbox)) {
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			textboxActive = true;
	}
	else
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	if (textboxActive) {
		UpdateTheText();
		for (int i = 0; i < letterCounter; i++);
	}
}

// Updates the text string
void TextBox::UpdateTheText() {
	int key = GetKeyPressed();
	while (key > 0) {

		if (key >= 48 and key <= 57 and letterCounter < MAX_INPUT_CHARS) {
			text[letterCounter] = (char)key;
			text[letterCounter + 1] = '\0';
			letterCounter++;
		}
		key = GetKeyPressed();
	}

	if (IsKeyPressed(KEY_BACKSPACE)) {
		letterCounter--;
		if (letterCounter < 0)
			letterCounter = 0;
		text[letterCounter] = '\0';
	}
}

void TextBox::ClearText() {
	text[0] = '\0';
	letterCounter = 0;
}