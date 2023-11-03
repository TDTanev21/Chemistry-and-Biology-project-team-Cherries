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
    double shipX = GetScreenHeight() / 2 + 245;
    double shipY = 650;
    while (!WindowShouldClose())
    {
        shipY+= 0.5f;
        ballPosition = GetMousePosition();
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) shipX += 2.0f;
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) shipX -= 2.0f;
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))shipY -= 2.0f;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))shipY += 2.0f;


        BeginDrawing();

        for (int i = 0; i < 2; i++)
        {
            bgRect[i].y += speed;
            if ((bgRect[i].y) >= GetScreenHeight())
                bgRect[i].y = -bg.height;

            DrawTexture(bg, bgRect[i].x, bgRect[i].y, WHITE);
        }
        DrawFPS(50, 50);

        
        DrawTexture(ship, shipX, shipY, WHITE);
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(BLUE);
        EndDrawing();
    }
}
void rulesFunction()
{
    SetExitKey(KEY_ESCAPE);

    Vector2 ballPosition = { -100.0f, -100.0f };
    Vector2 mousePoint = { -100.0f, -100.0f };
    Texture2D exitToGame, exitToMenu;
    exitToGame = LoadTexture("../images/rulesToGame.png");
    exitToMenu = LoadTexture("../images/rulesToMenuButton.png");
    Rectangle exitRulesButton = { 1635, 925, exitToGame.width, exitToGame.height };
    while (!WindowShouldClose())
    {
        ballPosition = GetMousePosition();
        mousePoint = GetMousePosition();

        BeginDrawing();
        DrawText("press ESC to go back", 75, 915, 20, RED);
        DrawTexture(exitToGame, 1635, 925, WHITE);
        DrawRectangleLines(75, 85, 1580, 820, ORANGE);
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        DrawFPS(75, 50);
        DrawText("There were times when people decided to get better,", 100, 110, 50, YELLOW);
        DrawText("to change themselfest to a better reality and a ", 100, 160, 50, YELLOW);
        DrawText("different lifestyle, so that's why they all gathered  ", 100, 210, 50, YELLOW);
        DrawText("all the trash on the planet together and put them on", 100, 260, 50, YELLOW);
        DrawText(" a big recycling ship. But the big ship crashed on an ", 100, 310, 50, YELLOW);
        DrawText("ice berg and all the garbage went floating in the ocean.", 100, 360, 50, YELLOW);
        DrawText("Your task is to gather all the left overs of the trash ", 100, 410, 50, YELLOW);
        DrawText("by completing chemistry and biology problems and ", 100, 460, 50, YELLOW);
        DrawText("questions. Good luck saving the whole planet ECO pirate.", 100, 510, 50, YELLOW);
        DrawText("*hint*", 100, 700, 50, RED);
        DrawText("You should be very careful when choosing the right answer", 100, 770, 50, GREEN);
        DrawText("because you have 3 lifes only.", 100, 820, 50, GREEN);
        ClearBackground(BLUE);
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, exitRulesButton))
            game();

    }
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