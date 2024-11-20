#include "game.h"

Game::Game() {
	MenuClosed = false;
	exitGame = false;
	MenuToInteractOpened = false;
}

// Checks for collisions, checks if the player clicks a button in the menu and updates the positions of the game objects
void Game::Update() {
	
	if (!MenuClosed) {
		MenuClosed = menu.CheckIfPlayIsClicked();
		exitGame = menu.CheckIfExitIsClicked();
	}
	else {
			Rectangle CharacterRec = character.getTextureRect();
			// The player's hitbox with his position after one step
			Rectangle NextCharacterRec = character.getCharacterNextRect();
			map.UpdateDoor(CharacterRec);
			map.CheckIfDoorIsUsed(NextCharacterRec);

			mapHitbox.CheckForColliding(CharacterRec, NextCharacterRec);
			map.DesksHitboxes(CharacterRec, NextCharacterRec);
			map.BookshelvesHitboxes(CharacterRec, NextCharacterRec);
			map.TeacherHitbox(CharacterRec, NextCharacterRec);
			character.Update(NextCharacterRec.x, NextCharacterRec.y);
			map.TrackCharacter(CharacterRec);
			map.teacher.CheckIfInteracting(CharacterRec, MenuToInteractOpened);
			if (MenuToInteractOpened) {
				MenuToInteractOpened = !menu.CheckIfInteractionClosed();
			}
	}
}

// Returns 1 if the math problem is solved wrongly, 2 if it's solved correctly and 0 if it doesn't check for the solution
int Game::IsProblemSolved(string currentProblem) {
	if (menu.IsCheckClicked()) {
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
	}
	return 0;
}

// Takes damage on the player or teacher whether the math problem is solved correctrly
void Game::DamagePlayerOrTeacher(int problemCorrect) {
	if (problemCorrect == 1)
		character.health--;
	else if (problemCorrect == 2) {
		switch (map.currentRoomID - 1)
		{
		case 1:
			map.teacher.healthTeacher1--;
			break;
		case 2:
			map.teacher.healthTeacher2--;
			break;
		case 3:
			map.teacher.healthTeacher3--;
			break;
		case 4:
			map.teacher.healthTeacher4--;
			break;
		case 5:
			map.teacher.healthTeacher5--;
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
		menu.DrawInteractionMenu();
		DrawText("Your health:", menu.interactionMenu.x + 4, menu.interactionMenu.y + 4, 25, WHITE);
		for (int playerHealth = 0; playerHealth < character.health; playerHealth++)
			DrawTexture(character.heartTexture, menu.interactionMenu.x + 5 + playerHealth*character.heartTexture.width, menu.interactionMenu.y + 30, WHITE);
		
		// Show different math problems according to the current room (level)
		switch (map.currentRoomID - 1) {
		case 1:
			DrawText("Teacher's health:", menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 100, menu.interactionMenu.y + 4, 25, WHITE);
			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher1; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, (menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 10) + teacherHealth * map.teacher.heartTexture.width, menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem1);
			if (menu.IsCheckClicked()) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem1)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
			}
			break;
		case 2:
			DrawText("Teacher's health:", menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 100, menu.interactionMenu.y + 4, 25, WHITE);
			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher2; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, (menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 10) + teacherHealth * map.teacher.heartTexture.width, menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem2);
			if (menu.IsCheckClicked()) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem2)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
			}
			break;
		case 3:
			DrawText("Teacher's health:", menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 100, menu.interactionMenu.y + 4, 25, WHITE);
			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher3; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, (menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 10) + teacherHealth * map.teacher.heartTexture.width, menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem3);
			if (menu.IsCheckClicked()) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem3)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
			}
			break;
		case 4:
			DrawText("Teacher's health:", menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 100, menu.interactionMenu.y + 4, 25, WHITE);
			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher4; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, (menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 10) + teacherHealth * map.teacher.heartTexture.width, menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem4);
			if (menu.IsCheckClicked()) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem4)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
			}
			break;
		case 5:
			DrawText("Teacher's health:", menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 100, menu.interactionMenu.y + 4, 25, WHITE);
			for (int teacherHealth = 0; teacherHealth < map.teacher.healthTeacher5; teacherHealth++)
				DrawTexture(map.teacher.heartTexture, (menu.interactionMenu.x + menu.interactionMenu.width - 3 * map.teacher.heartTexture.width - 10) + teacherHealth * map.teacher.heartTexture.width, menu.interactionMenu.y + 30, WHITE);
			menu.ShowRandomProblem(AllMathProblems.randomProblem5);
			if (menu.IsCheckClicked()) {
				DamagePlayerOrTeacher(IsProblemSolved(AllMathProblems.GetCurrentProblem(AllMathProblems.randomProblem5)));
				AllMathProblems.ChangeCurrentProblem(map.currentRoomID - 1);
			}
			break;	
		}
	}
}
