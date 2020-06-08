#include <iostream>
using namespace std;

void DisplayParagraph(string words[])
{
	srand(time(NULL));

	cout << "It was a question of which of " << words[rand() % 12] << " two she On the one " << words[rand() % 12] << ", the choice seemed simple.\nThe more expensive one " << words[rand() % 12] << " a brand name would be the choice of " << words[rand() % 12] << ". It was the easy choice.\nThe safe choice. But she wasn't " << words[rand() % 12] << " she actually preferred it.";

}

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
	string words[] = { "BOAT", "VAST", "BODY", "LAYS", "RAGS", "FEED", "SOUL", "NOTE", "TAKE", "EARN", "CARS", "TELL" };

	DisplayParagraph(words);

    bool showMenu;
    do
    {
        showMenu = mainMenu();
    } while (showMenu);
}