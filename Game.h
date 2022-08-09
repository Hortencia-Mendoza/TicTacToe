#ifndef GAME_H
#define GAME_H

#include "Person.h"

class Game {

public:
	Game(Person* const p1, Person* const p2, const int num_games);
	void Lets_Play();
	void print_board() const;
	bool playable(const int i, const int j) const;
	void update_board(const char mark, const int i, const int j);
	bool winner(const char mrk) const;
	void end_turn();
	void end_round();
	void clear_board();
	void play_again();
	std::string tour_winner() const;
	bool boardfull() const;

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
