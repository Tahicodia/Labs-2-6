#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    string name;
public:
    Person() : name("Unknown") {}
    Person(string name) : name(name) {}
    virtual ~Person() {} //віртуал це дозвіл від батьківського класу на зміну поведінки в дочірньому класі
    virtual void display() const { cout << "Name: " << name; }
};

class User : public Person {
protected:
    string course;
    string group;
    static int userCount;

public:
    User();
    User(string name, string course, string group);
    User(const User& other);
    User(User&& other) noexcept; //ноексепт - це гарантія, що воно не бахне
    User& operator=(const User& other);
    virtual ~User();

	void display() const override; // оверрайд це підтвердження дозволу на зміну поведінки в дочірньому класі
    User operator+(const User& other);
    static int getCount();
};

class Admin : public User {
private:
    string role;
public:
    Admin(string name, string course, string group, string role);
    void display() const override;
};

#endif