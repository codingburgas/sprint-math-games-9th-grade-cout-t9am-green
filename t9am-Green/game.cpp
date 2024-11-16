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
		map.TeacherHitbox(CharacterRec);
		character.Update(CharacterRec.x, CharacterRec.y);
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
