#include "map.h"

Map::Map() {
	hallPositionOffset = 0;
	hallXPosition = 0;
	currentRoomID = 1;
	CurrentRoomTexture = rooms[0];
	doorNotCollidingTexture = LoadTexture("Graphics/Door.png");
	doorCollidingTexture = LoadTexture("Graphics/DoorColliding.png");
	deskTexture = LoadTexture("Graphics/desk.png");
	doorCurrentTexture = doorNotCollidingTexture;
	bookshelfTexture = LoadTexture("Graphics/BookShelf.png");
	doorInRoomHitbox = { 170, 70, (float)doorNotCollidingTexture.width, (float)doorNotCollidingTexture.height };
	doorsInHallHitboxes = initializeDoorsHitboxes(5);
	doorsInHallTextures = initializeDoorsTextures(5);
	bookShelvesHitboxes = initializeBookshelvesHitboxes(4);
}

//Draws different rooms according to the currentRoomID variable
void Map::Draw() { 
	switch (currentRoomID) {
	case 1:
		DrawTexture(CurrentRoomTexture, hallXPosition, 0, WHITE);
		for (int i = 0; i < doorsInHallHitboxes.size(); i++) {
			DrawTexture(doorsInHallTextures[i], doorsInHallHitboxes[i].x, doorsInHallHitboxes[i].y, WHITE);
		}
		for (int i = 0; i < bookShelvesHitboxes.size(); i++) {
			DrawTexture(bookshelfTexture, bookShelvesHitboxes[i].x, bookShelvesHitboxes[i].y, WHITE);
			DrawTexture(bookshelfTexture, bookShelvesHitboxes[i].x + bookshelfTexture.width + 10, bookShelvesHitboxes[i].y, WHITE);
		}
		deskHitboxes = initializeDesksHitboxes(0, 0);
		break;
	default:
		DrawTexture(CurrentRoomTexture, 0, 0, WHITE);
		DrawTexture(doorCurrentTexture, doorInRoomHitbox.x, doorInRoomHitbox.y, WHITE);
		switch (currentRoomID)
		{
		case 2:
			deskHitboxes = initializeDesksHitboxes(2, 5);
			for (int i = 0; i < deskHitboxes.size(); i++) {
				for (int j = 0; j < deskHitboxes[0].size(); j++)
					DrawTexture(deskTexture, deskHitboxes[i][j].x - 15, deskHitboxes[i][j].y, WHITE);
			}
			break;
		}
		teacher.Draw();
	}
}

//Updates the door texture if it is colliding with the character
void Map::UpdateDoor(Rectangle CollidingObject) 
{
	if (currentRoomID == 1) {
		for (int i = 0; i < doorsInHallHitboxes.size(); i++) {
			if (CheckCollisionRecs(CollidingObject, doorsInHallHitboxes[i]))
				doorsInHallTextures[i] = doorCollidingTexture;
			else
				doorsInHallTextures[i] = doorNotCollidingTexture;
		}
	}
	else if (currentRoomID > 1 and currentRoomID <= 6) {
		if (CheckCollisionRecs(CollidingObject, doorInRoomHitbox))
			doorCurrentTexture = doorCollidingTexture;
		else
			doorCurrentTexture = doorNotCollidingTexture;
	}
}

//Checks with which door the character is colliding and returns the number of that door. If there are no collisions it
//returns 0
int Map::CheckWhichDoorIsColliding(Rectangle collidingObject)
{
	if (currentRoomID != 1) {
		if (CheckCollisionRecs(doorInRoomHitbox, collidingObject))
			return 1;
	}
	else {
		for (int i = 1; i <= doorsInHallHitboxes.size(); i++) {
			if (CheckCollisionRecs(doorsInHallHitboxes[i - 1], collidingObject))
				return i;
		}
	}
	return 0;
}

//Changes the current room texture and the currentRoomID and also oves the character so that he is next to the current door
void Map::ChangeTheRoom(int doorNumber, Rectangle &Character)
{

	switch (currentRoomID)
	{
	case 1:
		CurrentRoomTexture = rooms[1];
		Character.x = doorInRoomHitbox.x;
		if (doorNumber == 1) {
			currentRoomID = 2;
		}
		else if (doorNumber == 2){
			currentRoomID = 3;
		}
		else if (doorNumber == 3){
			currentRoomID = 4;
		}
		else if (doorNumber == 4){
			currentRoomID = 5;
		}
		else if (doorNumber == 5){
			currentRoomID = 6;
		}
		break;
	case 2:
		CurrentRoomTexture = rooms[0];
		Character.x = doorsInHallHitboxes[currentRoomID - 2].x;
		currentRoomID = 1;
		break;
	case 3:
		CurrentRoomTexture = rooms[0];
		Character.x = doorsInHallHitboxes[currentRoomID - 2].x;
		currentRoomID = 1;
		break;
	case 4:
		CurrentRoomTexture = rooms[0];
		Character.x = doorsInHallHitboxes[currentRoomID - 2].x;
		currentRoomID = 1;
		break;
	case 5:
		CurrentRoomTexture = rooms[0];
		Character.x = doorsInHallHitboxes[currentRoomID - 2].x;
		currentRoomID = 1;
		break;
	case 6:
		CurrentRoomTexture = rooms[0];
		Character.x = doorsInHallHitboxes[currentRoomID - 2].x;
		currentRoomID = 1;
		break;
	}
}

//Changes the room if the player presses 'E' while colliding with the door 
void Map::CheckIfDoorIsUsed(Rectangle& character)
{
	int doorNumber = CheckWhichDoorIsColliding(character);
	if (doorNumber != 0 and IsKeyPressed(KEY_E)) {
		ChangeTheRoom(doorNumber, character);
	}
	
}

//Tracks where the player goes when he is in the hall
void Map::TrackCharacter(Rectangle character) {
	if (currentRoomID == 1) {
		//These bounds are used to track when the hall position should change. They are a little bigger than the mapHitbox
		//bounds
		Rectangle leftBoundForTracking{ mapHitbox.leftBound.width, mapHitbox.upperBound.height, 15, mapHitbox.leftBound.height };
		Rectangle rightBoundForTracking { 900 - mapHitbox.rightBound.width - 15, mapHitbox.upperBound.height, 15, mapHitbox.rightBound.height };
		
		//Moves the hall left if the player tries to go right
		if (CheckCollisionRecs(character, leftBoundForTracking) and IsKeyDown(KEY_A)) {
			if (hallPositionOffset != 0) {
				hallXPosition += 13;
				for (int i = 0; i < doorsInHallHitboxes.size(); i++)
					doorsInHallHitboxes[i].x += 13;
				for (int i = 0; i < bookShelvesHitboxes.size(); i++)
					bookShelvesHitboxes[i].x += 13;
				hallPositionOffset -= 13;
			}
		}
		//Moves the hall right if the player tries to go left
		else if (CheckCollisionRecs(character, rightBoundForTracking) and IsKeyDown(KEY_D)) {
			if (hallPositionOffset < rooms[0].width - (mapHitbox.rightBound.width + 30 + (GetScreenWidth() - mapHitbox.leftBound.width))) {
				hallXPosition -= 13;
				for (int i = 0; i < doorsInHallHitboxes.size(); i++)
					doorsInHallHitboxes[i].x -= 13;
				for (int i = 0; i < bookShelvesHitboxes.size(); i++)
					bookShelvesHitboxes[i].x -= 13;
				hallPositionOffset += 13;
			}
		}
	}
}

// Calls the hitbox function from the teacher.h file to pass it needed values
void Map::TeacherHitbox(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec) {
	if (currentRoomID != 1)
	teacher.Hitbox(CharacterCurrentRec, CharacterNextRec);
}

//Initializes the vector with the hitboxes of the doors in the hall
vector<Rectangle> Map::initializeDoorsHitboxes(int numberOfDoors)
{
	vector<Rectangle> doors;
	
	for (int i = 0; i < numberOfDoors; i++)
		doors.insert(doors.end(), { doorInRoomHitbox.x + 500*i, doorInRoomHitbox.y, doorInRoomHitbox.width, doorInRoomHitbox.height});
	return doors;
}

//Initializes the vector with the textures of the doors in the hall
vector<Texture2D> Map::initializeDoorsTextures(int numberOfDoors)
{
	vector<Texture2D> textures;

	for (int i = 0; i < numberOfDoors; i++)
		textures.insert(textures.end(), doorNotCollidingTexture);
	return textures;
}

// Initializes the hitboxes of all the desks
vector<vector<Rectangle>> Map::initializeDesksHitboxes(int rows, int columns)
{
	Rectangle firstDesk = { (float)mapHitbox.leftBound.width  + 10, (float)mapHitbox.upperBound.height + 90, (float)deskTexture.width, deskTexture.height - 5 };
	vector<vector<Rectangle>> hitboxes;

	for (int i = 0; i < rows; i++) {
		hitboxes.push_back({});
		for (int j = 0; j < columns; j++)
			hitboxes[i].push_back({(float)firstDesk.x + deskTexture.width * j + j * 45 + 15.f, (float)firstDesk.y + 5, (float)deskTexture.width - 20.f, (float)deskTexture.height - 30});
		firstDesk.y += firstDesk.height + 40;
	}
	return hitboxes;
}

// Initializes the bookshelves hitboxes automatically
vector<Rectangle> Map::initializeBookshelvesHitboxes(int numberOfBookshelves) {

	Rectangle firstHitbox = { doorInRoomHitbox.x + doorNotCollidingTexture.width + 250 - bookshelfTexture.width - 5, doorInRoomHitbox.y - 10, bookshelfTexture.width, bookshelfTexture.height - 35 };
	vector <Rectangle> hitboxes;

	for (int i = 0; i < numberOfBookshelves; i++) {
		hitboxes.push_back({ firstHitbox.x + 500 * i - 25, firstHitbox.y, firstHitbox.width*2 + 10, firstHitbox.height });
		
	}

	return hitboxes;
}

// Checks for collisions between the player and any of the desks
void Map::DesksHitboxes(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec) {
	bool CharacterIsColliding = false;
	for (int row = 0; row < deskHitboxes.size(); row++) {
		for (int column = 0; column < deskHitboxes[0].size(); column++) {
			if (CheckCollisionRecs(CharacterNextRec, deskHitboxes[row][column]))
				CharacterIsColliding = true;
		}
	}
	if (CharacterIsColliding)
		CharacterNextRec = CharacterCurrentRec;
}

// Handles the collisions between the player and the bookshelves
void Map::BookshelvesHitboxes(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec) {
	bool CharacterIsColliding = false;
	for (int i = 0; i < bookShelvesHitboxes.size(); i++) {
		if (CheckCollisionRecs(CharacterNextRec, bookShelvesHitboxes[i]) and currentRoomID == 1)
			CharacterIsColliding = true;
	}
	
	if (CharacterIsColliding)
		CharacterNextRec = CharacterCurrentRec;
}
