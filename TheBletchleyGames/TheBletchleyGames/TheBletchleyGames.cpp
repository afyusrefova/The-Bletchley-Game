#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream> 
#include <conio.h>
#include "Presentation Layer.h"
#include "Data Layer.h"

using namespace std;

int main()
{
    greeting();
    int hackerNumbers[4];
    int germanNumbers[4];
    bool exit = false;
    do
    {
        exit = mainMenu(hackerNumbers, germanNumbers);
    } while (exit);
    return 0;
}