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
	vector<Rectangle> initializeBookshelvesHitboxes();
	vector <Rectangle> initSofasHitboxes();
	vector <Texture2D> initializeDoorsTextures(int numberOfDoors);
	vector<vector <Rectangle>> initializeDesksHitboxes(int rows, int columns);
	void DesksHitboxes(Rectangle &CharacterCurrentRec, Rectangle &CharacterNextRec);
	void SofasHitboxes(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec);
	void BookshelvesHitboxes(Rectangle &CharacterCurrentRec, Rectangle &CharacterNextRec);
	void CheckIfLevelPassed(int currentLevel, int teacherHealth);
	void CheckCollidingTeacherDesk(Rectangle &CharacterCurrentRec, Rectangle &CharacterNextRec);

	//Each room has an ID - ID 1 for the hall, ID 2 for the first classroom, ID 3 for the second classroom and so on
	int currentRoomID;
	//The hall position along X axis. It is in a separated variable because it will change as the character is moving in the hall 
	int hallXPosition;
	int hallPositionOffset;
	// The texture of the current room. It will change along with the currentRoomID variable
	MapHitbox mapHitbox;
	Teacher teacher;
    Texture2D CurrentRoomTexture;
	Texture2D doorNotCollidingTexture;
	Texture2D doorCollidingTexture;
	Texture2D doorCurrentTexture;
	Texture2D deskTexture;
	Texture2D bookshelfTexture;
	Texture2D lockedPadlock;
	Texture2D unlockedPadlock;
	Texture2D teacherDesk;
	Texture2D eButton1;
	Texture2D eButton2;
	Texture2D sofaTexture;
	Texture2D board;
	vector<Texture2D> paintingsTextures;
	// The hitbox of the classroom door
	Rectangle doorInRoomHitbox;
	Rectangle teacherDeskHitbox;
	vector<vector<Rectangle>> deskHitboxes;
	vector<Rectangle> doorsInHallHitboxes;
	vector<Rectangle> bookShelvesHitboxes;
	vector<Rectangle> sofasHitboxes;
	vector<Texture2D> doorsInHallTextures;
	vector <bool> isEachLevelPassed;
private:
	vector <Texture2D> rooms = {
	 LoadTexture("Graphics/hall.png"),
	 LoadTexture("Graphics/room.png")
	};
	vector<bool> DoorsInHallColliding;
	bool IsDoorInRoomColliding;
};