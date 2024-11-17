#include "game.h"
#include <iostream>
using namespace std;

Game::Game() {
	// True when the menu is closed (When the play button is clicked)
	MenuClosed = 0;
	// True when the game should close (When the exit button is clicked)
	exitGame = 0;
}

void Game::Update() {
	// Checks if the buttons in the menu are clicked
	if (!MenuClosed) {
		MenuClosed = menu.CheckIfPlayIsClicked();
		exitGame = menu.CheckIfExitIsClicked();
	}
	else {
		// The player's hitbox with his current position
		Rectangle CharacterRec = character.getTextureRect();
		// The player's hitbox with his position after one step
		Rectangle NextCharacterRec = character.getCharacterNextRect();
		// Updates the door texture when colliding with the player
		map.UpdateDoor(CharacterRec);
		// Checks if any door is used and changes the room if a door is used
		map.CheckIfDoorIsUsed(NextCharacterRec);

		// Checks if the player is colliding with the walls and doesn't let him go through
		mapHitbox.CheckForColliding(CharacterRec, NextCharacterRec);
		// Handles the collisions between the player and the desks. Doesn't let the player to go through
		map.DesksHitboxes(CharacterRec, NextCharacterRec);
		// Handles the collision between the player and the teacher. Doesn't let the player to go through
		map.TeacherHitbox(CharacterRec, NextCharacterRec);
		// Updates the position of the character
		character.Update(NextCharacterRec.x, NextCharacterRec.y);
		// Moves the hall after the player to track him
		map.TrackCharacter(CharacterRec);
	}
}

void Game::Draw() {
	// Draws the menu if it's not closed
	if (!MenuClosed) {
		menu.Draw();
	}
	else {
		// Draws the map (The hall, the classrooms, the desks, etc.)
		map.Draw();
		// Draws the character with his new position
		character.Draw();
		// Draws the character health
		character.drawHealth();
	}

}
