#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <sstream> 
#include <conio.h>
#include "Data Layer.h"

using namespace std;

void filesOutput(string fileName, int lineNumber, bool isThereASkip = false, int lineSkipNumber = 0) {
    ifstream file(fileName);
    string sLine;
    if (isThereASkip)
    {
        for (int i = 0; i < lineSkipNumber; i++) // skips lines
        {
            getline(file, sLine);
        }
        for (int i = 0; i < lineNumber; i++)
        {
            getline(file, sLine);
            cout << sLine << endl;
        }
        file.close();
    }
    else {
        for (int i = 0; i < lineNumber; i++)
        {
            getline(file, sLine);
            cout << sLine << endl;
        }
        file.close();
    }
}

void greeting() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    filesOutput("textFiles/Greating!.txt", 20);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

int tableColor(int guessedParameters) {
    if (guessedParameters == 0)
    {
        return 4;
    }
    else if (guessedParameters == 1)
    {
        return 12;
    }
    else if (guessedParameters == 2)
    {
        return 14;
    }
    else if (guessedParameters == 3)
    {
        return 10;
    }
    else if (guessedParameters == 4)
    {
        return 1;
    }
    return 11;
}

void displayErrorMessage() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Error! Incorect input. Try again!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void systemClear() {
    system("CLS");
}

void highscore() {
    string sLine;
    fstream file("HighScore/Highscore.txt");
    getline(file, sLine); // read the first line

    stringstream intValue(sLine);
    int number;
    intValue >> number; // changes the text into a number
    number++;

    stringstream ss;
    ss << number; // changes the number into a text
    string str = ss.str();
    file.seekg(0, ios::beg);
    file << str;
    file.close();
}

void displayLives(int lives)
{
    for (int i = 0; i < lives; i++)
    {
        cout << "<3  ";
    }
    cout << endl;
}

bool difficultyMenu(int hackerNumbers[], int germanNumbers[], string humanOrBot)
{
    cout << endl;
    filesOutput("textFiles/Menu's Text.txt", 2, true, 9);
    cout << endl;
    string hardOrEasy;
    cout << "Enter option: ";
    switch (checkIfUserDataIsValid())
    {
    case 1:
        hardOrEasy = "easy";
        if (humanOrBot == "human")
        {
            systemClear();
            playerVsPlayer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        else
        {
            systemClear();
            playerVsComputer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        return true;
        break;

    case 2:
        hardOrEasy = "hard";
        if (humanOrBot == "human")
        {
            systemClear();
            playerVsPlayer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        else
        {
            systemClear();
            playerVsComputer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        return true;
        break;

    default:
        displayErrorMessage();
        difficultyMenu(hackerNumbers, germanNumbers, humanOrBot);
        break;
        
    }
    return false;
}

bool levelMenu(int hackerNumbers[], int germanNumbers[])
{
    cout << endl;
    filesOutput("textFiles/Menu's Text.txt", 2, true, 5);
    cout << endl;
    string humanOrBot;
    cout << "Enter option: ";
    switch (checkIfUserDataIsValid())
    {
    case 1:
        humanOrBot = "computer";
        difficultyMenu(hackerNumbers, germanNumbers, humanOrBot);
        return true;
        break;

    case 2:
        humanOrBot = "human";
        difficultyMenu(hackerNumbers, germanNumbers, humanOrBot);
        return true;
        break;

    default:
        displayErrorMessage();
        levelMenu(hackerNumbers, germanNumbers);
        break;
    }
    return false;
}

bool mainMenu(int hackerNumbers[], int germanNumbers[])
{
    cout << endl;
    filesOutput("textFiles/Menu's Text.txt", 3);
    cout << endl;
    cout << "Enter option: ";
    int container;
    switch (checkIfUserDataIsValid())
    {
    case 1:

        levelMenu(hackerNumbers, germanNumbers);
        return true;
        break;

    case 2:

        systemClear();
        filesOutput("textFiles/Tutorial.txt", 10);
        cout << "Press any key to continue...";
        container = _getch();
        systemClear();

        return true;
        break;

    case 3:

        return false;
        break;

    default:
        displayErrorMessage();
        mainMenu(hackerNumbers, germanNumbers);
        break;
    }
    return false;
}