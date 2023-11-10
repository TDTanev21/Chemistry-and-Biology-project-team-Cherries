#include "main.h"

//variables for game()
Texture2D trash1 = LoadTexture("../images/bottle.png");
Texture2D trash2 = LoadTexture("../images/plasticBag.png");
Texture2D trash3 = LoadTexture("../images/trash.png");
Texture2D trash4 = LoadTexture("../images/spray.png");
Texture2D trash5 = LoadTexture("../images/foodTrash.png");
Texture2D trash6 = LoadTexture("../images/sodaCan.png");
Texture2D trash7 = LoadTexture("../images/tire.png");
Texture2D trash8 = LoadTexture("../images/notebook.png");
Texture2D ship = LoadTexture("../images/ship.png");
Rectangle trash1Colission = { 300, 200, trash1.width, trash1.height };
Rectangle trash2Colission = { 1500, 400, trash2.width, trash2.height };
Rectangle trash3Colission = { 150, 670, trash3.width, trash3.height };
Rectangle trash4Colission = { 350, 500, trash4.width, trash4.height };
Rectangle trash5Colission = { 1400, 100, trash5.width, trash5.height };
Rectangle trash6Colission = { 1700, 675, trash6.width, trash6.height };
Rectangle trash7Colission = { 600, 50, trash7.width, trash7.height };
Rectangle trash8Colission = { 1200, 175, trash8.width, trash8.height };
Texture2D bg = LoadTexture("../images/gamebg.png");
Rectangle bgRect[2] = { { 0, 0, bg.width, bg.height} , {0, -bg.height, bg.width, bg.height} };
float speed = 2;
double shipX = GetScreenHeight() / 2 + 245;
double shipY = 650;
Rectangle shipCollision = { shipX, shipY, ship.width, ship.height };



//variables for mainMenu()
bool exitGame = false;

Texture2D background = LoadTexture("../images/menubg.png");
Texture2D startGame = LoadTexture("../images/start.png");
Texture2D rules = LoadTexture("../images/rules.png");
Texture2D quitGame = LoadTexture("../images/quit.png");

Rectangle startGameButton = { 820, 350, startGame.width, startGame.height };
Rectangle rulesButton = { 820, 475, rules.width, rules.height };
Rectangle quitGameButton = { 820, 600, quitGame.width, quitGame.height };


//variables for rulesFunction()
Texture2D exitToGame = LoadTexture("../images/rulesToGame.png");
Texture2D rulesBackground = LoadTexture("../images/rulesbg.png");
Rectangle exitRulesButton = { 1635, 925, exitToGame.width, exitToGame.height };


//variables for question() and removeQuestion()
string questionsArr[5] = { "1","2", "3","4","5" };
string answers[5] = { "1", "2", "3", "4", "5" };
int questionsLength = 5;
string currentQuestion;


void game()
{
    SetExitKey(KEY_ESCAPE);
   
   
    while (!WindowShouldClose())
    {
        shipY += 0.5f;
        ballPosition = GetMousePosition();
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) shipX += 2.0f;
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) shipX -= 2.0f;
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))shipY -= 2.0f;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))shipY += 2.0f;
        if ((shipX + ship.width) > GetScreenWidth() + 150)
        {
            shipX = GetScreenWidth() - ship.width;
        }
        if ((shipX + ship.width) < 310)
        {
            shipX = 0;
        }
        if ((shipY + ship.height) >= GetScreenHeight() + 40)
        {
            shipY = GetScreenHeight() - ship.height;
        }
        if ((shipY + ship.height) < 350)
        {
            shipY = 0;
        }
        


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
        DrawTexture(trash2, 1500, 400, WHITE);
        DrawTexture(trash3, 150, 670, WHITE);
        DrawTexture(trash4, 350, 500, WHITE);
        DrawTexture(trash5, 1400, 100, WHITE);
        DrawTexture(trash6, 1700, 675, WHITE);
        DrawTexture(trash7, 600, 50,  WHITE);
        DrawTexture(trash8, 1200, 175, WHITE);

        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(BLUE);
        EndDrawing();
    }
}


void mainMenu()
{
    



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

void randomQuestion()
{  
        random_device(rd);
        uniform_int_distribution<int> dist(0, (questionsLength > 1) ? questionsLength - 1 : 1);
        currentQuestion = questionsArr[dist(rd)];
    
}
void removeQuestion()
{
    for (int i = 0; i < 14; i++)
    {
        if (questionsArr[i] == currentQuestion)
        {
            questionsLength -= 1;
            for (int j = i; j < questionsLength; j++)
            {
                questionsArr[j] = questionsArr[j + 1];
                answers[j] = answers[j + 1];
            }

        }
    }
}
