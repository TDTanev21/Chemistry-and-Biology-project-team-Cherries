#include "main.h"

void game()
{
    SetExitKey(KEY_ESCAPE);
   
    Texture2D trash1 = LoadTexture("../images/bottle.png");
    Texture2D trash2 = LoadTexture("../images/plasticBag.png");
    Texture2D trash3 = LoadTexture("../images/trash.png");
    Texture2D trash4 = LoadTexture("../images/spray.png");
    Texture2D trash5 = LoadTexture("../images/foodTrash.png");
    Texture2D trash6 = LoadTexture("../images/sodaCan.png");
    Texture2D ship = LoadTexture("../images/ship.png");
    ballPosition = { -100.0f, -100.0f };
    Texture2D bg = LoadTexture("../images/gamebg.png");
    Rectangle bgRect[2] = { { 0, 0, bg.width, bg.height} , {0, -bg.height, bg.width, bg.height} };
    float speed = 2;
    double shipX = GetScreenHeight() / 2 + 245;
    double shipY = 650;
    while (!WindowShouldClose())
    {
        shipY += 0.5f;
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
        DrawTexture(trash1, 300, 200, WHITE);
        DrawTexture(trash2, 1600, 400, WHITE);
        DrawTexture(trash3, 250, 670, WHITE);
        DrawTexture(trash4, 750, 500, WHITE);
        DrawTexture(trash5, 1800, 100, WHITE);
        DrawTexture(trash6, 1200, 575, WHITE);

        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(BLUE);
        EndDrawing();
    }
}


void mainMenu()
{
    Texture2D background, startGame, rules, quitGame;
    ballPosition = { -100.0f, -100.0f };
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

        DrawCircleV(ballPosition, 10, BLACK);
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


void rulesFunction()
{
    SetExitKey(KEY_ESCAPE);

    
    Texture2D exitToGame;
    Texture2D rulesBackground;

    exitToGame = LoadTexture("../images/rulesToGame.png");
    rulesBackground = LoadTexture("../images/rulesbg.png");

    Rectangle exitRulesButton = { 1635, 925, exitToGame.width, exitToGame.height };


    while (!WindowShouldClose())
    {
        ballPosition = GetMousePosition();
        mousePoint = ballPosition;

        BeginDrawing();
        DrawTexture(rulesBackground, 0, 0, WHITE);
        DrawText("press ESC to go back", 75, 915, 20, RED);
        DrawTexture(exitToGame, 1635, 925, WHITE);
        DrawRectangleLines(180, 160, 1500, 750, ORANGE);
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        DrawFPS(75, 50);
        DrawText("There were times when people decided to get better,", 190, 165, 50, WHITE);
        DrawText("to change themselves to a better reality and a ", 190, 215, 50, WHITE);
        DrawText("different lifestyle, so that's why they all gathered  ", 190, 265, 50, WHITE);
        DrawText("all the trash on the planet together and put them on", 190, 315, 50, WHITE);
        DrawText("a big recycling ship. But the big ship crashed on an ", 190, 365, 50, WHITE);
        DrawText("ice berg and all the garbage went floating in the ocean.", 190, 415, 50, WHITE);
        DrawText("Your task is to gather all the left overs of the trash ", 190, 465, 50, WHITE);
        DrawText("by completing chemistry and biology problems and ", 190, 515, 50, WHITE);
        DrawText("questions. Good luck saving the whole planet ECO pirate.", 190, 565, 50, WHITE);
        DrawText("*hint*", 190, 665, 50, RED);
        DrawText("You should be very careful when choosing the right", 190, 765, 50, WHITE);
        DrawText("answer because you have 3 lifes only.", 190, 825, 50, WHITE);
        ClearBackground(BLUE);
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, exitRulesButton))
            game();

    }
}

