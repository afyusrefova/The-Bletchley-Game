#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void input(int numbers[], int gameMaxNumbers = 4) {
    for (int i = 0; i < gameMaxNumbers; i++)
    {
        cin >> numbers[i];

    }
}

void filesOutput(string fileName, int lineNumber, bool isThereASkip=false, int lineSkipNumber=0) {
    ifstream file(fileName);
    string sLine;
    if (isThereASkip)
    {
        for (int i = 0; i < lineSkipNumber; i++)
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

int checkIfThreAreGuesedNumbers(int hackerNumbers[], int germanNumbers[]) {
    int guestNumbersCount = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (hackerNumbers[i] == germanNumbers[j])
            {
                guestNumbersCount++;
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

void playerVsPlayerEasyMode(int hackerNumbers[], int germanNumbers[]) {
    for (int i = 0; i < 4; i++)
    {
        cin >> hackerNumbers[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> germanNumbers[i];
    }

    int guestNumbersCount = checkIfThreAreGuesedNumbers(hackerNumbers, germanNumbers);
    cout << guestNumbersCount << endl;
    int guestNumbersAndPositionCount = checkIfThreAreGuesedNumbersAndPosition(hackerNumbers, germanNumbers);
    cout << guestNumbersAndPositionCount <<endl;
}

bool difficultyMenu(int hackerNumbers[], int germanNumbers[])
{
    filesOutput("textFiles/Menu's Text.txt", 4, true, 6);

    switch (checkIfUserDataIsValid())
    {
    case 1:
        playerVsPlayerEasyMode(hackerNumbers, germanNumbers);
        return true;
        break;

    case 2:

        return true;
        break;

    default:

        difficultyMenu(hackerNumbers, germanNumbers);
        break;

    }
}

bool levelMenu(int hackerNumbers[], int germanNumbers[])
{
    filesOutput("textFiles/Menu's Text.txt", 4, true, 2);
    switch (checkIfUserDataIsValid())
    {
    case 1:

        difficultyMenu(hackerNumbers, germanNumbers);
        return true;
        break;

    case 2:

        difficultyMenu(hackerNumbers, germanNumbers);
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

int main()
{
    int *hackerNumbers;
    int *germanNumbers;
    hackerNumbers = new int[4];
    germanNumbers = new int[4];
    bool exit = true;
    do
    {
        exit = mainMenu(hackerNumbers, germanNumbers);
    } while (exit);
    delete[]germanNumbers;
    delete[]hackerNumbers;
}
