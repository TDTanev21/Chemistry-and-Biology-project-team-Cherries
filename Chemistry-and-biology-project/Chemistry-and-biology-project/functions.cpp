#include "main.h"
void game()
{
    //variables for game()
    Texture2D trash1 = LoadTexture("../images/bottle.png");
    Texture2D trash2 = LoadTexture("../images/plasticBag.png");
    Texture2D trash3 = LoadTexture("../images/trash.png");
    Texture2D trash4 = LoadTexture("../images/spray.png");
    Texture2D trash5 = LoadTexture("../images/foodTrash.png");
    Texture2D trash6 = LoadTexture("../images/sodaCan.png");
    Texture2D trash7 = LoadTexture("../images/tire.png");
    Texture2D trash8 = LoadTexture("../images/notebook.png");
    Texture2D arrTrashes[8] = { trash1, trash2, trash3, trash4, trash5, trash6, trash7, trash8 };
    Texture2D ship = LoadTexture("../images/ship.png");
    double shipX = GetScreenHeight() / 2 + 245;
    double shipY = 650;
    Rectangle shipCollision = { shipX + 175, shipY + 26, ship.width / 2 - 175, ship.height / 2 };
    Rectangle trash1Collision = { 75, 165,  trash1.width, trash1.height };
    Rectangle trash2Collision = { 430, 160, trash2.width, trash2.height };
    Rectangle trash3Collision = { 625, 190,  trash3.width, trash3.height };
    Rectangle trash4Collision = { 828, 140, trash4.width, trash4.height };
    Rectangle trash5Collision = { 1022, 202, trash5.width, trash5.height };
    Rectangle trash6Collision = { 1223, 145, trash6.width, trash6.height };
    Rectangle trash7Collision = { 1425, 202, trash7.width, trash7.height };
    Rectangle trash8Collision = { 1625, 144, trash8.width, trash8.height };
    double trashPositionX = 300, trashPositionY = 200;
    Texture2D bg = LoadTexture("../images/gamebg.png");
    Rectangle bgRect[2] = { { 0, 0, bg.width, bg.height} , {0, -bg.height, bg.width, bg.height} };
    float speed = 2;
    

    

   
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
        if (CheckCollisionRecs(shipCollision, trash1Collision))
        {
            taskTr1();
        }
        if (CheckCollisionRecs(shipCollision, trash2Collision))
        {
            taskTr2();
        }
        if (CheckCollisionRecs(shipCollision, trash3Collision))
        {
            taskTr3();
        }
        if (CheckCollisionRecs(shipCollision, trash4Collision))
        {
            taskTr4();
        }
        if (CheckCollisionRecs(shipCollision, trash5Collision))
        {
            taskTr5();
        }
        if (CheckCollisionRecs(shipCollision, trash6Collision))
        {
            taskTr6();
        }
        if (CheckCollisionRecs(shipCollision, trash7Collision))
        {
            taskTr7();
        }
        if (CheckCollisionRecs(shipCollision, trash8Collision))
        {
            taskTr8();
        }


        shipCollision.x = shipX;
        shipCollision.y = shipY;

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
        for (int i = 0; i < 8; i++)
        {
            DrawTexture(arrTrashes[i], trashPositionX, trashPositionY, WHITE);
            trashPositionX += 200;
            trashPositionY += 50;

            if (i % 2 == 0)
            {
                trashPositionY -= 100;
            }
            if ((i + 1) % 8 == 0) 
            {
                trashPositionX = 225;
                trashPositionY = 200;
            }
            
            
        }
 
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(BLUE);

        EndDrawing();
    }
}


void mainMenu()
{
    //variables for mainMenu()
    bool exitGame = false;

    Texture2D background = LoadTexture("../images/menubg.png");
    Texture2D startGame = LoadTexture("../images/start.png");
    Texture2D rules = LoadTexture("../images/rules.png");
    Texture2D quitGame = LoadTexture("../images/quit.png");

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
    //variables for rulesFunction()
    Texture2D exitToGame = LoadTexture("../images/rulesToGame.png");
    Texture2D rulesBackground = LoadTexture("../images/rulesbg.png");
    Rectangle exitRulesButton = { 1635, 925, exitToGame.width, exitToGame.height };
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

void taskTr1()
{
   
   
        bool isAnswerTrue = false;
        
        const int screenWidth = 800;
        const int screenHeight = 450;
      

        char name[9 + 1] = "\0";      
        int letterCount = 0;

        Rectangle textBox = { GetScreenWidth()/2 - 150, 500, 350, 100 };
        bool mouseOnText = false;

        int framesCounter = 0;
        Texture2D submitAnswer = LoadTexture("../images/submitAnswer.png");
        Rectangle submitRec = { GetScreenWidth() / 2 - 115,700,submitAnswer.width,submitAnswer.height };

        SetTargetFPS(60);               
        
        while (!WindowShouldClose())
        {
            mousePoint = GetMousePosition();
            ballPosition = GetMousePosition();
            if (CheckCollisionPointRec(mousePoint, textBox)) mouseOnText = true;
            else mouseOnText = false;

            if (mouseOnText)
            {
                SetMouseCursor(MOUSE_CURSOR_IBEAM);

                int key = GetCharPressed();

                while (key > 0)
                {
                    if ((key >= 32) && (key <= 125) && (letterCount < 9))
                    {
                        name[letterCount] = (char)key;
                        name[letterCount + 1] = '\0';
                        letterCount++;
                    }

                    key = GetCharPressed();
                }

                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    letterCount--;
                    if (letterCount < 0) letterCount = 0;
                    name[letterCount] = '\0';
                }
            }
            else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

            if (mouseOnText) framesCounter++;
            else framesCounter = 0;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, submitRec))
            {
                for (int i = 0; i < letterCount; i++)
                {
                    if (name[i] == 'H' && name[i + 1] == '2' && name[i + 2] == 'O')
                    {
                        gameWon();
                    }
                }
            }
            BeginDrawing();
           
            ClearBackground(RAYWHITE);

            DrawText("Write down the molecular formula of two hydrogen atoms and one oxygen atom.", GetScreenWidth() / 2 - 800, 400, 40, GREEN);

            DrawRectangleRec(textBox, LIGHTGRAY);
            if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
            else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

            DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
            DrawTexture(submitAnswer, GetScreenWidth() / 2 -115, 700, WHITE);

            DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, 9), GetScreenWidth()/2 -75, 625, 20, GREEN);

            if (mouseOnText)
            {
                if (letterCount < 9)
                {
                    if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
                }
                else DrawText("Press BACKSPACE to delete chars...", GetScreenWidth() / 2 - 800, GetScreenHeight() / 2 - 300, 40, GREEN);
            }
            DrawCircleV(ballPosition, 10, BLACK);
            EndDrawing();
        }
}

void taskTr2()
{
  
    const int screenWidth = 800;
    const int screenHeight = 450;


    char name[9 + 1] = "\0";
    int letterCount = 0;

    Rectangle textBox = { GetScreenWidth() / 2 - 150, 500, 350, 100 };
    bool mouseOnText = false;

    int framesCounter = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            int key = GetCharPressed();

            while (key > 0)
            {
                if ((key >= 32) && (key <= 125) && (letterCount < 9))
                {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0';
                    letterCount++;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;
        BeginDrawing();
        DrawCircleV(ballPosition, 10, BLACK);

        ClearBackground(RAYWHITE);

        DrawText("Is the whale a mammal?(Yes/No question)", GetScreenWidth() / 2 - 600, GetScreenHeight() / 2 - 300, 40, GREEN);

        DrawRectangleRec(textBox, LIGHTGRAY);
        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, 9), GetScreenWidth() / 2 - 75, 625, 20, GREEN);

        if (mouseOnText)
        {
            if (letterCount < 9)
            {
                if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
            }
            else DrawText("Press BACKSPACE to delete chars...", GetScreenWidth() / 2 - 800, GetScreenHeight() / 2 - 300, 40, GREEN);
        }

        EndDrawing();

    }
}
void taskTr3()
{
    
    while(!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(WHITE);
        DrawText("What does this symbol means in chemistry: O?", GetScreenWidth() / 2- 600, GetScreenHeight() / 2 - 300, 40, GREEN);
        EndDrawing();
    }
}
void taskTr4()
{
   
    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(WHITE);
        DrawText("How many legs does the spider have?", GetScreenWidth() / 2, GetScreenHeight() / 2, 40, GREEN);
        EndDrawing();
    }
}
void taskTr5()
{
 
    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(WHITE);
        DrawText("What is the surface layer of the skin called?", GetScreenWidth() / 2- 600, GetScreenHeight() / 2- 300, 40, GREEN);
        EndDrawing();
    }
}
void taskTr6()
{
   
    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(WHITE);
        DrawText("What is the chemistry symbol for hydrogen?", GetScreenWidth() / 2 - 600, GetScreenHeight() / 2 - 300, 40, GREEN);
        EndDrawing();
    }
}
void taskTr7()
{

    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(WHITE);
        DrawText("Which element you should collide with when you are burning something?", GetScreenWidth() / 2 - 700, GetScreenHeight() / 2 - 300, 40, GREEN);
        EndDrawing();
    }
}
void taskTr8()
{
    
    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(WHITE);
        DrawText("How many chromosomes does the average human body have?", GetScreenWidth() / 2 - 600, GetScreenHeight() / 2, 40, RED);
        EndDrawing();
    }
}
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}


void gameWon()
{
    Texture2D gameWon = LoadTexture("../images/win.png");
    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        ballPosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(gameWon, 0, 0, WHITE);
        DrawCircleV(ballPosition, 10, BLACK);
        HideCursor();
        ClearBackground(WHITE);
        EndDrawing();
    }
}