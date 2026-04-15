#define NOMINMAX
#include "Folders.h"
#include "Files.h"
#include "User.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <limits>

using namespace std;

vector<User> users;
vector<Folder> folders;

//  РОБОТА З ФАЙЛАМИ 
void loadData() {
    ifstream uFile("users.txt");
    if (uFile) {
        users.clear();
        while (true) {
            User u;
            u.loadFromFile(uFile);
            if (uFile.fail()) break;
            users.push_back(u);
        }
        uFile.close();
    }

    ifstream fFile("folders_data.txt");
    if (fFile) {
        folders.clear();
        while (true) {
            Folder f;
            f.loadFromFile(fFile);
            if (fFile.fail()) break;
            folders.push_back(f);
        }
        fFile.close();
    }
}

void saveFolders() {
    ofstream fFile("folders_data.txt");
    for (const auto& f : folders) {
        f.saveToFile(fFile);
    }
    fFile.close();
}

//  ФУНКЦІЇ МЕНЮ
void showContent() {
    cout << "\n--- AVAILABLE CONTENT ---\n";
    if (folders.empty()) cout << "No folders found.\n";
    for (const auto& f : folders) {
        f.display();
    }
}

void createFolder(Admin& admin) {
    string fName, fDate;
    cout << "Folder Name: "; cin >> fName;
    cout << "Date (dd.mm.yyyy): "; cin >> fDate;

    Folder newFolder(fName, fDate, "Admin");
    folders.push_back(newFolder);

    saveFolders();
    admin.logAction("Created folder: " + fName);
    cout << "Folder saved!\n";
}

int getSafeInt() {
    int val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Помилка! Введіть число: ";
    }
    return val;
}

//  МЕНЮ 
void adminMenu(Admin& admin) {
    int choice;
    do {
        cout << "\n--- ADMIN MENU ---\n";
        cout << "1. Додати користувача\n";
        cout << "2. Показати користувачів\n";
        cout << "3. Створити нову папку (Контент)\n";
        cout << "4. Показати весь контент\n";
        cout << "0. Назад\n";
        cout << "Ваш вибір: ";
        choice = getSafeInt();

        switch (choice) {
        case 1: {
            string n, c, g;
            cout << "Name: "; cin >> n;
            cout << "Course: "; cin >> c;
            cout << "Group: "; cin >> g;
            User u(n, c, g);
            users.push_back(u);
            admin.addUserToFile(u);
            break;
        }
        case 2:
            cout << "\n--- USERS ---\n";
            for (const auto& u : users) u.display();
            break;
        case 3:
            createFolder(admin);
            break;
        case 4:
            showContent();
            break;
        }
    } while (choice != 0);
}

void userMenu() {
    int choice;
    do {
        cout << "\n--- USER MENU ---\n";
        cout << "1. Показати список користувачів\n";
        cout << "2. Переглянути контент (папки)\n";
        cout << "0. Назад\n";
        cout << "Ваш вибір: ";
        choice = getSafeInt();

        switch (choice) {
        case 1:
            for (const auto& u : users) u.display();
            break;
        case 2:
            showContent();
            break;
        }
    } while (choice != 0);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    loadData();

    int choice;
    string password;
    const string ADMIN_PASSWORD = "1234";
    Admin admin("Admin", "System", "000", "Root");

    do {
        cout << "\n====== CLOUD SYSTEM ======\n";
        cout << "1. Адміністратор\n";
        cout << "2. Користувач\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        choice = getSafeInt();

        try {
            if (choice == 1) {
                cout << "Пароль: ";
                cin >> password;
                if (password == ADMIN_PASSWORD) adminMenu(admin);
                else throw runtime_error("Wrong Password!");
            }
            else if (choice == 2) {
                userMenu();
            }
        }
        catch (const exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
    } while (choice != 0);

    return 0;
}