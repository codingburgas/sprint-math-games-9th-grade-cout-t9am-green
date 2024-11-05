#include "map.h"

Map::Map() {
	mapTexture = LoadTexture("Graphics/map1.png"); //Contains the map texture
	doorTexture = LoadTexture("Graphics/door1.png"); //Contains the door texture
	door = { 500, 70, (float)doorTexture.width, (float)doorTexture.height + 50.f };
}

void Map::Draw() { //Draws the map with its elements on the screen

DrawTexture(mapTexture, 0, 0, WHITE); //Draws the map on the screen
DrawTexture(doorTexture, door.x, door.y, WHITE); //Draws the door on the screen

}


