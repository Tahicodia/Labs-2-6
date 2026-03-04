#include "User.h"
#include <iostream>

using namespace std;

User::User(string name, string course, string group)
    : name(name), course(course), group(group) {
}

User::User() : User("Damir Rozhman", "Program Ingeneering", "143a") {}

User::~User() {
    cout << "User destroyed\n";
}

void User::display() const {
    cout << "Name: " << name << ", Course: " << course << ", Group: " << group << endl;
}