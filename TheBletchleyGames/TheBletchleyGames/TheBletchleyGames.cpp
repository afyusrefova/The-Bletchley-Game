#include <iostream>

using namespace std;

void input(int numbers[], int gameMaxNumbers=4) {
    for (int i = 0; i < gameMaxNumbers; i++)
    {
        cin >> numbers[i];
    }
}

bool difficultyMenu()
{
    cout << "1. Easy mode" << endl;
    cout << "2. Hard mode" << endl;
    int difficultyOption;
    while (!(cin >> difficultyOption))
    {

        cin.clear(); // clear the error flags
        cin.ignore(INT_MAX, '\n'); // discard the row
        cout << "Incorrect input! Try again." << endl;
    }​​​​​:
    switch (difficultyOption)
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
    cout << "1. Play vs Computer" << endl;
    cout << "2. Play vs Player" << endl;
    int levelOption;
    while (!(cin >> levelOption))
    {

        cin.clear(); // clear the error flags
        cin.ignore(INT_MAX, '\n'); // discard the row
        cout << "Incorrect input! Try again." << endl;
    }​​​​​:
    switch (levelOption)
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
    cout << "1. Play Game" << endl;
    cout << "2. Exit" << endl;
    int option;
    while (!(cin >> option))
    {

        cin.clear(); // clear the error flags
        cin.ignore(INT_MAX, '\n'); // discard the row
        cout << "Incorrect input! Try again." << endl;
    }​​​​​:
    switch (option)
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
