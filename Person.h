#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
	Person(std::string name_input);
	std::string get_name();
	int get_score();
	void score_update();

private:
	std::string name;
	int score;
};

#endif // !PERSON_H