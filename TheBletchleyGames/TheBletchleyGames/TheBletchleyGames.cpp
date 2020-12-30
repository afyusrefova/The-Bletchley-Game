#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream> 
#include "Presentation Layer.h"
#include "Data Layer.h"

using namespace std;

int main()
{
    int* hackerNumbers;
    int* germanNumbers;
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