#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream> 

using namespace std;
int checkIfUserDataIsValid();
int checkIfGermanOrHackerDataIsValid();
void input(int numbers[], string hardOrEasy);
void numberGenerator(int germanNumbers[], string hardOrEasy);
string turnNumberIntoChar(int integerNumber);
string stringInseter(string fileName, int guessedNumbersOrPositions, int insertPosition);
void sortNumbers(int sortedNumbers[]);
int checkIfThreAreGuessedNumbers(int hackerNumbers[], int germanNumbers[]);
int checkIfThreAreGuessedNumbersAndPosition(int hackerNumbers[], int germanNumbers[]);
void playerVsPlayer(int hackerNumbers[], int germanNumbers[], string hardOrEasy);
void playerVsComputer(int hackerNumbers[], int germanNumbers[], string hardOrEasy);