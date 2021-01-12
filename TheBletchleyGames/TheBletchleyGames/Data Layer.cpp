#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <sstream> 
#include <conio.h>
#include "Presentation Layer.h"
using namespace std;

int checkIfUserDataIsValid()
{
    int value;
    bool validInput = false;
    do {
        cin >> value;
        if (!(validInput = cin.good())) { // checks if the input is valid
            displayErrorMessage();
            cin.clear(); // clear all errors
            cin.ignore(INT_MAX, '\n'); // removes the whole row
        }

    } while (!validInput);
    return value;
}

int checkIfGermanOrHackerDataIsValid()
{
    char value = _getch();
    switch (value)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    default:
        displayErrorMessage();
        checkIfGermanOrHackerDataIsValid();
        return 0;
    }
}

void input(int numbers[], string hardOrEasy, string germanOrHacker=" ") {
    if (germanOrHacker=="german")
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "Enter a number: ";
            numbers[i] = checkIfGermanOrHackerDataIsValid();
            cout << "*";
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < 4; i++)
        {
            cout << "Enter a number: ";
            numbers[i] = checkIfGermanOrHackerDataIsValid();
            cout << numbers[i];
            cout << endl;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (numbers[i] < 0 or numbers[i]>7)
        {
            displayErrorMessage();
            input(numbers, hardOrEasy); // function call itself if the input is incorrect
        }
    }
    if (hardOrEasy == "easy")
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = i; j < 4; j++)
            {
                if (i != j)
                {
                    if (numbers[i] == numbers[j])
                    {
                        displayErrorMessage();
                        input(numbers, hardOrEasy); // function call itself if there are repetative numbers
                    }
                }
            }
        }
    }
}

void numberGenerator(int germanNumbers[], string hardOrEasy) {
    if (hardOrEasy == "hard")
    {
        for (int i = 0; i < 4; i++)
        {
            germanNumbers[i] = rand() % 8; // generates random number between 1 and 7
        }
    }
    else {
        int numberContainer[8];
        int randomiserContainer;
        int container;
        for (int i = 0; i < 8; i++)
        {
            numberContainer[i] = i; // initialize an array with value from 1 to 7
        }
        for (int i = 0; i < 8; i++) // randomizing the postion of the numbers in the array
        {
            randomiserContainer = (rand() % 7) + 1;
            container = numberContainer[i];
            numberContainer[i] = numberContainer[randomiserContainer];
            numberContainer[randomiserContainer] = container;
        }
        for (int i = 0; i < 4; i++) // pick the first 4 numbers
        {
            germanNumbers[i] = numberContainer[i];
        }
    }
}

string turnNumberIntoChar(int integerNumber) {
    string turnedInteger;
    integerNumber += 48;
    turnedInteger = (char)integerNumber;
    return turnedInteger;
}

string stringInseter(string fileName, int guessedNumbersOrPositions, int insertPosition)
{
    fileName.insert(insertPosition, turnNumberIntoChar(guessedNumbersOrPositions));
    return fileName;
}

void sortNumbers(int sortedNumbers[]) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sortedNumbers[i] > sortedNumbers[j])
            {
                swap(sortedNumbers[i], sortedNumbers[j]);
            }
        }
    }
}

int checkIfThreAreGuessedNumbers(int hackerNumbers[], int germanNumbers[]) {
    int guessedNumbersCount = 0;
    int sortedHackerNumbers[4];
    int sortedGermanNumbers[4];

    for (int i = 0; i < 4; i++)
    {
        sortedGermanNumbers[i] = germanNumbers[i];
        sortedHackerNumbers[i] = hackerNumbers[i];
    }
    sortNumbers(sortedGermanNumbers); // sort the German numbers
    sortNumbers(sortedHackerNumbers); // sort the hacker numbers

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sortedGermanNumbers[i] == sortedHackerNumbers[j])
            {
                guessedNumbersCount++;
                i++;
            }
        }
    }
    return guessedNumbersCount;
}

int checkIfThreAreGuessedNumbersAndPosition(int hackerNumbers[], int germanNumbers[]) {
    int guessedNumbersAndPositionCount = 0;
    for (int i = 0; i < 4; i++)
    {
        if (hackerNumbers[i] == germanNumbers[i])
        {
            guessedNumbersAndPositionCount++;
        }
    }
    return guessedNumbersAndPositionCount;
}

void playerVsPlayer(int hackerNumbers[], int germanNumbers[], string hardOrEasy) {
    int lives = 13;
    cout << "German enter your coordinates: "<<endl;
    input(germanNumbers, hardOrEasy, "german"); // input the German numbers
    systemClear();
label:
    displayLives(lives);
    cout << "Hacker enter your coordinates: "<<endl;
    input(hackerNumbers, hardOrEasy); // input the hacker numbers

    int guessedNumbersCount = checkIfThreAreGuessedNumbers(hackerNumbers, germanNumbers); // see how many guessed numbers are there
    int guessedNumbersAndPositionCount = checkIfThreAreGuessedNumbersAndPosition(hackerNumbers, germanNumbers); // // see how many guessed numbers and positions are there

    guessedNumbersCount = guessedNumbersCount - guessedNumbersAndPositionCount;

    string fileGuessedNumbersName = stringInseter("textFiles/TableVariant.txt", guessedNumbersCount, 22); // insert character into a string so it maches the text file
    string fileGuessedNumbersAndPositionName = stringInseter("textFiles/TableVariant.txt", guessedNumbersAndPositionCount, 22);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guessedNumbersCount));
    cout << "Guessed numbers: " << endl;
    filesOutput(fileGuessedNumbersName, 15); // displays the file
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guessedNumbersAndPositionCount));
    cout << "Guessed numbers and positions: " << endl;
    filesOutput(fileGuessedNumbersAndPositionName, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    if (guessedNumbersAndPositionCount != 4) // if the game is not ended
    {
        lives--; // remove 1 live
        if (lives <= 0)
        {
            filesOutput("textFiles/Mission failed.txt", 19); // displays the file
            highscore(); // add game play
        }
        else
        {         
            goto label;
        }
    }
    else {
        filesOutput("textFiles/Mission completed.txt", 19);
        highscore();
    }
}

void playerVsComputer(int hackerNumbers[], int germanNumbers[], string hardOrEasy) {
    int lives = 13;
    numberGenerator(germanNumbers, hardOrEasy);
label:
    displayLives(lives);
    cout << "Hacker enter your coordinates: " << endl;
    input(hackerNumbers, hardOrEasy);

    int guessedNumbersCount = checkIfThreAreGuessedNumbers(hackerNumbers, germanNumbers);
    int guessedNumbersAndPositionCount = checkIfThreAreGuessedNumbersAndPosition(hackerNumbers, germanNumbers);

    guessedNumbersCount = guessedNumbersCount - guessedNumbersAndPositionCount;

    string fileGuessedNumbersName = stringInseter("textFiles/TableVariant.txt", guessedNumbersCount, 22); // insert character into a string so it maches the text file
    string fileGuessedNumbersAndPositionName = stringInseter("textFiles/TableVariant.txt", guessedNumbersAndPositionCount, 22);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guessedNumbersCount));
    cout << "Guessed numbers: " << endl;
    filesOutput(fileGuessedNumbersName, 15); // displays the file
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guessedNumbersAndPositionCount));
    cout << "Guessed numbers and positions: " << endl;
    filesOutput(fileGuessedNumbersAndPositionName, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    if (guessedNumbersAndPositionCount != 4)
    {
        lives--;
        if (lives <= 0)
        {
            filesOutput("textFiles/Mission failed.txt", 19);
            highscore();
        }
        else
        {
            goto label;
        }
    }
    else {
        filesOutput("Mission completed.txt", 19, false, 0);
        highscore();
    }
}