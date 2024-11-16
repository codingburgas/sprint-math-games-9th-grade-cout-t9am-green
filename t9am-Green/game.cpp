#include "game.h"

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
		mapHitbox.CheckForColliding(CharacterRec);
		map.UpdateDoor(CharacterRec);
		map.CheckIfDoorIsUsed(CharacterRec);
		character.Update(CharacterRec.x, CharacterRec.y);
		map.TrackCharacter(CharacterRec);
		bool MenuClosed = menu.CheckIfPlayIsClicked();
	}
}

void Game::Draw() {
	if (!MenuClosed) {
		menu.Draw();
	}
	else {
	character.drawHealth();
	map.Draw();
	character.Draw();
	}
}

