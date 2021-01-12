#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream> 

using namespace std;
void greeting();
int tableColor(int guestParameters);
void displayErrorMessage();
void systemClear();
void highscore();
void filesOutput(string fileName, int lineNumber, bool isThereASkip = false, int lineSkipNumber = 0);
void livesDisplayer(int lives);
bool difficultyMenu(int hackerNumbers[], int germanNumbers[], string humarOrBot);
bool levelMenu(int hackerNumbers[], int germanNumbers[]);
bool mainMenu(int hackerNumbers[], int germanNumbers[]);
