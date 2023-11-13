#pragma once
#include <iostream>
#include <random>
#include "raylib.h"
using namespace std;

extern float WIDTH;
extern float HEIGHT;
extern Vector2 ballPosition;
extern Vector2 mousePoint;


//Makes the size of the screen during the whole game and locks the FPS to 60
void init();

//Opens the game
void game();

//Open the rules menu
void rulesFunction();

//Open the main menu
void mainMenu();

//Selects a random question from questionsArr
void randomQuestion();

//Makes it impossible to have the same question twice
void removeQuestion();
 
//There are eight functions for the eight trahses which give the question
void taskTr1();
void taskTr2();
void taskTr3();
void taskTr4();
void taskTr5();
void taskTr6();
void taskTr7();
void taskTr8();


//The function which sends you to the game won menu
void gameWon();
