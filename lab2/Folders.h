#ifndef FOLDER_H
#define FOLDER_H
#include <string>
#include "Files.h"
using namespace std;

class Folder {
private:
    string name;
    string date;
    string user;

    Files* files;

public:
    Folder();
    Folder(string name, string date, string user);
    Folder(string name, string date, string user, Files* files);

    Folder(const Folder& other);
    Folder(Folder&& other) noexcept;
    Folder& operator=(const Folder& other);

    virtual ~Folder();
    virtual void display() const;
};

class ZipFolder : public Folder {
private:
    double compressionRatio;

public:
    ZipFolder(string name, string date, string user,
        Files* files, double compressionRatio);

    void display() const override;
};
#endif
