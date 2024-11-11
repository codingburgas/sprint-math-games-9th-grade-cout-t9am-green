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
	void GoToTheHall();
	void CheckIfDoorIsUsed(Rectangle character);
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