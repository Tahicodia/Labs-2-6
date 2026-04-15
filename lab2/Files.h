#ifndef FILES_H
#define FILES_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Files {
protected:
    string name;
    string extension;
    int size;

public:
    Files();
    Files(string name, string extension, int size);

    Files(const Files& other);
    Files(Files&& other) noexcept;
    Files& operator=(const Files& other);

    virtual ~Files();

    virtual void display() const;

    virtual void info() const = 0;
    virtual Files* clone() const = 0;

    //  ДОДАНО 
    virtual void saveToFile(ofstream& out) const;
    virtual void loadFromFile(ifstream& in);
};

class MediaFile final : public Files {
private:
    string duration;

public:
    MediaFile();
    MediaFile(string name, string extension, int size, string duration);

    void display() const override;
    void info() const override;
    Files* clone() const override;

    //  ДОДАНО 
    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
};

class TextFile : public Files {
private:
    string encoding; 

public:
    TextFile();
    TextFile(string name, string extension, int size, string encoding);

    void display() const override;
    void info() const override;
    Files* clone() const override;

    //  ДОДАНО
    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
};

#endif