#include "Person.h"

//Constructs Class Person; assigns member fields name and score

Person::Person(std::string name_input): name(name_input), score(0){
	
}

//retrieves player names from Class Person
//@param: implicit parameter is Player of Type Class Person
//@return: player name

std::string Person::get_name()
{
	return name;
}

//retrieves player scores from Class Person
//@param: implicit parameter is Player of Type Class Person
//@return: player score

int Person::get_score()
{
	return score;
}

//accesses and updates player score from Class Person
//@param: implicit parameter is Player of Type Class Person
//@return: none

void Person::score_update()
{
	score += 1;
}