#include "Files.h"
#include <iostream>
using namespace std;

Files::Files() : Files("Homework_OOP", "Homeworks", "Admin") {}
Files::Files(string name, string folder, string user) : name(name), folder(folder), user(user) {}
Files::Files() { cout << "Files destroyed/n"; }
void Files::Files() const { cout << "Name: " << name << ", Folder: " << folder << ", User: " << user << endl }