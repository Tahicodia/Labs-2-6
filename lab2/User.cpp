#include "User.h"
#include <iostream>
using namespace std;

User::User() : User("Damir Rozhman", "Program Ingeneering", "143a") {}
User::User(string name, string course, string group) : name(name), course(course), group(group) {}
User::User() { cout << "User destroyed/n"; }
void User::User() const { cout << "Name: " << name << ", Course: " << course << ", Group: " << group << endl }