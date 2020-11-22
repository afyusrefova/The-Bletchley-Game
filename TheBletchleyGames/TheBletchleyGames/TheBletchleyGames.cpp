#include <iostream>

using namespace std;

bool levelMenu()
{
    int levelOption;
    cin >> levelOption;
    switch (levelOption)
    {
    case 1:

        return true;
        break;

    case 2:
        return true;
        break;

    default:

        levelMenu();
        break;

    }
}

bool mainMenu()
{
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
