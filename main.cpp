#include <iostream>
#include <string>
#include "Person.h"
#include "Game.h"

int main() {

	std::cout << "Number of games: ";
	int num_games;
	std::cin >> num_games;
	std::cout << "Player 1 Name = ";
	std::string p1_;
	std::cin >> p1_;
	std::cout << "Player 2 Name = ";
	std::string p2_;
	std::cin >> p2_;

	Person p1 = Person::Person(p1_);
	Person p2 = Person::Person(p2_);
	Game TicTacToe = Game::Game(&p1, &p2, num_games);

	TicTacToe.Lets_Play();
}