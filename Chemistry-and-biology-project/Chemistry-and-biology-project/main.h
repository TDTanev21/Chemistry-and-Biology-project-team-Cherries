#pragma once
#include <iostream>
#include "raylib.h"
using namespace std;

extern float WIDTH;
extern float HEIGHT;
extern Vector2 ballPosition;
extern Vector2 mousePoint;

void init();

void game();

void rulesFunction();
 
void mainMenu();

