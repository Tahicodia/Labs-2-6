#include "Folders.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

//  Реалізація класу Folder 

Folder::Folder() : name("New Folder"), date("01.01.2026"), user("Admin"), files(nullptr) {}

Folder::Folder(string name, string date, string user)
    : name(name), date(date), user(user), files(nullptr) {
}

Folder::Folder(string name, string date, string user, Files* files)
    : name(name), date(date), user(user), files(files) {
}

// Конструктор копіювання глибоке копіювання файлів
Folder::Folder(const Folder& other) : name(other.name), date(other.date), user(other.user) {
    if (other.files) {
        // Тут бажано мати метод clone() у класі Files, 
        // але для простоти поки зробимо так або просто копіюємо вказівник якщо це допустимо
        files = other.files;
    }
    else {
        files = nullptr;
    }
}

// Конструктор переміщення
Folder::Folder(Folder&& other) noexcept
    : name(move(other.name)), date(move(other.date)), user(move(other.user)), files(other.files) {
    other.files = nullptr;
}

// Оператор присвоювання
Folder& Folder::operator=(const Folder& other) {
    if (this != &other) {
        name = other.name;
        date = other.date;
        user = other.user;
        files = other.files;
    }
    return *this;
}

// ДЕСТРУКТОР 
Folder::~Folder() {
    if (files) {
        delete files;
        files = nullptr;
    }
}

void Folder::display() const {
    cout << "Folder: " << name << " | Created: " << date << " | Owner: " << user << endl;
    if (files) {
        cout << "  Contains: ";
        files->display();
    }
    else {
        cout << "  Folder is empty." << endl;
    }
}

// ЗБЕРЕЖЕННЯ
void Folder::saveToFile(ofstream& out) const {
    out << "FOLDER|" << name << "|" << date << "|" << user << "|";
    if (files) {
        // Тут логіка Files має сама дописувати тип MEDIA/TEXT
        files->saveToFile(out);
    }
    else {
        out << "NONE\n";
    }
}

// ЗАВАНТАЖЕННЯ
void Folder::loadFromFile(ifstream& in) {
    string type;
    getline(in, name, '|');
    getline(in, date, '|');
    getline(in, user, '|');
    getline(in, type, '|');

    try {
        if (type == "MEDIA") {
            files = new MediaFile();
            files->loadFromFile(in);
        }
        else if (type == "TEXT") {
            files = new TextFile();
            files->loadFromFile(in);
        }
        else {
            files = nullptr;
        }
    }
    catch (...) {
        files = nullptr;
    }
}

//  Реалізація класу ZipFolder 

ZipFolder::ZipFolder(string name, string date, string user, Files* files, double compressionRatio)
    : Folder(name, date, user, files), compressionRatio(compressionRatio) {
}

void ZipFolder::display() const {
    cout << "[ZIP ARCHIVE - " << compressionRatio << "x] ";
    Folder::display();
}

void ZipFolder::saveToFile(ofstream& out) const {
    out << "ZIP|";
    Folder::saveToFile(out);
    out << "|" << compressionRatio << endl;
}