#include "game.h"

Game::Game() {
	map = Map();
}

void Game::Update() {
	Rectangle CharacterRec = character.getTextureRect();
	mapHitbox.CheckForColliding(CharacterRec);
	character.Update(CharacterRec.x, CharacterRec.y);
}

void Game::Draw() {
	map.Draw();
	character.Draw();
}