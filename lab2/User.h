#ifndef USER_H
#define USER_H
#include <string>
class User {
private:
	string name;
	string course;
	string group;
public:
	User();
	User(string name, string course, string group);
	~User();
	void display() const;
};
#endif
