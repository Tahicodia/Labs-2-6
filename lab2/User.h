#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Person {
protected:
    string name;
public:
    Person() : name("Unknown") {}
    Person(string name) : name(name) {}
    virtual ~Person() {}
    virtual void display() const { cout << "Name: " << name; }
    void testStatic() const { cout << "Base (Person)" << endl; }
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
    User(User&& other) noexcept;
    User& operator=(const User& other);
    virtual ~User();

    void testStatic() const { cout << "Derived (User)" << endl; }
    void display() const override;

    User operator+(const User& other);
    static int getCount();

    //  ДОДАНО 
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);
    void logAction(const string& action) const;
};

class Admin : public User {
private:
    string role;
public:
    Admin(string name, string course, string group, string role);
    void display() const override;

    //  ДОДАНО 
    void addUserToFile(const User& user);
};

#endif