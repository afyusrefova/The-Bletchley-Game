#include <iostream>

using namespace std;

bool mainMenu()
{
    int option;
    cin >> option;
    switch (option)
    {
    case 1:

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
