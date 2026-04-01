#ifndef FILES_H
#define FILES_H

#include <string>

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
};

class MediaFile : public Files {
private:
    string duration;

public:
    MediaFile(string name, string extension, int size, string duration);

    void display() const override;
};

#endif