#include "User.h"
#include <utility>

int User::userCount = 0;

User::User() : Person("Noname"), course("None"), group("None") { userCount++; }

User::User(string name, string course, string group)
    : Person(name), course(course), group(group) {
    userCount++;
}

User::User(const User& other) : Person(other), course(other.course), group(other.group) {
    userCount++;
}

User::User(User&& other) noexcept
    : Person(move(other)), course(move(other.course)), group(move(other.group)) {
}

User& User::operator=(const User& other) {
    if (this != &other) {
        Person::operator=(other);
        this->course = other.course;
        this->group = other.group;
    }
    return *this;
}

User::~User() { userCount--; }

void User::display() const {
    Person::display();
    cout << ", Course: " << course << ", Group: " << group;
}

User User::operator+(const User& other) {
    return User(this->name + " & " + other.name, this->course, this->group);
}

int User::getCount() { return userCount; }

Admin::Admin(string name, string course, string group, string role)
    : User(name, course, group), role(role) {
}

void Admin::display() const {
    cout << "[ADMIN] ";
    User::display();
    cout << ", Role: " << role << endl;
}