#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <Windows.h>
#include "functions.h"
using namespace std;

int main()
{
    srand(time(NULL));

    int cnt = 0;
    string allWords[250], finalFour[10];

    bool showMenu;

    do
    {
        showMenu = mainMenu(finalFour, allWords, cnt);
    } while (showMenu);
}