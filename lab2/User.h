#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;
class User {
private:
	string name;
	string course;
	string group;
	static int userCount;
public:
	User();
	User(string name, string course, string group);
	User(const User& other);
	User(User&& other);
	~User();
    void display() const;
    void setGroup(string group);
	static int getCount();
	User operator+(const User& other);
	friend ostream& operator<<(ostream& os, const User& s);
	friend istream& operator>>(istream& is, User& s);
};
#endif
