#include "User.h"
#include <iostream>

using namespace std;
int User::userCount = 0;


User::User(string name, string course, string group)
    : name(name), course(course), group(group) {
}

User::User() : User("Damir Rozhman", "Program Ingeneering", "143a") {}

User::User(const User& other)
    : name(other.name), course(other.course), group(other.group) {
    cout << "User copied\n";
}

User::User(User&& other)
    : name(move(other.name)), course(other.course), group(other.group) {
    cout << "User moved\n";
}

void User::setGroup(string group) {
    this->group = group;
}

int User::getCount() {
    return userCount;
}

User User::operator+(const User& other) {
    return User(name + "&" + other.name, course, group);
}

ostream& operator<<(ostream& os, const User& u) {
    os << u.name << " " << u.course << " " << u.group;
    return os;
}

istream& operator>>(istream& is, User& u) {
    is >> u.name >> u.course >> u.group;
    return is;
}

User::~User() {
    cout << "User destroyed\n";
}

void User::display() const {
    cout << "Name: " << name << ", Course: " << course << ", Group: " << group << endl;
}