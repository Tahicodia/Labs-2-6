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
    Files fi1;
    Files fi2("Lab_OOP", ".cpp", 20);
    Folders f1;
    Folders f2("Project", "01.04.2026", "Damir", &fi2);
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

    return 0;
}