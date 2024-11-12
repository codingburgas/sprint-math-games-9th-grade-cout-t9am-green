#include "map.h"

Map::Map() {
	hallPositionOffset = 0;
	hallXPosition = 0;
	currentRoomID = 1;
	//Contains the map texture
	CurrentRoomTexture = rooms[0]; 
	//Contains the door texture when it isn't colliding
	doorNotCollidingTexture = LoadTexture("Graphics/Door.png"); 
	//Contains the door texture when it is colliding
	doorCollidingTexture = LoadTexture("Graphics/DoorColliding.png"); 
	doorCurrentTexture = doorNotCollidingTexture;
	//The door hitbox
	door = { 170, 70, (float)doorCurrentTexture.width, (float)doorCurrentTexture.height}; 
}

//Draws the map with its elements on the screen
void Map::Draw() { 
//Draws the map on the screen
switch (currentRoomID) {
case 1:
	DrawTexture(CurrentRoomTexture, hallXPosition, 0, WHITE);
	break;
default:
	DrawTexture(CurrentRoomTexture, 0, 0, WHITE);
}
//Draws the door on the screen
DrawTexture(doorCurrentTexture, door.x, door.y, WHITE); 

}

//Updates the door texture if it is colliding with the character
void Map::UpdateDoor(Rectangle& CollidingObject) 
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

//Returns true if the character is colliding with the door
bool Map::CheckDoorColliding(Rectangle collidingObject)
{
	if (CheckCollisionRecs(door, collidingObject))
		return true;

	else
		return false;
}

//Changes the current room texture and changes the current room id
void Map::ChangeTheRoom()
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

//Checks if the player presses 'E' while colliding with the door
void Map::CheckIfDoorIsUsed(Rectangle character)
{
	if (CheckDoorColliding(character) and IsKeyPressed(KEY_E))
     ChangeTheRoom();
	
	
}

//Tracks where the player goes when he is in the hall
void Map::TrackCharacter(Rectangle character) {
	if (currentRoomID == 1) {
		//These bounds are used to track when the hall position should change. They are a little bigger than the mapHitbox bounds
		Rectangle leftBoundForTracking{ mapHitbox.leftBound.width, mapHitbox.upperBound.height, 15, mapHitbox.leftBound.height };
		Rectangle rightBoundForTracking { 900 - mapHitbox.rightBound.width - 15, mapHitbox.upperBound.height, 15, mapHitbox.rightBound.height };
		
		if (CheckCollisionRecs(character, leftBoundForTracking) and IsKeyDown(KEY_A)) {
			if (hallPositionOffset != 0) {
				hallXPosition += 30;
				door.x += 30;
				hallPositionOffset -= 30;
			}
		}
		else if (CheckCollisionRecs(character, rightBoundForTracking) and IsKeyDown(KEY_D)) {
			if (hallPositionOffset < rooms[0].width - (mapHitbox.rightBound.width + 30 + (900 - mapHitbox.leftBound.width))) {
				hallXPosition -= 30;
				door.x -= 30;
				hallPositionOffset += 30;
			}
		}
	}
}

