#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <Windows.h>
using namespace std;

void takeFromFile(string* allWords, int& cnt);
void selectWords(string* allWords, string* finalFour, int cnt);
string selectPassword(string* finalFour);
void DisplayParagraph(string words[]);
string runGame(string* finalFour, string* allWords, int& cnt);
bool mainMenu(string* finalFour, string* allWords, int& cnt);