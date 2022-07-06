#include <iostream>
#include <vector>
#include "user.hpp"

using namespace std;

int main()
{
    int option;
    User user;
    string name, lastName, email, password;
    cout << "*--------------------*\n" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "*\t\t\t\t\t*" << endl;
    }
    cout << "*\t\t Task Manager\t\t*" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "*\t\t\t\t\t*" << endl;
    }
    cout << "*--------------------*\n" << endl;

    cout << "Wybierz opcję: " << endl;
    cout << "1 - logowanie " << endl;
    cout << "2 - rejestracja " << endl;
    cin >> option;
    switch(option)
    {
        case 1:
            cout << "*Logowanie*" << endl;
            cout << "Podaj email: " << endl;
            cin >> email;
            cout << "Podaj haslo: " << endl;
            cin >> password;
            user.Login(email, password);
            break;
        case 2:
            cout << "*Rejestracja uzytkownika*" << endl;
            cout << "Podaj imie: " << endl;
            cin >> name;
            cout << "Podaj nazwisko: " << endl;
            cin >> lastName;
            cout << "Podaj email: " << endl;
            cin >> email;
            cout << "Podaj haslo: " << endl;
            cin >> password;
            user.CreateUser(name, lastName, email, password);
            break;
        default:
            cout << "Nie rozpoznano polecenia." << endl;
            break;
    }
    return 0;
}

