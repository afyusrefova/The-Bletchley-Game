#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream> 
#include "Presentation Layer.h"
#include "Data Layer.h"

using namespace std;

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    filesOutput("textFiles/Greating!.txt", 20);
    int* hackerNumbers;
    int* germanNumbers;
    hackerNumbers = new int[4];
    germanNumbers = new int[4];
    bool exit = true;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    do
    {
        exit = mainMenu(hackerNumbers, germanNumbers);
    } while (exit);
    delete[]germanNumbers;
    delete[]hackerNumbers;
}