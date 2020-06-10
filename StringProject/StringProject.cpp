#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <Windows.h>
using namespace std;

void takeFromFile(string* allWords, int& cnt)
{
    string word;
    ifstream fileRead("words.txt");

    while (getline(fileRead, word))
    {
        allWords[cnt] = word;
        cnt++;
    }

    fileRead.close();
}

void selectWords(string* allWords, string* finalFour, int cnt)
{
    for (int i = 0; i < 4; i++)
    {
        string duma = allWords[rand() % cnt];
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
    cout << "It was a question of which of " << words[0] << " two she On the one " << words[1] << ", the choice seemed simple.\nThe more expensive one " << words[2] << " a brand name would be the choice of " << words[3] << ". It was the easy choice.\nThe safe choice." << endl;
    cout << endl;
}

string runGame(string* finalFour, string* allWords, int& cnt)
{
    takeFromFile(allWords, cnt);

    selectWords(allWords, finalFour, cnt);
    string pass = selectPassword(finalFour);

labelChoice:
    system("CLS");

    DisplayParagraph(finalFour);

    int attempts = 2, charsGuessed = 0,choice;

    bool gameEnd = false;

    string userChoice;

    do
    {
        cout << endl;
        cout << "Number of attempts left: " << attempts << endl;
        cout << "Enter word choice: "; cin >> userChoice;
        
        cout << endl;

        if (userChoice == finalFour[0] or userChoice == finalFour[1] or userChoice == finalFour[2] or userChoice == finalFour[3])
        {
            if (userChoice == pass)
            {
                cout << "Congratulations! You guessed the word!" << endl
                    << endl;
                cout << "Thank you for playing!" << endl;
                Sleep(2*1000);
                gameEnd = true;
            }
            else
            {

                for (int i = 0; i < 4; i++)
                {
                    if (userChoice[i] == pass[i])
                    {
                        charsGuessed++;
                    }
                }

                cout << "You guessed " << charsGuessed << "/4 symbols. Try again!" << endl;
                charsGuessed = 0;
                attempts--;

                if (attempts == 0)
                {
                    cout << "Thank you for playing!" << endl;
                    Sleep(2*1000);
                    gameEnd = true;
                }
            }
        }
        else
        {
            goto labelChoice;
        }

    } while (gameEnd != true);
    return 0;
}

/*string writeScore(string ign, int score)
{
    ifstream read;
    ofstream append;

    string line;

    read.open("source.txt");
    append.open("source.txt", ios::app);

    bool isEmpty = read.peek() == EOF;

    if (isEmpty)
    {
        append << ign << endl;
        append << "BREAK" << endl;

        return 0;
    }

    while (getline(read, line))
    {
        string sline;

        if (line == "BREAK")
        {
            getline(read, sline);
            if (sline.empty())
            {
                append << ign << endl;
                append << score << endl;
                append << "BREAK" << endl;
                return 0;
            }
        }
    }

    read.close();
    append.close();
}
*/

// not enough time to finish score system


bool mainMenu(string* finalFour, string* allWords, int& cnt)
{
    system("CLS");

    int choice;
labelMenu:
    cout << "...:::MAIN MENU:::..." << endl
        <<endl
        << "(1) Start game" << endl
        << endl
        << "(2) Show instructions" << endl
        << endl
        << "(3) Quit" << endl
        << endl
        << "Enter choice: "; cin >> choice;
    switch (choice)
    {
    case 1:
        runGame(finalFour, allWords, cnt);
        break;
    case 2:

        int choice2;

        system("CLS");
        cout << endl
            << "Instructions on how to play:" << endl
            << endl
            << "1. Upon choosing to start a game, a paragraph with four uppercase words will be displayed on the screen. One of the words is the password." << endl
            << endl
            << "2. To make your guess, enter the desired word as you see it on screen (All capital letters!)" << endl
            << endl
            << "3. If you guessed the word, the game will end and you'll have to restart the program to play again." << endl
            << endl
            << "4. If your guess is wrong, the number of letters that are the same as the password and in the same position will be displayed alongside your remaining attempts." << endl
            << endl
            << "Exit instructions?" << endl
            << "(1) Yes" << endl
            << endl
            << "Enter choice: "; cin >> choice2;

        if (choice2 == 1)
        {
            system("CLS");
            goto labelMenu;
        }
     
        break;
    case 3:
        return false;
        break;
    default:
        cout << "Invalid input" << endl;
        Sleep(2*1000);
        system("CLS");
        goto labelMenu;
        break;
    }
    return true;
}

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