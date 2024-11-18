#include "game.h"
#include <iostream>
using namespace std;

Game::Game() {
	MenuClosed = 0;
	exitGame = 0;
}

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
		map.TeacherHitbox(CharacterRec, NextCharacterRec);
		character.Update(NextCharacterRec.x, NextCharacterRec.y);
		map.TrackCharacter(CharacterRec);
	}
}

void Game::Draw() {
	if (!MenuClosed) {
		menu.Draw();
	}
	else {
		map.Draw();
		character.Draw();
		character.drawHealth();
	}

}
