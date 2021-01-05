#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream> 
#include "Presentation Layer.h"
using namespace std;

int checkIfUserDataIsValid()
{
    int value;
    bool validInput = false;
    do {
        cin >> value;
        if (!(validInput = cin.good())) { // checks if the input is valid
            cout << "That input is invalid! Try Again!\n";
            cin.clear(); // clear all errors
            cin.ignore(INT_MAX, '\n'); // removes the whole row
        }

    } while (!validInput);
    return value;
}

void input(int numbers[], string hardOrEasy) {
    for (int i = 0; i < 4; i++)
    {
        numbers[i] = checkIfUserDataIsValid();
    }
    for (int i = 0; i < 4; i++)
    {
        if (numbers[i] < 0 or numbers[i]>7)
        {
            cout << "incorect input try again" << endl;
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
                        cout << "Incrorrect Input!" << endl;
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
    input(germanNumbers, hardOrEasy); // input the German numbers
label:
    livesDisplayer(lives);
    input(hackerNumbers, hardOrEasy); // input the hacker numbers

    int guestNumbersCount = checkIfThreAreGuesedNumbers(hackerNumbers, germanNumbers); // see how many guest numbers are there
    int guestNumbersAndPositionCount = checkIfThreAreGuesedNumbersAndPosition(hackerNumbers, germanNumbers); // // see how many guest numbers and positions are there

    guestNumbersCount = guestNumbersCount - guestNumbersAndPositionCount;

    string fileGuestNumbersName = stringInseter("textFiles/TableVariant.txt", guestNumbersCount, 22); // insert character into a string so it maches the text file
    string fileGuestNumbersAndPositionName = stringInseter("textFiles/TableVariant.txt", guestNumbersAndPositionCount, 22); 
    filesOutput(fileGuestNumbersName, 15); // displays the file
    filesOutput(fileGuestNumbersAndPositionName, 15);

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
    input(hackerNumbers, hardOrEasy);

    int guestNumbersCount = checkIfThreAreGuesedNumbers(hackerNumbers, germanNumbers);
    int guestNumbersAndPositionCount = checkIfThreAreGuesedNumbersAndPosition(hackerNumbers, germanNumbers);

    guestNumbersCount = guestNumbersCount - guestNumbersAndPositionCount;

    string fileGuestNumbersName = stringInseter("textFiles/TableVariant.txt", guestNumbersCount, 22);
    string fileGuestNumbersAndPositionName = stringInseter("textFiles/TableVariant.txt", guestNumbersAndPositionCount, 22);

    filesOutput(fileGuestNumbersName, 15, false, 0);
    filesOutput(fileGuestNumbersAndPositionName, 15, false, 0);

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