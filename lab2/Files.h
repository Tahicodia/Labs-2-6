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

	virtual void info() const = 0; // Чисто віртуальна функція для отримання додаткової інформації про файл
    virtual Files* clone() const = 0; // Поліморфне клонування
};

class MediaFile final : public Files { // final - це заборона на наслідування від цього класу
private:
    string duration;

public:
    MediaFile();
    MediaFile(string name, string extension, int size, string duration);
    void display() const override;
    void info() const override; // Реалізація чисто віртуальної функції
    Files* clone() const override;
};

// Додатковий клас, що реалізує інтерфейс Files (щоб показати інтерфейс на різних класах)
class TextFile : public Files {
private:
    string encoding;

public:
    TextFile();
    TextFile(string name, string extension, int size, string encoding);
    void display() const override;
    void info() const override;
    Files* clone() const override;
};

#endif