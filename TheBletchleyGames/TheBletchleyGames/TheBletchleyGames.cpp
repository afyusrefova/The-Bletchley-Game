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

bool difficultyMenu()
{
    filesOutput("textFiles/Menu's Text.txt", 4, true, 6);

    switch (checkIfUserDataIsValid())
    {
    case 1:

        return true;
        break;

    case 2:

        return true;
        break;

    default:

        difficultyMenu();
        break;

    }
}

bool levelMenu()
{
    filesOutput("textFiles/Menu's Text.txt", 4, true, 2);
    switch (checkIfUserDataIsValid())
    {
    case 1:

        difficultyMenu();
        return true;
        break;

    case 2:

        difficultyMenu();
        return true;
        break;

    default:

        levelMenu();
        break;

    }
}

bool mainMenu()
{
    filesOutput("textFiles/Menu's Text.txt", 2);

    switch (checkIfUserDataIsValid())
    {
    case 1:

        levelMenu();
        return true;
        break;

    case 2:

        return false;
        break;

    default:

        mainMenu();
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
        exit = mainMenu();
    } while (exit);
    delete[]germanNumbers;
    delete[]hackerNumbers;
}
