#include "Folders.h"
#include <iostream>

using namespace std;

Folders::Folders(string name, string date, string user)
    : name(name), date(date), user(user) {
}

Folders::Folders() : Folders("Homeworks", "04.03.2026", "Admin") {}

Folders::~Folders() {
    cout << "Folder destroyed\n";
}

void Folders::Print() const {
    cout << "Name: " << name << ", Date: " << date << ", User: " << user << endl;
}