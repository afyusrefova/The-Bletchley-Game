#include <iostream>

using namespace std;

bool difficultyMenu()
{
    cout << "1. Easy mode" << endl;
    cout << "2. Hard mode" << endl;
    int difficultyOption;
    cin >> difficultyOption;


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
    cin >> levelOption;
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
    cin >> option;
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
    bool exit = true;
    do
    {
        exit = mainMenu();
    } while (exit);
}
