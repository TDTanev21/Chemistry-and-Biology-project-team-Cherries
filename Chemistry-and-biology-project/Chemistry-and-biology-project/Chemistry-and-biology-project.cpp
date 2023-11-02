#include <iostream>
#include "raylib.h"
using namespace std;
void game()
{
    SetExitKey(KEY_ESCAPE);
    
    Texture2D ship;
    ship = LoadTexture("../images/ship.png");
    Vector2 ballPosition = { -100.0f, -100.0f };

    Texture2D bg = LoadTexture("../images/gamebg.png");
    Rectangle bgRect[2] = { { 0, 0, bg.width, bg.height} , {0, -bg.height, bg.width, bg.height} };
    float speed = 3;

    while (!WindowShouldClose())
    {
        ballPosition = GetMousePosition();

        BeginDrawing();

        for (int i = 0; i < 2; i++)
        {
            bgRect[i].y += speed;
            if ((bgRect[i].y) >= GetScreenHeight())
                bgRect[i].y = -bg.height;

            DrawTexture(bg, bgRect[i].x, bgRect[i].y, WHITE);
        }
        DrawFPS(50, 50);

        DrawTexture(ship, GetScreenWidth() / 3 + 110, 650, WHITE);
        
        DrawCircleV(ballPosition, 10, BLACK);

        HideCursor();
        ClearBackground(BLUE);
        EndDrawing();
    }
}
void rulesFunction()
{

}
float HEIGHT, WIDTH;
int main()
{
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    InitWindow(WIDTH, HEIGHT, "Eco Pirates");
    ToggleFullscreen();

    SetTargetFPS(60);
   
    Texture2D background,startGame, rules, quitGame;
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

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, startGameButton))
            game();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, rulesButton))
            rulesFunction();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, quitGameButton))
            exitGame = true;
    }
}