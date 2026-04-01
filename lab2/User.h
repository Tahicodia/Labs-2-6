#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

// Рівень 1
class Person {
protected:
    string name;
public:
    Person() : name("Unknown") {}
    Person(string name) : name(name) {}
    virtual ~Person() {}
    virtual void display() const { cout << "Name: " << name; }
};

// Рівень 2 (Is-A Person)
class User : public Person {
protected:
    string course;
    string group;
    static int userCount;

public:
    User();
    // Конструктор на 3 параметри: (ім'я, курс, група)
    User(string name, string course, string group);

    User(const User& other);
    User(User&& other) noexcept;
    User& operator=(const User& other);
    virtual ~User();

    void display() const override;
    User operator+(const User& other);
    static int getCount();
};

// Рівень 3 (Is-A User)
class Admin : public User {
private:
    string role;
public:
    // Конструктор на 4 параметри: (ім'я, курс, група, роль)
    Admin(string name, string course, string group, string role);
    void display() const override;
};

#endif