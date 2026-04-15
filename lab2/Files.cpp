#include "Files.h"
#include <iostream>
#include <utility>
#include <fstream>
#include <stdexcept>

using namespace std;

//  РЕАЛІЗАЦІЯ БАЗОВОГО КЛАСУ Files 

Files::Files() : name("untitled"), extension("txt"), size(0) {}

Files::Files(string name, string extension, int size)
    : name(name), extension(extension), size(size) {
}

Files::Files(const Files& other)
    : name(other.name), extension(other.extension), size(other.size) {
}

Files::Files(Files&& other) noexcept
    : name(move(other.name)), extension(move(other.extension)), size(other.size) {
    other.size = 0;
}

Files& Files::operator=(const Files& other) {
    if (this != &other) {
        name = other.name;
        extension = other.extension;
        size = other.size;
    }
    return *this;
}

Files::~Files() {} // Обов'язково для віртуального деструктора

void Files::display() const {
    cout << "File: " << name << "." << extension << " (" << size << " KB)";
}

void Files::saveToFile(ofstream& out) const {
    out << name << "|" << extension << "|" << size;
}

void Files::loadFromFile(ifstream& in) {
    string sizeStr;
    getline(in, name, '|');
    getline(in, extension, '|');
    getline(in, sizeStr, '|'); // Читаємо до роздільника
    try { size = stoi(sizeStr); }
    catch (...) { size = 0; }
}

//  РЕАЛІЗАЦІЯ MediaFile 

MediaFile::MediaFile() : Files("video", "mp4", 0), duration("00:00") {}

MediaFile::MediaFile(string name, string extension, int size, string duration)
    : Files(name, extension, size), duration(duration) {
}

void MediaFile::display() const {
    Files::display();
    cout << " [Duration: " << duration << "]";
}

void MediaFile::info() const {
    cout << "Type: Media File, Name: " << name << ", Duration: " << duration << endl;
}

Files* MediaFile::clone() const {
    return new MediaFile(*this);
}

void MediaFile::saveToFile(ofstream& out) const {
    out << "MEDIA|";
    Files::saveToFile(out);
    out << "|" << duration << endl;
}

void MediaFile::loadFromFile(ifstream& in) {
    Files::loadFromFile(in);
    getline(in, duration);
}

// РЕАЛІЗАЦІЯ TextFile 
TextFile::TextFile() : Files("document", "txt", 0), encoding("UTF-8") {}

TextFile::TextFile(string name, string extension, int size, string encoding)
    : Files(name, extension, size), encoding(encoding) {
}

void TextFile::display() const {
    Files::display();
    cout << " [Encoding: " << encoding << "]";
}

void TextFile::info() const {
    cout << "Type: Text File, Name: " << name << ", Encoding: " << encoding << endl;
}

Files* TextFile::clone() const {
    return new TextFile(*this);
}

void TextFile::saveToFile(ofstream& out) const {
    out << "TEXT|";
    Files::saveToFile(out);
    out << "|" << encoding << endl;
}

void TextFile::loadFromFile(ifstream& in) {
    Files::loadFromFile(in);
    getline(in, encoding);
}