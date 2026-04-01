#ifndef FOLDERS_H
#define FOLDERS_H
#include <string>
#include "Files.h"
using namespace std;

class Folders {
private:
    string name;
    string date;
    string user;

    Files* files;

public:
    Folders();
    Folders(string name, string date, string user);
    Folders(string name, string date, string user, Files* files);

    Folders(const Folders& other);
    Folders(Folders&& other) noexcept;
    Folders& operator=(const Folders& other);

    virtual ~Folders();
    virtual void display() const;
};

class ZipFolder : public Folders {
private:
    double compressionRatio;

public:
    ZipFolder(string name, string date, string user,
        Files* files, double compressionRatio);

    void display() const override;
};
#endif