#pragma once
#include "raylib.h"
#include <vector>
#include "mapHItbox.h"
#include "teacher.h"
#include "hitbox.h"
using namespace std;

class Map {
public:
	Map();
	void Draw();
	void UpdateDoor(Rectangle CollidingObject);
	int CheckWhichDoorIsColliding(Rectangle collidingObject);
	void ChangeTheRoom(int DoorNumber, Rectangle &Character);
	void CheckIfDoorIsUsed(Rectangle &character);
	void TrackCharacter(Rectangle character);
	void TeacherHitbox(Rectangle& collidingObject);
	vector <Rectangle> initializeDoorsHitboxes(int numberOfDoors);
	vector <Texture2D> initializeDoorsTextures(int numberOfDoors);
	vector<vector <Rectangle>> initializeDesksHitboxes(int rows, int columns);
	//The hall position along X axis. It is in a separated variable because it will change as the character is moving in
	//the hall 
	int hallXPosition;
	//Contains how much pixels did the hall position change compared to its initial position
	int hallPositionOffset;
    Texture2D CurrentRoomTexture;
	Texture2D doorNotCollidingTexture;
	Texture2D doorCollidingTexture;
	Texture2D doorCurrentTexture;
	Texture2D deskTexture;
	Rectangle doorInRoomHitbox;
	vector<vector<Rectangle>> deskHitboxes;
	vector<Rectangle> doorsInHallHitboxes;
	vector<Texture2D> doorsInHallTextures;
	MapHitbox mapHitbox;
private:
	//Each room has an ID - ID 1 for the hall, ID 2 for the first classroom, ID 3 for the second classroom and so on
	int currentRoomID;
	//There are only two room textures - the hall and a classroom
	vector <Texture2D> rooms = {
     LoadTexture("Graphics/hall.png"),
	 LoadTexture("Graphics/room.png")
	};
	Teacher teacher;
};