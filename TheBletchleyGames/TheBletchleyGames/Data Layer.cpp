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
        if (!(validInput = cin.good())) {
            cout << "That input is invalid! Try Again!\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
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
            input(numbers, hardOrEasy);
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
                        input(numbers, hardOrEasy);
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
            germanNumbers[i] = rand() % 8;
        }
    }
    else {
        int numberContainer[8];
        int randomiserContainer;
        int container;
        for (int i = 0; i < 8; i++)
        {
            numberContainer[i] = i;
        }
        for (int i = 0; i < 8; i++)
        {
            randomiserContainer = (rand() % 7) + 1;
            container = numberContainer[i];
            numberContainer[i] = numberContainer[randomiserContainer];
            numberContainer[randomiserContainer] = container;
        }
        for (int i = 0; i < 4; i++)
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
    sortNumbers(sortedGermanNumbers);
    sortNumbers(sortedHackerNumbers);

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
    input(germanNumbers, hardOrEasy);
label:
    livesDisplayer(lives);
    input(hackerNumbers, hardOrEasy);

    int guestNumbersCount = checkIfThreAreGuesedNumbers(hackerNumbers, germanNumbers);
    int guestNumbersAndPositionCount = checkIfThreAreGuesedNumbersAndPosition(hackerNumbers, germanNumbers);

    string fileGuestNumbersName = stringInseter("textFiles/TableVariant.txt", guestNumbersCount, 22);
    string fileGuestNumbersAndPositionName = stringInseter("textFiles/TableVariant.txt", guestNumbersAndPositionCount, 22);
    filesOutput(fileGuestNumbersName, 15);
    filesOutput(fileGuestNumbersAndPositionName, 15);

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