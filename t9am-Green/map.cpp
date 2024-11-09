#include "map.h"

Map::Map() {
	mapTexture = LoadTexture("Graphics/map1.png"); //Contains the map texture
	doorTexture = LoadTexture("Graphics/Door.png"); //Contains the door texture
	door = { 170, 70, (float)doorTexture.width, (float)doorTexture.height}; 
}

void Map::Draw() { //Draws the map with its elements on the screen

DrawTexture(mapTexture, 0, 0, WHITE); //Draws the map on the screen
DrawTexture(doorTexture, door.x, door.y, WHITE); //Draws the door on the screen

}

void Map::UpdateDoor(Rectangle CollidingObject) //Updates the door texture if it is colliding with the character
{
	if (CheckCollisionRecs(door, CollidingObject))
	{
		doorTexture = LoadTexture("Graphics/DoorColliding.png");

	}
	else 
	{
		doorTexture = LoadTexture("Graphics/Door.png");
	}
}


