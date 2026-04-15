#include "User.h"
#include <fstream>
#include <stdexcept>

// Ініціалізація статичної змінної
int User::userCount = 0;

//  Реалізація класу User 

User::User() : Person(), course("Unknown"), group("Unknown") {
    userCount++;
}

User::User(string name, string course, string group) : Person(name), course(course), group(group) {
    userCount++;
}

// Конструктор копіювання
User::User(const User& other) : Person(other.name), course(other.course), group(other.group) {
    userCount++;
}

// Конструктор переміщення
User::User(User&& other) noexcept : Person(move(other.name)), course(move(other.course)), group(move(other.group)) {
    // userCount не інкрементуємо, бо ми забираємо існуючий об'єкт
}

// Оператор присвоювання
User& User::operator=(const User& other) {
    if (this != &other) {
        name = other.name;
        course = other.course;
        group = other.group;
    }
    return *this;
}

User::~User() {
    userCount--;
}

void User::display() const {
    Person::display();
    cout << " | Course: " << course << " | Group: " << group << endl;
}

int User::getCount() {
    return userCount;
}

User User::operator+(const User& other) {
    return User(this->name + " & " + other.name, this->course, this->group);
}

// Методи для файлів
void User::saveToFile(ofstream& out) const {
    out << name << "|" << course << "|" << group << endl;
}

void User::loadFromFile(ifstream& in) {
    getline(in, name, '|');
    getline(in, course, '|');
    getline(in, group);
}

void User::logAction(const string& action) const {
    ofstream log("history.txt", ios::app);
    if (log) {
        log << "User " << name << ": " << action << endl;
    }
}

// Реалізація класу Admin 

Admin::Admin(string name, string course, string group, string role)
    : User(name, course, group), role(role) {
}

void Admin::display() const {
    cout << "[ADMIN - " << role << "] ";
    User::display();
}

void Admin::addUserToFile(const User& user) {
    try {
        ofstream file("users.txt", ios::app);
        if (!file) throw runtime_error("File opening failed!");
        user.saveToFile(file);
        cout << "User successfully saved!\n";
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}