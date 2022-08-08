#ifndef GAME_H
#define GAME_H

#include "Person.h"

class Game {

public:
	Game(Person* p1, Person* p2, int num_games);
	void Lets_Play();
	void print_board();
	bool playable(int i, int j);
	void update_board(char mark, int i, int j);
	bool winner(char mrk);
	void end_turn();
	void end_round();
	void clear_board();
	void play_again();
	std::string tour_winner();
	bool boardfull();

private:
	Person* player_1 = nullptr;
	Person* player_2 = nullptr;
	Person* current = nullptr;
	int total_games;
	int games_played;
	char mm[3][3] = { ' ', ' ', ' ',
					 ' ', ' ', ' ',
					' ', ' ', ' ' };
	bool game_over;
};

#endif // !GAME_H