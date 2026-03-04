#include "Folders.h"
#include <iostream>
using namespace std;

Folders::Folders() : Folders("", "", "") {}
Folders::Folders(string name, string date, string user) : name(name), date(date), user(user) {}
Folders::Folders() { cout << "Folder destroyed/n"; }
void Folders::Folders() const { cout << "Name: " << name << ", Date: " << date << ", User: " << user << endl }