#include <iostream>
#include "raylib.h"
using namespace std;

float HEIGHT, WIDTH;
int main()
{
    InitWindow(200, 200, "tedo");
    ToggleFullscreen();

    SetTargetFPS(60);
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    Texture2D background, startGame, rules, quitGame;
    Vector2 mousePoint;
    Vector2 ballPosition = { -100.0f, -100.0f };
    bool exitGame = false;
    background = LoadTexture("../images/main_menu.png");
    while (!exitGame)
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawFPS(50, 50);

        ClearBackground(BLACK);

        DrawTexture(background, WIDTH / 38.4f, HEIGHT / 10.8f, WHITE);

        DrawCircleV(ballPosition, 10, MAROON);
            HideCursor();

        EndDrawing();

        SetExitKey(0);
    }
}