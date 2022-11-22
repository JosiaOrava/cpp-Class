#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Person {
public:
	Person(const char* name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
	void setName(const char* name);
	std::string getName() const{ return name; } 
private:
	std::string name;
};

class Spy: public Person {
public:
	Spy(const char* name, const char* alias, int resistance);
	void set_identity(const char* alias);
	void interrogate();
	void identity() const;
private:
	std::string alias;
	int resistance;
};

Person::Person(const char* name)
{
	this->name = name;
}

void Person::identity() const
{
	std::cout << name << std::endl;
}

void Person::interrogate()
{
}
void Person::setName(const char* name)
{
	this->name = name;
}

Spy::Spy(const char* name, const char* alias, int resistance)
{
	setName(name);
	this->alias = alias;
	this->resistance = resistance;
}

void Spy::set_identity(const char* alias)
{
	this->alias = alias;
}

void Spy::interrogate()
{
	resistance = resistance - 1;
}

void Spy::identity() const
{
	if (resistance <= 0) {
		std::cout << "My name is: " << getName() << std::endl;
		std::cout << "My alias is: " << alias << std::endl;
	} else { 
		std::cout << "My name is: " << alias << std::endl;
	}
}

int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	std::cout << std::endl << "Nice to meet you. My name is: ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}


