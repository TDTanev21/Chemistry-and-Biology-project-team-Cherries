#include "main.h"
float WIDTH = GetScreenWidth();
float HEIGHT = GetScreenHeight();
Vector2 ballPosition = { -100.0f, -100.0f };
Vector2 mousePoint = { -100.0f, -100.0f };
int counter = 3;

void init()
{
	
	InitWindow(WIDTH, HEIGHT, "Eco Pirates");
	ToggleFullscreen();

	SetTargetFPS(60);
}