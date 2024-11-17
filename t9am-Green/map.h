#pragma once
#include "raylib.h"
#include <vector>
#include "mapHItbox.h"
#include "teacher.h"
using namespace std;

class Map {
public:
	Map();
	// Draws the map with it's elements on the screen
	void Draw();
	// Updates the door texture when colliding with the player
	void UpdateDoor(Rectangle CollidingObject);
	// Returns the door number of the door with which the player collides
	int CheckWhichDoorIsColliding(Rectangle collidingObject);
	// Changes the room and updates player's position according the door he used so that he is next to that door
	void ChangeTheRoom(int DoorNumber, Rectangle &Character);
	// Checks if the door the player uses any of the doors
	void CheckIfDoorIsUsed(Rectangle &character);
	// Tracks the player in the hall
	void TrackCharacter(Rectangle character);
	// Calls the hitbox() function from the teacher.h file with the needed parameters
	void TeacherHitbox(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec);
	// Used automaticly initialize the hitboxes of all the doors in the hall 
	vector <Rectangle> initializeDoorsHitboxes(int numberOfDoors);
	// Automaticly initializes the textures of all the doors in the hall
	vector <Texture2D> initializeDoorsTextures(int numberOfDoors);
	// Automaticly initializes the hitboxes of all the desks and sorts the into a vector of vectors
	vector<vector <Rectangle>> initializeDesksHitboxes(int rows, int columns);
	// Checks for collisions between the player and the desks. Doesn't let the player to go through them
	void DesksHitboxes(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec);
	//The hall position along X axis. It is in a separated variable because it will change as the character is moving in the hall 
	int hallXPosition;
	//Contains how much pixels did the hall position change compared to its initial position
	int hallPositionOffset;
	// The texture of the current room. It will change along with the currentRoomID variable
    Texture2D CurrentRoomTexture;
	// The texture of the door when it isn't colliding with the player
	Texture2D doorNotCollidingTexture;
	// The texture of the door when it is colliding with the player
	Texture2D doorCollidingTexture;
	// The current door texture that will get the doorNotCollidingTexture or doorCollidingTexture value
	Texture2D doorCurrentTexture;
	// The desk texture
	Texture2D deskTexture;
	// The hitbox of the classroom door
	Rectangle doorInRoomHitbox;
	// The hitboxes of all the desks
	vector<vector<Rectangle>> deskHitboxes;
	// The hitboxes of all the doors in the hall
	vector<Rectangle> doorsInHallHitboxes;
	// The textires of all the doors in the hall
	vector<Texture2D> doorsInHallTextures;
	// Creating a map hitbox object
	MapHitbox mapHitbox;
private:
	//Each room has an ID - ID 1 for the hall, ID 2 for the first classroom, ID 3 for the second classroom and so on
	int currentRoomID;
	//There are only two room textures - the hall and a classroom
	vector <Texture2D> rooms = {
     LoadTexture("Graphics/hall.png"),
	 LoadTexture("Graphics/room.png")
	};
	// Creating a teacher object
	Teacher teacher;
};