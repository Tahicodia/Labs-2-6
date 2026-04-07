#include "Folders.h"
#include "Files.h"
#include "User.h"
#include <iostream>

using namespace std;

int main() {
    User u1;
    User u2("Igor Aheienko", "Software Engineering", "143a");
    Admin a1("Damir Rozhman", "Software Engineering", "143a", "System Moderator");
    Admin a2("Igor Aheienko", "Software Engineering", "143a", "Software Architector");
    MediaFile fi1;
    MediaFile fi2("Lab_OOP", ".mp3", 3200, "30");
    Folder f1;
    Folder f2("Project", "01.04.2026", "Damir", &fi2);
    Person* ptr = &u2;

    cout << "Total Users: " << User::getCount() << endl;

    cout << "========USERS========" << endl;
    u1.display(); cout << endl;
    u2.display(); cout << endl;
    cout << "========ADMINS========" << endl;
    a1.display(); cout << endl;
    a2.display(); cout << endl;
    cout << "========FOLDERS========" << endl;
    f1.display(); cout << endl;
    f2.display(); cout << endl;
    cout << "========Static Method Binding========" << endl;
    ptr->testStatic();

    // Демонстрація поліморфізму через посилання на батьківський клас
    Person& pref = u2; // викличе User::display() завдяки virtual
    cout << "\nPolymorphism via reference (Person&): ";
    pref.display();

    // Демонстрація поліморфізму через посилання для Files
    Files& fref = fi2; // MediaFile реалізує display() і info()
    cout << "\nPolymorphism via reference (Files&): ";
    fref.display();
    fref.info();

    // Використання інтерфейсу Files на іншому класі (TextFile)
    TextFile tf("Readme", ".txt", 5, "UTF-8");
    Files& finter = tf;
    cout << "\nUsing Files interface on TextFile: ";
    finter.display();
    finter.info();

    return 0;
}