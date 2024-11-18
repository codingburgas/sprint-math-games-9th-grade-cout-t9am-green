#pragma once
#include "raylib.h"
#include <vector>
#include "mapHItbox.h"
#include "teacher.h"
using namespace std;

// Class with all the elements and functions needed to load the map 
class Map {
public:
	Map();

	void Draw();
	void UpdateDoor(Rectangle CollidingObject);
	int CheckWhichDoorIsColliding(Rectangle collidingObject);
	void ChangeTheRoom(int DoorNumber, Rectangle &Character);
	void CheckIfDoorIsUsed(Rectangle &character);
	void TrackCharacter(Rectangle character);
	void TeacherHitbox(Rectangle &CharacterCurrentRec, Rectangle &CharacterNextRec);
	vector <Rectangle> initializeDoorsHitboxes(int numberOfDoors);
	vector <Texture2D> initializeDoorsTextures(int numberOfDoors);
	vector<vector <Rectangle>> initializeDesksHitboxes(int rows, int columns);
	vector<Rectangle> initializeBookshelvesHitboxes(int numberOfBookshelves);
	void DesksHitboxes(Rectangle &CharacterCurrentRec, Rectangle &CharacterNextRec);
	void BookshelvesHitboxes(Rectangle &CharacterCurrentRec, Rectangle &CharacterNextRec);

	//The hall position along X axis. It is in a separated variable because it will change as the character is moving in the hall 
	int hallXPosition;
	int hallPositionOffset;
	// The texture of the current room. It will change along with the currentRoomID variable
    Texture2D CurrentRoomTexture;
	Texture2D doorNotCollidingTexture;
	Texture2D doorCollidingTexture;
	Texture2D doorCurrentTexture;
	Texture2D deskTexture;
	Texture2D bookshelfTexture;
	// The hitbox of the classroom door
	Rectangle doorInRoomHitbox;
	vector<vector<Rectangle>> deskHitboxes;
	vector<Rectangle> doorsInHallHitboxes;
	vector<Texture2D> doorsInHallTextures;
	vector<Rectangle> bookShelvesHitboxes;
	MapHitbox mapHitbox;
	Teacher teacher;
private:
	//Each room has an ID - ID 1 for the hall, ID 2 for the first classroom, ID 3 for the second classroom and so on
	int currentRoomID;
	vector <Texture2D> rooms = {
     LoadTexture("Graphics/hall.png"),
	 LoadTexture("Graphics/room.png")
	};
};