#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream> 
#include "Data Layer.h"

using namespace std;

void highscore() {
    string sLine;
    fstream file("textFiles/Highscore.txt");
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

void livesDisplayer(int lives)
{
    for (int i = 0; i < lives; i++)
    {
        cout << "<3  ";
    }
    cout << endl;
}

bool difficultyMenu(int hackerNumbers[], int germanNumbers[], string humarOrBot)
{
    filesOutput("textFiles/Menu's Text.txt", 4, true, 6);
    string hardOrEasy;
    switch (checkIfUserDataIsValid())
    {
    case 1:
        hardOrEasy = "easy";
        if (humarOrBot == "human")
        {
            playerVsPlayer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        else
        {
            playerVsComputer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        return true;
        break;

    case 2:
        hardOrEasy = "hard";
        if (humarOrBot == "human")
        {
            playerVsPlayer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        else
        {
            playerVsComputer(hackerNumbers, germanNumbers, hardOrEasy);
        }
        return true;
        break;

    default:

        difficultyMenu(hackerNumbers, germanNumbers, humarOrBot);
        break;

    }
}

bool levelMenu(int hackerNumbers[], int germanNumbers[])
{
    filesOutput("textFiles/Menu's Text.txt", 4, true, 2);
    string humarOrBot;
    switch (checkIfUserDataIsValid())
    {
    case 1:
        humarOrBot = "computer";
        difficultyMenu(hackerNumbers, germanNumbers, humarOrBot);
        return true;
        break;

    case 2:
        humarOrBot = "human";
        difficultyMenu(hackerNumbers, germanNumbers, humarOrBot);
        return true;
        break;

    default:

        levelMenu(hackerNumbers, germanNumbers);
        break;

    }
}

bool mainMenu(int hackerNumbers[], int germanNumbers[])
{
    filesOutput("textFiles/Menu's Text.txt", 2);

    switch (checkIfUserDataIsValid())
    {
    case 1:

        levelMenu(hackerNumbers, germanNumbers);
        return true;
        break;

    case 2:

        return false;
        break;

    default:

        mainMenu(hackerNumbers, germanNumbers);
        break;

    }
}