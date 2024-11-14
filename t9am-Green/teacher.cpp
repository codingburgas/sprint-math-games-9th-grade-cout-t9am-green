#include "teacher.h"

Teacher::Teacher()
{
	texture = LoadTexture("Graphics/TeacherTexture.png");


}

void Teacher::Draw()
{
	DrawTexture(texture, GetScreenWidth() / 2 + (GetScreenWidth() / 2) / 2, GetScreenHeight() / 2, WHITE);
}
