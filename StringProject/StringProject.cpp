#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <Windows.h>
using namespace std;

void takeFromFile(string* initWords, int& cnt)
{
    string word;
    ifstream fileRead("words.txt");

    while (getline(fileRead, word))
    {
        initWords[cnt] = word;
        cnt++;
    }

    fileRead.close();
}

void selectWords(string* initWords, string* finalFour, int cnt)
{
    for (int i = 0; i < 4; i++)
    {
        string duma = initWords[rand() % cnt];
        finalFour[i] = duma;
    }
}

string selectPassword(string* finalFour)
{
    string password = finalFour[rand() % 4];

    return password;
}

void DisplayParagraph(string words[])
{
    cout << "It was a question of which of " << words[0] << " two she On the one " << words[1] << ", the choice seemed simple.\nThe more expensive one " << words[2] << " a brand name would be the choice of " << words[3] << ". It was the easy choice.\nThe safe choice.";
}

void CheckPassword(string password, string words[], string passwordEntry, int cnt, int attempts = 1)
{

	cout << "Please enter your password: ";

	getline(cin, passwordEntry, '\n');

	while (passwordEntry != password && attempts <= 2)
	{
		cout << "Please try again: ";
		getline(cin, passwordEntry, '\n');
		attempts++;
	}

	if (passwordEntry == password && attempts <= 3)
	{
		cout << "Access granted";
	}
	else
	{
		cout << "Sorry, only allowed 3 attempts";
	}
}

void showScore(int score, int highScore)
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
    srand(time(NULL));

    int cnt = 0;
    string initWords[250], finalFour[10];

    takeFromFile(initWords, cnt);
    selectWords(initWords, finalFour, cnt);

    string password = selectPassword(finalFour);

    bool showMenu;

    do
    {
        showMenu = mainMenu();
    } while (showMenu);
}