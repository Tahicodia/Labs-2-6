#include "Folders.h"
#include <iostream>
#include <utility>
using namespace std;

// --- Конструктори Folder ---

Folder::Folder() : name("Homeworks"), date("04.03.2026"), user("Admin"), files(nullptr) {}

Folder::Folder(string name, string date, string user)
    : name(name), date(date), user(user), files(nullptr) {
}

Folder::Folder(string name, string date, string user, Files* files)
    : name(name), date(date), user(user) {
    if (files) this->files = files->clone();
    else this->files = nullptr;
}

Folder::Folder(const Folder& other)
    : name(other.name), date(other.date), user(other.user) {
    if (other.files) this->files = other.files->clone();
    else this->files = nullptr;
}

Folder::Folder(Folder&& other) noexcept
    : name(move(other.name)),
    date(move(other.date)),
    user(move(other.user)) {
    this->files = other.files;
    other.files = nullptr;
    cout << "Folder moved" << endl;
}

// --- Оператори та деструктор ---

Folder& Folder::operator=(const Folder& other) {
    if (this != &other) {
        delete this->files;
        this->user = other.user;
        this->date = other.date;
        this->name = other.name;
        if (other.files) this->files = other.files->clone();
        else this->files = nullptr;
    }
    return *this;
}

Folder::~Folder() {
    delete files;
    cout << "Folder destroyed" << endl;
}

// --- МЕТОДИ ВИВОДУ (Оновлені) ---

void Folder::display() const {
    // Додаємо заголовок, як на скріншоті
    cout << "[Folder]\n";
    cout << "Name: " << name << ", Date: " << date << ", User: " << user << endl;
    if (files) {
        cout << "  File: ";
        files->display();
    }
}

ZipFolder::ZipFolder(string name, string date, string user,
    Files* files, double compressionRatio)
    : Folder(name, date, user, files), compressionRatio(compressionRatio) {
}

void ZipFolder::display() const {
    // Додаємо заголовок для архіву
    cout << "[Zip Folder]\n";

    // Викликаємо базовий метод, щоб вивести загальні дані (name, date, user)
    // Якщо ви не хочете, щоб Folder::display() дублював заголовок [Folder] всередині ZipFolder,
    // можна вивести поля вручну або створити допоміжний метод.
    Folder::display();

    cout << "  Compression: " << compressionRatio << "x" << endl;
}