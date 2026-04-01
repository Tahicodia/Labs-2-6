#ifndef FILES_H
#define FILES_H

#include <string>

using namespace std;

class Files {
protected: // protected, щоб MediaFile бачив поля
    string name;
    string extension;
    int size;

public:
    Files();
    Files(string name, string extension, int size);

    // ПУНКТ 6: Copy + Move + operator=
    Files(const Files& other);
    Files(Files&& other) noexcept;
    Files& operator=(const Files& other);

    virtual ~Files(); // ПУНКТ 5: Віртуальний деструктор

    virtual void display() const;
};

// Рівень 3: MediaFile (Is-A Files)
class MediaFile : public Files {
private:
    string duration;

public:
    MediaFile(string name, string extension, int size, string duration);

    void display() const override;
};

#endif