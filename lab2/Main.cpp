#include "Folders.h"
#include "Files.h"
#include "User.h"
#include <iostream>

using namespace std;

int main() {
    User u1;
    User u2("Igor Aheienko", "Software Engineering", "143a");
    Admin a1("Damir Rozhman", "Software Engineering", "143a", "System Moderator");
    Files fi2("Lab_OOP", ".cpp", 20);
    Folders f2("Project", "01.04.2026", "Damir", &fi2);
    cout << "Total Users: " << User::getCount() << endl;

    u2.display(); cout << endl;
    a1.display(); // Тут виведеться роль адміна
    f2.display();

    return 0;
}