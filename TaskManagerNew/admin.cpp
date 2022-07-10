#include "admin.hpp"
#include <iostream>
#include <regex>
#include <vector>
using namespace std;

vector <Admin> admins;

int adminArrSize()
{
    return sizeof(admins) / sizeof(admins[0]);
}

Admin Admin::CreateAccount(string email, string password)
{
    Admin admin;
    regex password_regex("^(? = .*[A - Za - z])(? = .*\d)[A - Za - z\d]{8,}$");
	regex email_regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    if (email == "" && password == "") cout << "Dane nie moga byc puste!" << endl;
    if (!regex_match(email, email_regex)) cout << "Nieprawidlowy zapis adresu mailowego" << endl;
    if (!regex_match(password, password_regex)) cout << "Haslo musi zawierac co najmniej 8 znakow, w tym jedna duza litere, jedna mala litere i jedna cyfre" << endl;

    admin->email = email; 
    admin->password = password;
    return admin;
}

void Admin::Login(string email, string password)
{
    Admin admin;
    for (int i = 0; i < adminArrSize(); i++)
    {
        if (admins[i].email == email && admins[i].password == password)
        {
            admin->ID = admins[i].ID;
            admin->email = admins[i].email;
            admin->password = admins[i].password;
            break;
        }
    }
    return admin;
}

void Admin::Delete(uint32_t ID)
{
    for (int i = 0; i < adminArrSize(); i++)
    {
        if (admins[i].ID == ID) 
        {
            admins.erase(admins[i]);
            break;
        }
    }
}







