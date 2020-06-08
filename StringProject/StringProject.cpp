#include <iostream>
using namespace std;

int showScore(int score, int highScore)
{
    if (score > highScore)
    {
        cout << "Highscore: " << score << endl;
    }
    else
    {
        cout << "Highscore: " << highScore << endl;
    }
}

bool mainMenu()
{
    int choice;
    cout << "...:::MAIN MENU:::..." << endl;
    cout << "1) Start game" << endl;
    cout << "2) Show score" << endl;
    cout << "3) Exit game" << endl;
    cout << "Your choice is: ";
    cin >> choice;
    switch (choice)
    {
        case 1:

            break;
        case 2:

            break;
        case 3:
            return false;
            break;
        default:
            cout << "Invalid input" << endl;
            return false;
            break;
    }
    return true;
}

int main()
{
    bool showMenu;
    do
    {
        showMenu = mainMenu();
    } while (showMenu);
}