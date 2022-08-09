#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
	Person(const std::string& name_input);
	std::string get_name() const;
	int get_score() const;
	void score_update();

private:
	std::string name;
	int score;
};

#endif // !PERSON_H
