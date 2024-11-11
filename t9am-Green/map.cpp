#include "map.h"

Map::Map() {
	currentRoomID = 1;
	CurrentRoomTexture = rooms[0]; //Contains the map texture
	doorNotCollidingTexture = LoadTexture("Graphics/Door.png"); //Contains the door texture when it isn't colliding
	doorCollidingTexture = LoadTexture("Graphics/DoorColliding.png"); //Contains the door texture when it is colliding
	doorCurrentTexture = doorNotCollidingTexture;
	door = { 170, 70, (float)doorCurrentTexture.width, (float)doorCurrentTexture.height}; //The door hitbox
}

void Map::Draw() { //Draws the map with its elements on the screen
DrawTexture(CurrentRoomTexture, 0, 0, WHITE); //Draws the map on the screen
DrawTexture(doorCurrentTexture, door.x, door.y, WHITE); //Draws the door on the screen

}

void Map::UpdateDoor(Rectangle& CollidingObject) //Updates the door texture if it is colliding with the character
{
	if (CheckCollisionRecs(door, CollidingObject))
	{
		doorCurrentTexture = doorCollidingTexture;
	}
	else 
	{
		doorCurrentTexture = doorNotCollidingTexture;
	}
}

bool Map::CheckDoorColliding(Rectangle collidingObject)
{
	if (CheckCollisionRecs(door, collidingObject))
		return true;

	else
		return false;
}

void Map::GoToTheHall()
{
	switch (currentRoomID)
	{
	case 1:
		CurrentRoomTexture = rooms[1];
		currentRoomID = 2;
		break;
	default:
		CurrentRoomTexture = rooms[0];
		currentRoomID = 1;



	}
}

void Map::CheckIfDoorIsUsed(Rectangle character)
{
	if (CheckDoorColliding(character) and IsKeyPressed(KEY_E))
     GoToTheHall();
	
	
}