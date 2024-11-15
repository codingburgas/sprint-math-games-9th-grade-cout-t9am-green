#include "game.h"

Game::Game() {
	
}

void Game::Update() {
	Rectangle CharacterRec = character.getTextureRect();
	mapHitbox.CheckForColliding(CharacterRec);
	map.UpdateDoor(CharacterRec);
	map.CheckIfDoorIsUsed(CharacterRec);
	character.Update(CharacterRec.x, CharacterRec.y);
	map.TrackCharacter(CharacterRec);
	bool MenuClosed = menu.CheckIfPlayIsClicked();
}

void Game::Draw() {
	if (MenuClosed)
	{
	menu.Draw();
	}
	else {
	character.drawHealth();
	map.Draw();
	character.Draw();
	}
}
