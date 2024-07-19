#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

enum Choice {rock, paper, scissors};
string choices[3] = { "rock", "paper", "scissors" };

enum Outcome {user, bot, draw};
string outcomes[3] = { "You win!", "Bot wins!", "Draw!" };

Choice getUserChoice() {
	string choice;
	auto userChoice = "NA";
			std:: cout << "Rock, Paper, or Scissors?\n";
			std:: cin >> choice;
			while (userChoice = "NA") {
				if (choice == "Rock" || choice == "rock" || choice == "R" || choice == "r") {
					return rock;
				}
				else if (choice == "Paper" || choice == "paper" || choice == "P" || choice == "p") {
					return paper;
				}
				else if (choice == "Scissors" || choice == "scissors" || choice == "S" || choice == "s") {
					return scissors;
				}
				else {
					cout << "I'm sorry, I didn't understand \"" << choice << "\".\n";
					cout << "Rock, Paper, or Scissors?\n";
					cin >> choice;
				}
			}
}

Choice getBotChoice() {
	auto randomNumber = rand() % 3 + 1;
	
	switch (randomNumber) {
	case 1:
		return rock;
	case 2:
		return paper;
	case 3:
		return scissors;
	default:
		throw invalid_argument("Random number was generated outside of the given range.");
	}
}

Outcome decideOutcome(Choice userChoice, Choice botChoice) {
	if (userChoice == botChoice) {
		return draw;
	}
	else if (userChoice == rock && botChoice == paper) {
		return bot;
	}
	else if (userChoice == rock && botChoice == scissors) {
		return user;
	}
	else if (userChoice == paper && botChoice == rock) {
		return user;
	}
	else if (userChoice == paper && botChoice == scissors) {
		return bot;
	}
	else if (userChoice == scissors && botChoice == rock) {
		return bot;
	}
	else if (userChoice == scissors && botChoice == paper) {
		return user;
	}

}

bool shouldGameEnd() {
	string input;
	cout << "Quit?\n";
	cin >> input;
	if (input == "No" || input == "no" || input == "N" || input == "n" || input == "0") {
		return false;
	}
	else {
		return true;
	}

}

void gameLoop();

int main() {
	
	string choice;
	auto play = true;

	cout << "Would you like to play rock-paper-scissors? \n";
	cin >> choice; "\n";
	

	while (play == true) {
		if (choice == "Yes" || choice == "yes" || choice == "Y" || choice == "y") {
			gameLoop();
			break;
		}
		else if (choice == "No" || choice == "N" || choice == "n") {
			cout << "We can play some other time! \n";
			return 0;
		}
		else {
			cout << "I'm sorry, I didn't understand \"" << choice << "\".\n";
			cout << "Would you like to play rock paper scissors? \n";
			cin >> choice; "\n";
		}
	}
	return 0;
}

void gameLoop() {
	int userTotal = 0;
	int botTotal = 0;
	auto quit = false;
	while (!quit) {
		auto userChoice = getUserChoice();
		auto botChoice = getBotChoice();
		cout << "You chose " << choices[userChoice] << "\r\n";
		cout << "Bot chose " << choices[botChoice] << "\r\n";
		cout << outcomes[decideOutcome(userChoice, botChoice)] << "\r\n";
		if (userChoice == rock && botChoice == paper) {
			botTotal++;
	}
		else if (userChoice == rock && botChoice == scissors) {
			userTotal++;
	}
		else if (userChoice == paper && botChoice == rock) {
			userTotal++;
		}
		else if (userChoice == paper && botChoice == scissors) {
			botTotal++;
			}
		else if (userChoice == scissors && botChoice == rock) {
			botTotal++;
				}
		else if (userChoice == scissors && botChoice == paper) {
			userTotal++;
		}
		quit = shouldGameEnd();
	}
	cout << "Your total rounds won were: " << userTotal << "\n";
	cout << "The bot total rounds won were: " << botTotal << "\n";
	if (userTotal < botTotal) {
		cout << "The bot beat you!\n";
		cout << "Thanks for playing!\n";
	}
	else if (botTotal < userTotal) {
		cout << "You beat the bot!\n";
		cout << "Thanks for playing!\n";
	}
	else if (botTotal == userTotal) {
		cout << "This game ends in a draw!\n";
		cout << "Thanks for playing!\n";
	}
}