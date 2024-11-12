#pragma once
#include "raylib.h"
#include <vector>
#include "mapHItbox.h"
using namespace std;

class Map {
public:
	Map();
	void Draw();
	void UpdateDoor(Rectangle &CollidingObject);
	bool CheckDoorColliding(Rectangle collidingObject);
	void ChangeTheRoom();
	void CheckIfDoorIsUsed(Rectangle character);
	void TrackCharacter(Rectangle character);
	//The hall position along X axis. It is in a separated variable because it will change as the character is moving in
	//the hall
	int hallXPosition;
	//Contains how much pixels did the hall position change compared to its initial position
	int hallPositionOffset;
    Texture2D CurrentRoomTexture;
	Texture2D doorNotCollidingTexture;
	Texture2D doorCollidingTexture;
	Texture2D doorCurrentTexture;
	Rectangle door;
	MapHitbox mapHitbox;

private:
	int currentRoomID;
	vector <Texture2D> rooms = {
     LoadTexture("Graphics/hall.png"),
	 LoadTexture("Graphics/room1.png")
	};

};