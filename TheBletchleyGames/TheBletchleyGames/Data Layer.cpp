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

string stringInseter(string fileName, int guestNumbersOrPositions, int insertPosition)
{
    fileName.insert(insertPosition, turnNumberIntoChar(guestNumbersOrPositions));
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

int checkIfThreAreGuesedNumbers(int hackerNumbers[], int germanNumbers[]) {
    int guestNumbersCount = 0;
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
                guestNumbersCount++;
                i++;
            }
        }
    }
    return guestNumbersCount;
}

int checkIfThreAreGuesedNumbersAndPosition(int hackerNumbers[], int germanNumbers[]) {
    int guestNumbersAndPositionCount = 0;
    for (int i = 0; i < 4; i++)
    {
        if (hackerNumbers[i] == germanNumbers[i])
        {
            guestNumbersAndPositionCount++;
        }
    }
    return guestNumbersAndPositionCount;
}

void playerVsPlayer(int hackerNumbers[], int germanNumbers[], string hardOrEasy) {
    int lives = 13;
    cout << "German enter your cordinates: "<<endl;
    input(germanNumbers, hardOrEasy, "german"); // input the German numbers
    systemClear();
label:
    livesDisplayer(lives);
    cout << "Hacher enter your cordinates: "<<endl;
    input(hackerNumbers, hardOrEasy); // input the hacker numbers

    int guestNumbersCount = checkIfThreAreGuesedNumbers(hackerNumbers, germanNumbers); // see how many guest numbers are there
    int guestNumbersAndPositionCount = checkIfThreAreGuesedNumbersAndPosition(hackerNumbers, germanNumbers); // // see how many guest numbers and positions are there

    guestNumbersCount = guestNumbersCount - guestNumbersAndPositionCount;

    string fileGuestNumbersName = stringInseter("textFiles/TableVariant.txt", guestNumbersCount, 22); // insert character into a string so it maches the text file
    string fileGuestNumbersAndPositionName = stringInseter("textFiles/TableVariant.txt", guestNumbersAndPositionCount, 22); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guestNumbersCount));
    cout << "Guest numbers: " << endl;
    filesOutput(fileGuestNumbersName, 15); // displays the file
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guestNumbersAndPositionCount));
    cout << "Guest numbers and positions: " << endl;
    filesOutput(fileGuestNumbersAndPositionName, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    if (guestNumbersAndPositionCount != 4) // if the game is not ended
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
    livesDisplayer(lives);
    cout << "Hacher enter your cordinates: " << endl;
    input(hackerNumbers, hardOrEasy);

    int guestNumbersCount = checkIfThreAreGuesedNumbers(hackerNumbers, germanNumbers);
    int guestNumbersAndPositionCount = checkIfThreAreGuesedNumbersAndPosition(hackerNumbers, germanNumbers);

    guestNumbersCount = guestNumbersCount - guestNumbersAndPositionCount;

    string fileGuestNumbersName = stringInseter("textFiles/TableVariant.txt", guestNumbersCount, 22); // insert character into a string so it maches the text file
    string fileGuestNumbersAndPositionName = stringInseter("textFiles/TableVariant.txt", guestNumbersAndPositionCount, 22);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guestNumbersCount));
    cout << "Guest numbers: " << endl;
    filesOutput(fileGuestNumbersName, 15); // displays the file
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tableColor(guestNumbersAndPositionCount));
    cout << "Guest numbers and positions: " << endl;
    filesOutput(fileGuestNumbersAndPositionName, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    if (guestNumbersAndPositionCount != 4)
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