#include "map.h"

Map::Map() {
	mapTexture = LoadTexture("Graphics/map1.png"); //Contains the map texture
	doorNotCollidingTexture = LoadTexture("Graphics/Door.png"); //Contains the door texture when it isn't colliding
	doorCollidingTexture = LoadTexture("Graphics/DoorColliding.png"); //Contains the door texture when it is colliding
	doorCurrentTexture = doorNotCollidingTexture;
	door = { 170, 70, (float)doorCurrentTexture.width, (float)doorCurrentTexture.height}; //The door hitbox
}

void Map::Draw() { //Draws the map with its elements on the screen

DrawTexture(mapTexture, 0, 0, WHITE); //Draws the map on the screen
DrawTexture(doorCurrentTexture, door.x, door.y, WHITE); //Draws the door on the screen

}

void Map::UpdateDoor(Rectangle CollidingObject) //Updates the door texture if it is colliding with the character
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


