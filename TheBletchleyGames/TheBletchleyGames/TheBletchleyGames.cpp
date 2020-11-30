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

void filesOutput(string fileName, int lineNumbers, bool isThereASkip, int lineSkipNumber) {
    ifstream infile(fileName);
    string sLine;
    if (!(isThereASkip))
    {
        for (int i = 0; i < lineNumbers; i++)
        {
            getline(infile, sLine);
            cout << sLine << endl;
        }
        infile.close();
    }
    else {
        for (int i = 0; i < lineSkipNumber; i++)
        {
            getline(infile, sLine);
        }
        infile.close();
    }
}

int checkIfUserDataIsValid() {
    int dataCheck;
    cin >> dataCheck;
    while (!(dataCheck))
    {
        cin.clear(); // clear the error flags
        cin.ignore(INT_MAX, '\n'); // discard the row
        cout << "Incorrect input! Try again." << endl;
    }
    return dataCheck;
}

bool difficultyMenu()
{
    filesOutput("Menu's Text.txt", 4, true, 6);

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
    filesOutput("Menu's Text.txt", 4, true, 2);
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
    filesOutput("Menu's Text.txt", 2, false, 0);

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
