#include "Files.h"
#include <iostream>
#include <utility>
using namespace std;

Files::Files() : name("new_file"), extension(".txt"), size(0) {}

Files::Files(string name, string extension, int size)
    : name(name), extension(extension), size(size) {
}

Files::Files(const Files& other)
    : name(other.name), extension(other.extension), size(other.size) {
    cout << "File copied" << endl;
}

Files::Files(Files&& other) noexcept
    : name(move(other.name)),
    extension(move(other.extension)),
    size(other.size) {
    other.size = 0;
    cout << "File moved" << endl;
}

Files& Files::operator=(const Files& other) {
    if (this != &other) {
        this->name = other.name;
        this->extension = other.extension;
        this->size = other.size;
    }
    return *this;
}

Files::~Files() {
    cout << "File destroyed" << endl;
}

void Files::display() const {
    cout << name << extension << " (" << size << " KB)";
}

MediaFile::MediaFile(string name, string extension, int size, string duration)
    : Files(name, extension, size), duration(duration) {
}

MediaFile::MediaFile() : Files(), duration("00:00") {}

void MediaFile::display() const {
    Files::display();
    cout << " [Duration: " << duration << "]" << endl;
}

void MediaFile::info() const {
    cout << "Duration: " << duration << endl;
}

Files* MediaFile::clone() const {
    return new MediaFile(*this);
}

// TextFile implementation
TextFile::TextFile() : Files(), encoding("UTF-8") {}

TextFile::TextFile(string name, string extension, int size, string encoding)
    : Files(name, extension, size), encoding(encoding) {
}

void TextFile::display() const {
    Files::display();
    cout << " [Encoding: " << encoding << "]" << endl;
}

void TextFile::info() const {
    cout << "Encoding: " << encoding << endl;
}

Files* TextFile::clone() const {
    return new TextFile(*this);
}
