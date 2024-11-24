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
	lockedPadlock = LoadTexture("Graphics/lockTextureClosed.png");
	unlockedPadlock = LoadTexture("Graphics/lockTextureOpened.png");
	teacherDesk = LoadTexture("Graphics/TeacherDesk.png");
	eButton1 = LoadTexture("Graphics/E-button1.png");
	sofaTexture = LoadTexture("Graphics/sofa.png");
	board = LoadTexture("Graphics/board.png");
	paintingsTextures = {
		LoadTexture("Graphics/painting1.png"),
		LoadTexture("Graphics/painting2.png"),
		LoadTexture("Graphics/painting3.png"),
		LoadTexture("Graphics/painting4.png")
	};
	doorInRoomHitbox = { 170.f, 70.f, (float)doorNotCollidingTexture.width, (float)doorNotCollidingTexture.height };
	doorsInHallHitboxes = InitializeDoorsHitboxes(5);
	doorsInHallTextures = InitializeDoorsTextures(5);
	bookShelvesHitboxes = InitializeBookshelvesHitboxes();
	sofasHitboxes = InitSofasHitboxes();
	teacherDeskHitbox = { (float)GetScreenWidth() - mapHitbox.rightBound.width - teacherDesk.width - 5, (float)GetScreenHeight() / 2 - teacherDesk.height - 15, (float)teacherDesk.width, (float)teacherDesk.height - 40 };
	isEachLevelPassed = {
		true,
		false,
		false,
		false,
		false,
		false
	};
	DoorsInHallColliding = {
		false,
		false,
		false,
		false,
		false
	};
	IsDoorInRoomColliding = false;
}

//Draws different rooms according to the currentRoomID variable
void Map::Draw() { 
	switch (currentRoomID) {
	case 1:
		DrawTexture(CurrentRoomTexture, hallXPosition, 0, WHITE);
		for (int i = 0; i < doorsInHallHitboxes.size(); i++) {
			if (DoorsInHallColliding[i]) {
				DrawTexture(eButton1, (int)doorsInHallHitboxes[i].x + (int)doorCollidingTexture.width + 5, (int)doorsInHallHitboxes[i].y, WHITE);
			}
		}
		for (int i = 0; i < doorsInHallHitboxes.size(); i++) {
			DrawText("Level ", doorsInHallHitboxes[i].x - 10, doorsInHallHitboxes[i].y + 10, 10, { 192, 209, 121, 255 });
			DrawTexture(doorsInHallTextures[i], (int)doorsInHallHitboxes[i].x, (int)doorsInHallHitboxes[i].y, WHITE);
			if (isEachLevelPassed[i])
				DrawTexture(unlockedPadlock, (int)doorsInHallHitboxes[i].x - (int)unlockedPadlock.width - 5, (int)doorsInHallHitboxes[i].y, WHITE);
			else
				DrawTexture(lockedPadlock, (int)doorsInHallHitboxes[i].x - (int)unlockedPadlock.width - 5, (int)doorsInHallHitboxes[i].y, WHITE);
		}

		for (int i = 0; i < bookShelvesHitboxes.size(); i++) {
			DrawTexture(bookshelfTexture, (int)bookShelvesHitboxes[i].x, (int)bookShelvesHitboxes[i].y, WHITE);
		}
		deskHitboxes = InitializeDesksHitboxes(0, 0);
		DrawTexture(paintingsTextures[0], (int)doorsInHallHitboxes[0].x + (int)doorsInHallHitboxes[0].width + 70, (int)doorsInHallHitboxes[0].y - 10, WHITE);
		DrawTexture(paintingsTextures[1], (int)doorsInHallHitboxes[1].x + (int)doorsInHallHitboxes[1].width + 70, (int)doorsInHallHitboxes[1].y - 10, WHITE);
		DrawTexture(paintingsTextures[2], (int)doorsInHallHitboxes[2].x + (int)doorsInHallHitboxes[2].width + 175, (int)doorsInHallHitboxes[2].y - 10, WHITE);
		DrawTexture(paintingsTextures[3], (int)doorsInHallHitboxes[3].x + (int)doorsInHallHitboxes[3].width + 70, (int)doorsInHallHitboxes[3].y - 10, WHITE);
		for (int i = 0; i < sofasHitboxes.size(); i++) {
			DrawTexture(sofaTexture, (int)sofasHitboxes[i].x, (int)sofasHitboxes[i].y, WHITE);
		}
		break;
	default:
		DrawTexture(CurrentRoomTexture, 0, 0, WHITE);
		if (IsDoorInRoomColliding)
			DrawTexture(eButton1, (int)doorInRoomHitbox.x + (int)doorCollidingTexture.width + 5, (int)doorInRoomHitbox.y, WHITE);
		DrawTexture(doorCurrentTexture, (int)doorInRoomHitbox.x, (int)doorInRoomHitbox.y, WHITE);

		deskHitboxes = InitializeDesksHitboxes(2, 5);
		for (int i = 0; i < deskHitboxes.size(); i++) {
			for (int j = 0; j < deskHitboxes[0].size(); j++)
				DrawTexture(deskTexture, (int)deskHitboxes[i][j].x - 15, (int)deskHitboxes[i][j].y, WHITE);
		}
		teacher.Draw(currentRoomID - 1);
		DrawTexture(teacherDesk, (int)teacherDeskHitbox.x, (int)teacherDeskHitbox.y, WHITE);
		DrawTexture(board, (int)teacherDeskHitbox.x - board.width - 10, 60, WHITE);
		teacher.DrawEButton();
	}
}

//Updates the door texture if it is colliding with the character
void Map::UpdateDoor(Rectangle CollidingObject) 
{
	if (currentRoomID == 1) {
		for (int i = 0; i < doorsInHallHitboxes.size(); i++) {
			if (CheckCollisionRecs(CollidingObject, doorsInHallHitboxes[i]) and isEachLevelPassed[i]) {
				doorsInHallTextures[i] = doorCollidingTexture;
				DrawTexture(eButton1, (int)doorsInHallHitboxes[i].x + (int)doorCollidingTexture.width + 5, (int)doorsInHallHitboxes[i].y, WHITE);
				DoorsInHallColliding[i] = true;
			}
			else {
				doorsInHallTextures[i] = doorNotCollidingTexture;
				DoorsInHallColliding[i] = false;
			}
		}
	}
	else if (currentRoomID > 1 and currentRoomID <= 6) {
		if (CheckCollisionRecs(CollidingObject, doorInRoomHitbox)) {
			doorCurrentTexture = doorCollidingTexture;
			IsDoorInRoomColliding = true;
		}
		else {
			doorCurrentTexture = doorNotCollidingTexture;
			IsDoorInRoomColliding = false;
		}
	}
}

//Checks with which door the character is colliding and returns the number of that door. If there are no collisions it returns 0
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

//Changes the current room texture and the currentRoomID and also moves the character so that he is next to the current door
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
	if (doorNumber != 0 and IsKeyPressed(KEY_E) and isEachLevelPassed[doorNumber - 1]) {
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
				for (int i = 0; i < sofasHitboxes.size(); i++)
					sofasHitboxes[i].x += 13;
				hallPositionOffset -= 13;
			}
		}
		//Moves the hall right if the player tries to go left
		else if (CheckCollisionRecs(character, rightBoundForTracking) and IsKeyDown(KEY_D)) {
			if (hallPositionOffset < rooms[0].width - ((float)mapHitbox.rightBound.width + 30 + (GetScreenWidth() - mapHitbox.leftBound.width))) {
				hallXPosition -= 13;
				for (int i = 0; i < doorsInHallHitboxes.size(); i++)
					doorsInHallHitboxes[i].x -= 13;
				for (int i = 0; i < bookShelvesHitboxes.size(); i++)
					bookShelvesHitboxes[i].x -= 13;
				for (int i = 0; i < sofasHitboxes.size(); i++)
					sofasHitboxes[i].x -= 13;
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
vector<Rectangle> Map::InitializeDoorsHitboxes(int numberOfDoors)
{
	vector<Rectangle> doors;
	
	for (int i = 0; i < numberOfDoors; i++)
		doors.insert(doors.end(), { (float)doorInRoomHitbox.x + (float)500*i, (float)doorInRoomHitbox.y, (float)doorInRoomHitbox.width, (float)doorInRoomHitbox.height});
	return doors;
}

//Initializes the vector with the textures of the doors in the hall
vector<Texture2D> Map::InitializeDoorsTextures(int numberOfDoors)
{
	vector<Texture2D> textures;

	for (int i = 0; i < numberOfDoors; i++)
		textures.insert(textures.end(), doorNotCollidingTexture);
	return textures;
}

// Initializes the hitboxes of all the desks
vector<vector<Rectangle>> Map::InitializeDesksHitboxes(int rows, int columns)
{
	Rectangle firstDesk = { (float)mapHitbox.leftBound.width  + 10.f, (float)mapHitbox.upperBound.height + 90.f, (float)deskTexture.width, deskTexture.height - 5.f };
	vector<vector<Rectangle>> hitboxes;

	for (int i = 0; i < rows; i++) {
		hitboxes.push_back({});
		for (int j = 0; j < columns; j++)
			hitboxes[i].push_back({(float)firstDesk.x + (float)deskTexture.width * j + (float)j * 45 + 15.f, (float)firstDesk.y + 5.f, (float)deskTexture.width - 20.f, (float)deskTexture.height - 40.f});
		firstDesk.y += firstDesk.height + 40;
	}
	return hitboxes;
}

// Initializes the bookshelves hitboxes automatically
vector<Rectangle> Map::InitializeBookshelvesHitboxes() {

	vector <Rectangle> hitboxes;

	hitboxes.push_back({ (float)doorsInHallHitboxes[0].x + doorsInHallHitboxes[0].width + 300.f, (float)doorInRoomHitbox.y - 15, (float)bookshelfTexture.width, (float)bookshelfTexture.height - 40 });
	hitboxes.push_back({ (float)doorsInHallHitboxes[1].x + doorsInHallHitboxes[1].width + 300.f, (float)doorInRoomHitbox.y - 15, (float)bookshelfTexture.width, (float)bookshelfTexture.height - 40 });
	hitboxes.push_back({ (float)doorsInHallHitboxes[3].x + doorsInHallHitboxes[3].width + 300.f, (float)doorInRoomHitbox.y - 15, (float)bookshelfTexture.width, (float)bookshelfTexture.height - 40 });

	return hitboxes;
}

vector<Rectangle> Map::InitSofasHitboxes() {
	vector <Rectangle> hitboxes;

	hitboxes.push_back({ (float)bookShelvesHitboxes[0].x - sofaTexture.width - 50.f, (float)doorInRoomHitbox.y, (float)sofaTexture.width, (float)sofaTexture.height - 30 });
	hitboxes.push_back({ (float)bookShelvesHitboxes[1].x - sofaTexture.width - 50.f, (float)doorInRoomHitbox.y, (float)sofaTexture.width, (float)sofaTexture.height - 30 });
	hitboxes.push_back({ (float)doorsInHallHitboxes[2].x + doorsInHallHitboxes[2].width + 75.f, (float)doorInRoomHitbox.y, (float)sofaTexture.width, (float)sofaTexture.height - 30 });
	hitboxes.push_back({ (float)doorsInHallHitboxes[3].x - sofaTexture.width - 100.f, (float)doorInRoomHitbox.y, (float)sofaTexture.width, (float)sofaTexture.height - 30 });
	hitboxes.push_back({ (float)bookShelvesHitboxes[2].x - sofaTexture.width - 10.f, (float)doorInRoomHitbox.y, (float)sofaTexture.width, (float)sofaTexture.height - 30 });

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

void Map::SofasHitboxes(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec) {
	bool CharacterIsColliding = false;
	for (int i = 0; i < sofasHitboxes.size(); i++) {
		if (CheckCollisionRecs(CharacterNextRec, sofasHitboxes[i]) and currentRoomID == 1) {
			CharacterIsColliding = true;
		}
		if (CharacterIsColliding)
			CharacterNextRec = CharacterCurrentRec;
	}
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

void Map::CheckIfLevelPassed(int currentLevel, int teacherHealth) {
	if (teacherHealth <= 0)
		isEachLevelPassed[currentLevel] = true;
}

void Map::CheckCollidingTeacherDesk(Rectangle& CharacterCurrentRec, Rectangle& CharacterNextRec){
	if (CheckCollisionRecs(teacherDeskHitbox, CharacterNextRec))
		CharacterNextRec = CharacterCurrentRec;
}