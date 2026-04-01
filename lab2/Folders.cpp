#include "Folders.h"
#include <iostream>
using namespace std;

Folders::Folders() : name("Homeworks"), date("04.03.2026"), user("Admin"), files(nullptr) {}

Folders::Folders(string name, string date, string user)
    : name(name), date(date), user(user), files(nullptr) {
}

Folders::Folders(string name, string date, string user, Files* files)
    : name(name), date(date), user(user) {
    if (files) this->files = new Files(*files); // Глибоке копіювання
    else this->files = nullptr;
}

Folders::Folders(const Folders& other)
    : name(other.name), date(other.date), user(other.user) {
    if (other.files) this->files = new Files(*other.files);
    else this->files = nullptr;
}

Folders::Folders(Folders&& other) noexcept
    : name(move(other.name)),
    date(move(other.date)),
    user(move(other.user)) {

    this->files = other.files; // Просто копіюємо адресу вказівника
    other.files = nullptr;     // ВАЖЛИВО: зануляємо у старого об'єкта

    cout << "Folder moved" << endl;
}

Folders& Folders::operator=(const Folders& other) {
    if (this != &other) {
        delete this->files; // Очищення старої пам'яті

        this->name = other.name;
        this->date = other.date;
        this->user = other.user;

        if (other.files) this->files = new Files(*other.files);
        else this->files = nullptr;
    }
    return *this;
}

Folders::~Folders() {
    delete files;
    cout << "Folder destroyed" << endl;
}

void Folders::display() const {
    cout << "Name: " << name << ", Date: " << date << ", User: " << user << endl;
    if (files) {
        cout << "  File: ";
        files->display();
    }
}

ZipFolder::ZipFolder(string name, string date, string user,
    Files* files, double compressionRatio)
    : Folders(name, date, user, files), compressionRatio(compressionRatio) {
}

void ZipFolder::display() const {
    Folders::display(); // Виклик методу батька
    cout << "  Compression: " << compressionRatio << "x" << endl;
}