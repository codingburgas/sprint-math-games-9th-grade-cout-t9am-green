#include "menu.h"

Menu::Menu() {
	playButton = { (float)GetScreenWidth() / 2 - 75,(float)GetScreenHeight() / 2 - 25, 150.f, 50.f };
	exitButton = { (float)GetScreenWidth() / 2 - 75,(float)GetScreenHeight() / 2 + 2 * playButton.height - 25, 150.f, 50.f };
	interactionMenu = { 100.f, 100.f, 700.f, 300.f };
	submitButton = { (float)textBox.textbox.x + 25, (float)textBox.textbox.y + 70, 175.f, 60.f };
	interactionCloseButton = { interactionMenu.x + interactionMenu.width - 150, interactionMenu.y + interactionMenu.height - 60, 140, 50 };
	gameWinWindow = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
	gameCloseButton = { (float)GetScreenWidth() / 2 - 100, (float)GetScreenHeight() / 2, 200.f, 50.f };
	gameOverMenu = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
	pauseMenu = interactionMenu;
	resumeButton = { pauseMenu.width / 2 + 30, 180, 160, 50 };
	controlsButton = { resumeButton.x - 20, resumeButton.y + resumeButton.height + 5, 200, 50 };
	exitGamePauseButton = { resumeButton.x - 25, controlsButton.y + controlsButton.height + 5, 210, 50 };
	controlsMenu = interactionMenu;
	exitControlsMenuButton = { controlsMenu.x + controlsMenu.width - 160, controlsMenu.y + controlsMenu.height - 60, 150, 50 };
}

// Draws the start menu
void Menu::Draw() {
	DrawText("Count the Teacher", (float)GetScreenWidth() / 2 - 150, 40.f, 30, WHITE);
	ClearBackground(BLACK);
	DrawRectangleRec(playButton, GREEN);
	DrawTextEx(GetFontDefault(), "Play", { playButton.x + MeasureTextEx(GetFontDefault(), "Play", 20, 5).x / 2, playButton.y }, 45, 5, WHITE);
	DrawRectangleRec(exitButton, RED);
	DrawTextEx(GetFontDefault(), "Exit", { exitButton.x + MeasureTextEx(GetFontDefault(), "Exit", 30, 5).x / 2, exitButton.y }, 45, 5, WHITE);
}

// Draws the interaction menu
void Menu::DrawInteractionMenu() {
	DrawRectangleRec(interactionMenu, DARKGRAY);
	DrawRectangleLinesEx(interactionMenu, 4, BLACK);
	textBox.Update();
	textBox.Draw();
	DrawRectangleRec(submitButton, GREEN);
	DrawRectangleLinesEx(submitButton, 4, DARKGREEN);
	DrawText("Check", submitButton.x + 10, submitButton.y + 5, 50, WHITE);
	DrawRectangleRec(interactionCloseButton, RED);
	DrawRectangleLinesEx(interactionCloseButton, 3, MAROON);
	DrawText("Close", interactionCloseButton.x + 10, interactionCloseButton.y + 5, 40, WHITE);
}

// Returns true when we click on the play button
bool Menu::CheckIfPlayIsClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), playButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 1;
	else
		return 0;
}

// Returns true when we click on the exit button
bool Menu::CheckIfExitIsClicked()
{
	if (CheckCollisionPointRec(GetMousePosition(), exitButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 1;
	else
		return 0;
}

// Returns true if the player clicks on the close button while interacting with a teacher
bool Menu::CheckIfInteractionClosed()
{
	if (CheckCollisionPointRec(GetMousePosition(), interactionCloseButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		textBox.ClearText();
		textBox.textboxActive = false;
		return 1;
	}
	else
		return 0;
}

// Returns true if the check button is clicked in the interacting menu
bool Menu::IsCheckClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), submitButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return true;
	else
		return false;
}

// Checks if the player clicks the close button in the window for winning the game.
bool Menu::CheckIfCloseClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), gameCloseButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return true;
	else
		return false;
}

bool Menu::CheckIfResumeClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), resumeButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return true;
	else
		return false;
}

bool Menu::CheckIfControlsClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), controlsButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return true;
	else
		return false;
}

bool Menu::CheckIfExitPauseClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), exitGamePauseButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return true;
	else
		return false;
}

bool Menu::CheckIfExitControlsClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), exitControlsMenuButton) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return true;
	else
		return false;
}

// Shows a random math problem in the interaction menu
void Menu::ShowRandomProblem(map<string, string> RandomProblem) {
	auto it = RandomProblem.begin();

	DrawText(it->first.c_str(), textBox.textbox.x + 20, textBox.textbox.y - 50, 30, WHITE);
}

void Menu::DrawWinWindow() {
	DrawRectangleRec(gameWinWindow, GREEN);
	DrawRectangleLinesEx(gameWinWindow, 10, DARKGREEN);
	DrawText("YOU WON THE GAME!", GetScreenWidth() / 2.f - 165 , 180, 30, WHITE);
	DrawRectangleRec(gameCloseButton, RED);
	DrawText("Close", (float)gameCloseButton.x + 40, (float)gameCloseButton.y + 8, 40, WHITE);
}

void Menu::DrawGameOverMenu() {
	DrawRectangleRec(gameOverMenu, DARKGRAY);
	DrawText("GAME OVER", GetScreenWidth() / 2.f - 140, 100, 50, RED);
	DrawRectangleLinesEx(gameOverMenu, 4, BLACK);
	DrawRectangleRec(gameCloseButton, RED);
	DrawText("Close", (float)gameCloseButton.x + 40, (float)gameCloseButton.y + 8, 40, WHITE);
}

void Menu::DrawPauseMenu() {
	DrawRectangleRec(pauseMenu, GRAY);
	DrawRectangleLinesEx(pauseMenu, 4, BLACK);
	DrawText("Paused", GetScreenWidth() / 2.f - 80, 120, 50, WHITE);
	DrawRectangleRec(resumeButton, LIGHTGRAY);
	DrawRectangleLinesEx(resumeButton, 3, DARKGRAY);
	DrawText("Resume", resumeButton.x + 7, resumeButton.y + 8, 40, BLACK);
	DrawRectangleRec(controlsButton, LIGHTGRAY);
	DrawRectangleLinesEx(controlsButton, 3, DARKGRAY);
	DrawText("Controls", controlsButton.x + 10, controlsButton.y + 8, 40, BLACK);
	DrawRectangleRec(exitGamePauseButton, LIGHTGRAY);
	DrawRectangleLinesEx(exitGamePauseButton, 3, DARKGRAY);
	DrawText("Exit Game", exitGamePauseButton.x + 10, exitGamePauseButton.y + 8, 40, BLACK);
}

void Menu::DrawControls() {
	DrawRectangleRec(controlsMenu, GRAY);
	DrawRectangleLinesEx(controlsMenu, 4, BLACK);
	DrawText("Controls", controlsMenu.width / 2, controlsMenu.y + 10, 40, WHITE);
	DrawText("WASD - Move", controlsMenu.x + 10, controlsMenu.y + 70, 40, BLACK);
	DrawText("E - Interact", controlsMenu.x + 10, controlsMenu.y + 110, 40, BLACK);
	DrawText("P - Pause", controlsMenu.x + 10, controlsMenu.y + 150, 40, BLACK);
	DrawRectangleRec(exitControlsMenuButton, RED);
	DrawText("Back", exitControlsMenuButton.x + 10, exitControlsMenuButton.y + 8, 40, BLACK);
}
