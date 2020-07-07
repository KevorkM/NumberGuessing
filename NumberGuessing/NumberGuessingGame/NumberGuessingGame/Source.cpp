
#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <ctime>

using namespace std;

//functions
void PlayGame();
bool WantToPlayAgain();
int GetGuesses(int NumberOfTries);

bool isGameOver(int SecretNumber, int NumerOfTries, int Guess);
void DisplayResult(int SecretNumber, int NumberOfTries);

//Variables
const int IGNORE_CHARS = 256;

int main() {

	cout << "The number guesser game" << endl;

	srand((unsigned int)time(NULL));// to make the value a random number

	do {
		PlayGame();
	} while (WantToPlayAgain());

	return 0;
}

void PlayGame() {
	const int UPPER_BOUND = 100;

	int SecretNumber = rand() %UPPER_BOUND;
	int NumberOfTries = ceil(log2(UPPER_BOUND));
	int Guess = 0;

	cout << "The range of the number is between, 0 and 100 " << endl;

	do {

		Guess = GetGuesses(NumberOfTries);
		if (Guess != SecretNumber) {
			NumberOfTries--;

			if (Guess > SecretNumber) {
				cout << "Your Guess was to high!" << endl;
			}
			else {
				cout << "Your guess was to low!" << endl;
			}
		}

	} while (!isGameOver(SecretNumber, NumberOfTries, Guess));

	DisplayResult(SecretNumber, NumberOfTries);
}

bool WantToPlayAgain() {

	char input;
	bool failure;

	do {
		failure = false;
		cout << "Would you like to play again? (Y/N) ";
		cin >> input;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');

			cout << "Input error! Please try again." << endl;
			failure = true;
		}
		/* to check whether y is lowercase or capital letter 
		(need to include cctype)
		else {
		cin.ignore(IGNORE_CHARS, '\n');
		input = tolower(input);
		}
		*/
	} while (failure);

	return input == 'y'||'Y';
}

int GetGuesses(int NumberOfTries)
{
	int Guess;

	bool failure;

	do {
		failure = false;
		cout << "Please enter your guess(Number Of tries left: " << NumberOfTries << " )";
		cin >> Guess;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Input Error! Please try again." << endl;
			failure = true;
		}

	} while (failure);

	return Guess;
}

bool isGameOver(int SecretNumber, int NumerOfTries, int Guess)
{
	return SecretNumber == Guess || NumerOfTries <= 0;
}

void DisplayResult(int SecretNumber, int NumberOfTries) {

	if (NumberOfTries > 0) {
		cout << "You got the number! It was:" << SecretNumber << endl;
	}
	else {
		cout << "You did not get it! It was: " << SecretNumber << endl;
	}
}