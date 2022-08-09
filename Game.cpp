#include <iostream>
#include "Game.h"

//Contructs Class Game; assigns member field pointers to Type Class Person player_1 and player_2

Game::Game(Person* const p1, Person* const p2, const int num_games) : player_1(p1), player_2(p2), current(p1),
total_games(num_games), games_played(0), game_over(false) {

}

//Tournament game control flow
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: none

void Game::Lets_Play() {

	std::cout << "	Tic Tac Toe" << std::endl;
	std::cout << "  " << player_1->get_name() << " (X) - "
		<< player_2->get_name() << " (O)" << std::endl;

	int row; int col;

	do
	{
		this->print_board();

		do {
			std::cout << player_1->get_name() << " (X) Mark Location: ";
			std::cin >> row >> col;
		} while (!(this->playable(row, col)));

		this->update_board('X', row, col);
		this->print_board();

		if (!(this->winner('X'))) {
			this->end_turn();
		}
		else {
			this->end_round();
			player_1->score_update();
			continue;
		}

		if (this->boardfull()) {

			games_played += 1;
			std::cout << " It's a Draw!" << std::endl;
			this->clear_board();
			this->play_again();
			continue;
		}

		do {
			std::cout << player_2->get_name() << " (O) Mark Location: ";
			std::cin >> row >> col;
		} while (!(this->playable(row, col)));

		this->update_board('O', row, col);
		this->print_board();

		if (!(this->winner('O'))) {
			this->end_turn();
		}
		else {
			this->end_round();
			player_2->score_update();
		}

	} while (!game_over);

	std::cout << player_1->get_name() << " : " << player_1->get_score() << std::endl;
	std::cout << player_2->get_name() << " : " << player_2->get_score() << std::endl;
	std::cout << "Congratulations " << this->tour_winner() << ". You won!" << std::endl;
}

//displays TicTacToe board and plays made (if any)
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: none

void Game::print_board() const{

	std::cout << "     1       2       3   \n"
		"         |       |       \n"
		"1    " << mm[0][0] << "   |   " << mm[0][1] << "   |   " << mm[0][2] << "   \n"
		"  _______|_______|_______\n"
		"         |       |       \n"
		"2    " << mm[1][0] << "   |   " << mm[1][1] << "   |   " << mm[1][2] << "   \n"
		"  _______|_______|_______\n"
		"         |       |       \n"
		"3    " << mm[2][0] << "   |   " << mm[2][1] << "   |   " << mm[2][2] << "   \n"
		"         |       |       \n\n\n";
}

//checks whether specified location is playable (within bounds and empty)
//@param: explicit parameter is row and column location player is attempting to occupy
//@return: true if location playable; false o/w

bool Game::playable(const int i, const int j) const{

	if (mm[i - 1][j - 1] == ' ') {
		return true;
	}
	else {
		return false;
	}
}

//updates board with player's specified mark ('X' or 'O') at specified row and column
//@param: explicit parameter is player's specific mark (either 'X' or 'O'), and row/column player wishes to occupy
//@return: none

void Game::update_board(const char mark, const int i, const int j) {

	mm[i - 1][j - 1] = mark;
}

//checks whether game has been won by a specified mark
//@param: specific player's mark being checked across all rows/columns/diagonals
//@return: true if player's mark found across a row, colummn or diagonal; false o/w

bool Game::winner(const char mrk) const
{
	//checks rows
	if (mrk == mm[0][0] && mm[0][0] == mm[0][1] && mm[0][1] == mm[0][2]) {
		return true;
	}
	if (mrk == mm[1][0] && mm[1][0] == mm[1][1] && mm[1][1] == mm[1][2]) {
		return true;
	}
	if (mrk == mm[2][0] && mm[2][0] == mm[2][1] && mm[2][1] == mm[2][2]) {
		return true;
	}
	//checks columns
	if (mrk == mm[0][0] && mm[0][0] == mm[1][0] && mm[1][0] == mm[2][0]) {
		return true;
	}
	if (mrk == mm[0][1] && mm[0][1] == mm[1][1] && mm[1][1] == mm[2][1]) {
		return true;
	}
	if (mrk == mm[0][2] && mm[0][2] == mm[1][2] && mm[1][2] == mm[2][2]) {
		return true;
	}
	//checks diagonals
	if (mrk == mm[0][0] && mm[0][0] == mm[1][1] && mm[1][1] == mm[2][2]) {
		return true;
	}
	if (mrk == mm[0][2] && mm[0][2] == mm[1][1] && mm[1][1] == mm[2][0]) {
		return true;
	}
	else {
		return false;
	}
}

//changes which player is currently in play
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: none

void Game::end_turn() {

	if (current == player_1) {
		current = player_2;
	}
	else {
		current = player_1;
	}
}

//displays round winner; clears board; checks if there are more rounds left to play; increments games_played member field
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: none

void Game::end_round() {

	games_played += 1;
	std::cout << current->get_name() << " wins this round!" << std::endl;
	this->clear_board();
	this->play_again();
}

//clears board for new round
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: none

void Game::clear_board() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mm[i][j] = ' ';
		}
	}
}

//checks if there are more games to be played in tournament
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: none

void Game::play_again() {

	if (games_played == total_games) {
		game_over = true;
	}
	current = player_1;
}

//retrieves name(s) of tournament winner(s)
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: name(s) of tournament winner(s)

std::string Game::tour_winner() const{

	if (player_1->get_score() < player_2->get_score()) {
		return player_2->get_name();
	}
	if (player_2->get_score() < player_1->get_score()) {
		return player_1->get_name();
	}

	return player_1->get_name() + " & " + player_2->get_name();
}

//checks whether board is full
//@param: implicit parameter is TicTacToe of Type Class Game
//@return: false if there is an empty space; true o/w

bool Game::Game::boardfull() const {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (mm[i][j] == ' ') {
				return false;
			}
		}
	}

	return true;
}