#include <iostream>
#include "raylib.h"
using namespace std;

float HEIGHT, WIDTH;
int main()
{
    InitWindow(0, 0, "Eco Pirates");
    ToggleFullscreen();

    SetTargetFPS(60);
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    Texture2D background, startGame, rules, quitGame;
    Vector2 mousePoint;
    Vector2 ballPosition = { -100.0f, -100.0f };
    bool exitGame = false;
    background = LoadTexture("../images/menubg.png");
    startGame = LoadTexture("../images/start.png");
    rules = LoadTexture("../images/rules.png");
    quitGame = LoadTexture("../images/quit.png");
    Rectangle startGameButton = { 820, 350, startGame.width, startGame.height };
    Rectangle rulesButton = { 820, 475, rules.width, rules.height };
    Rectangle quitGameButton = { 820, 600, quitGame.width, quitGame.height };
    while (!exitGame)
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawFPS(50, 50);

        ClearBackground(BLUE);

        DrawTexture(background, WIDTH / 38.4f, HEIGHT / 10.8f, WHITE);
        DrawTexture(startGame, 818, 300, WHITE);
        DrawTexture(rules, 822, 480, WHITE);
        DrawTexture(quitGame, 822, 660, WHITE);

        DrawCircleV(ballPosition, 10,BLACK);
            HideCursor();

        EndDrawing();

        SetExitKey(0);
    }
}