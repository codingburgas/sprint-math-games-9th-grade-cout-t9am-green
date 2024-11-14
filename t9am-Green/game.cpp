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
}

void Game::Draw() {
	map.Draw();
	character.Draw();
}