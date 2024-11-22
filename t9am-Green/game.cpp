#include "game.h"

Game::Game() {
	MenuClosed = false;
	exitGame = false;
	MenuToInteractOpened = false;
	gameOverMenuOpened = false;
	gameWinMenuOpened = false;
	PauseMenuOpened = false;
	ControlsMenuOpened = false;
}

// Checks for collisions, checks if the player clicks a button in the menu and updates the positions of the game objects
void Game::Update() {
	if (PauseMenuOpened) {
		PauseMenuOpened = !menu.CheckIfResumeClicked();
		exitGame = menu.CheckIfExitPauseClicked();
		if (menu.CheckIfControlsClicked()) {
			ControlsMenuOpened = true;
		}
			if (menu.CheckIfExitControlsClicked())
				ControlsMenuOpened = false;
	}

	if (!MenuClosed) {
		MenuClosed = menu.CheckIfPlayIsClicked();
		exitGame = menu.CheckIfExitIsClicked();
	}
	else if (!PauseMenuOpened and !gameOverMenuOpened){
			Rectangle CharacterRec = character.getTextureRect();
			// The player's hitbox with his position after one step
			Rectangle NextCharacterRec = character.getCharacterNextRect();
			map.UpdateDoor(CharacterRec);
			map.CheckIfDoorIsUsed(NextCharacterRec);

			mapHitbox.CheckForColliding(CharacterRec, NextCharacterRec);
			map.DesksHitboxes(CharacterRec, NextCharacterRec);
			map.BookshelvesHitboxes(CharacterRec, NextCharacterRec);
			map.SofasHitboxes(CharacterRec, NextCharacterRec);
			map.TeacherHitbox(CharacterRec, NextCharacterRec);
			map.teacher.setCollidingState(map.teacher.CheckColission(NextCharacterRec));
			if (map.currentRoomID != 1)
				map.CheckCollidingTeacherDesk(CharacterRec, NextCharacterRec);
			if (!MenuToInteractOpened)
				character.Update(NextCharacterRec.x, NextCharacterRec.y);
			map.TrackCharacter(CharacterRec);
			map.teacher.CheckIfInteracting(CharacterRec, MenuToInteractOpened);
			if (MenuToInteractOpened) {
				MenuToInteractOpened = !menu.CheckIfInteractionClosed();
			}
			if (character.health <= 0)
				gameOverMenuOpened = true;
			if (IsKeyPressed(KEY_Q))
				PauseMenuOpened = true;
			if (map.isEachLevelPassed[5] == true)
				gameWinMenuOpened = true;
	}
}

// Returns 1 if the math problem is solved wrongly, 2 if it's solved correctly and 0 if it doesn't check for the solution
int Game::IsProblemSolved(string currentProblem) {
		switch (map.currentRoomID) {
		case 2:
			if (menu.textBox.text == AllMathProblems.Level1[currentProblem])
				return 2;
			else
				return 1;
			break;
		case 3:
			if (menu.textBox.text == AllMathProblems.Level2[currentProblem])
				return 2;
			else
				return 1;
			break;
		case 4:
			if (menu.textBox.text == AllMathProblems.Level3[currentProblem])
				return 2;
			else
				return 1;
			break;
		case 5:
			if (menu.textBox.text == AllMathProblems.Level4[currentProblem])
				return 2;
			else
				return 1;
			break;
		case 6:
			if (menu.textBox.text == AllMathProblems.Level5[currentProblem])
				return 2;
			else
				return 1;
			break;
		}
	return 0;
}

// Takes damage on the player or teacher whether the math problem is solved correctly
void Game::DamagePlayerOrTeacher(int problemCorrect) {
	if (problemCorrect == 1)
		character.health--;
	else if (problemCorrect == 2) {
		switch (map.currentRoomID - 1)
		{
		case 1:
			map.teacher.healthTeacher1--;
			if(map.teacher.healthTeacher1 == 0)
				menu.textBox.textboxActive = false;
			map.CheckIfLevelPassed(map.currentRoomID - 1, map.teacher.healthTeacher1);
			break;
		case 2:
			map.teacher.healthTeacher2--;
			if (map.teacher.healthTeacher2 == 0)
				menu.textBox.textboxActive = false;
			map.CheckIfLevelPassed(map.currentRoomID - 1, map.teacher.healthTeacher2);
			break;
		case 3:
			map.teacher.healthTeacher3--;
			if (map.teacher.healthTeacher3 == 0)
				menu.textBox.textboxActive = false;
			map.CheckIfLevelPassed(map.currentRoomID - 1, map.teacher.healthTeacher3);
			break;
		case 4:
			map.teacher.healthTeacher4--;
			if (map.teacher.healthTeacher4 == 0)
				menu.textBox.textboxActive = false;
			map.CheckIfLevelPassed(map.currentRoomID - 1, map.teacher.healthTeacher4);
			break;
		case 5:
			map.teacher.healthTeacher5--;
			if (map.teacher.healthTeacher5 == 0)
				menu.textBox.textboxActive = false;
			map.CheckIfLevelPassed(map.currentRoomID - 1, map.teacher.healthTeacher5);
			break;
		}
	}
}

// Draws all the game elements, menus and objects
void Game::Draw() {
	if (!MenuClosed) {
		menu.Draw();
	}
	else {
		map.Draw();
		character.Draw();
		character.drawHealth();
	}

	if (MenuToInteractOpened) {
		
		// Show different math problems according to the current room (level)
		switch (map.currentRoomID - 1) {
		case 1:
			if (!map.isEachLevelPassed[map.currentRoomID - 1] ) {
				menu.DrawInteractionMenu();
				DrawText("Your health:", (int)menu.interactionMenu.x + 4, (int)menu.interactionMenu.y + 4, 25, WHITE);
				for (int playerHealth = 0; playerHealth < character.health; playerHealth++)
					DrawTexture(character.heartTexture, (int)menu.interactionMenu.x + 5 + (int)playerHealth * character.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
				DrawText("Teacher's health:", (int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 100, (int)menu.interactionMenu.y + 4, 25, WHITE);

				for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher1; teacherHealth++)
					DrawTexture(map.teacher.heartTexture, ((int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 10) + (int)teacherHealth * map.teacher.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
				menu.ShowRandomProblem(AllMathProblems.randomProblem1);
				if (menu.IsCheckClicked() or IsKeyPressed(KEY_ENTER)) {
					DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem1)));
					AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
					menu.textBox.ClearText();
				}
			}
			else
				MenuToInteractOpened = false;
			break;
		case 2:
			if (!map.isEachLevelPassed[map.currentRoomID - 1]) {
				menu.DrawInteractionMenu();
				DrawText("Your health:", (int)menu.interactionMenu.x + 4, (int)menu.interactionMenu.y + 4, 25, WHITE);
				for (int playerHealth = 0; playerHealth < character.health; playerHealth++)
					DrawTexture(character.heartTexture, (int)menu.interactionMenu.x + 5 + (int)playerHealth * character.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
				DrawText("Teacher's health:", (int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 100, (int)menu.interactionMenu.y + 4, 25, WHITE);

			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher2; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, ((int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 10) + (int)teacherHealth * map.teacher.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem2);
			if (menu.IsCheckClicked() or IsKeyPressed(KEY_ENTER)) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem2)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
				menu.textBox.ClearText();
			}
			}
			else
				MenuToInteractOpened = false;
			break;
		case 3:
			if (!map.isEachLevelPassed[map.currentRoomID - 1]) {
				menu.DrawInteractionMenu();
				DrawText("Your health:", (int)menu.interactionMenu.x + 4, (int)menu.interactionMenu.y + 4, 25, WHITE);
				for (int playerHealth = 0; playerHealth < character.health; playerHealth++)
					DrawTexture(character.heartTexture, (int)menu.interactionMenu.x + 5 + (int)playerHealth * character.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
				DrawText("Teacher's health:", (int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 100, (int)menu.interactionMenu.y + 4, 25, WHITE);

			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher3; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, ((int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 10) + (int)teacherHealth * map.teacher.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem3);
			if (menu.IsCheckClicked() or IsKeyPressed(KEY_ENTER)) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem3)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
				menu.textBox.ClearText();
			}
			}
			else
				MenuToInteractOpened = false;
			break;
		case 4:
			if (!map.isEachLevelPassed[map.currentRoomID - 1]) {
				menu.DrawInteractionMenu();
				DrawText("Your health:", (int)menu.interactionMenu.x + 4, (int)menu.interactionMenu.y + 4, 25, WHITE);
				for (int playerHealth = 0; playerHealth < character.health; playerHealth++)
					DrawTexture(character.heartTexture, (int)menu.interactionMenu.x + 5 + (int)playerHealth * character.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
				DrawText("Teacher's health:", (int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 100, (int)menu.interactionMenu.y + 4, 25, WHITE);

			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher4; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, ((int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 10) + (int)teacherHealth * map.teacher.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem4);
			if (menu.IsCheckClicked() or IsKeyPressed(KEY_ENTER)) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem4)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
				menu.textBox.ClearText();
			}
			}
			else
				MenuToInteractOpened = false;
			break;
		case 5:
			if (!map.isEachLevelPassed[map.currentRoomID - 1]) {
				menu.DrawInteractionMenu();
				DrawText("Your health:", (int)menu.interactionMenu.x + 4, (int)menu.interactionMenu.y + 4, 25, WHITE);
				for (int playerHealth = 0; playerHealth < character.health; playerHealth++)
					DrawTexture(character.heartTexture, (int)menu.interactionMenu.x + 5 + (int)playerHealth * character.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
				DrawText("Teacher's health:", (int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 100, (int)menu.interactionMenu.y + 4, 25, WHITE);

			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher5; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, ((int)menu.interactionMenu.x + (int)menu.interactionMenu.width - (int)3 * map.teacher.heartTexture.width - 10) + (int)teacherHealth * map.teacher.heartTexture.width, (int)menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem5);
			if (menu.IsCheckClicked() or IsKeyPressed(KEY_ENTER)) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem5)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
				menu.textBox.ClearText();
			}
			}
			else
				MenuToInteractOpened = false;
			break;
		}
	}
		if (gameWinMenuOpened) {
			menu.DrawWinWindow();
			exitGame = menu.CheckIfCloseClicked();
		}
	if (gameOverMenuOpened) {
		menu.DrawGameOverMenu();
		exitGame = menu.CheckIfCloseClicked();
	}
	if (ControlsMenuOpened)
		menu.DrawControls();
	else if (PauseMenuOpened)
		menu.DrawPauseMenu();
}
