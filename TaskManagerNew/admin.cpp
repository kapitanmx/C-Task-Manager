#include "admin.hpp"
#include <iostream>
#include <regex>

Admin Admin::CreateAccount(email, password)
{
    Admin *admin;
    regex password_regex("^(? = .*[A - Za - z])(? = .*\d)[A - Za - z\d]{8,}$");
	regex email_regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    if (email == "" && password == "") cout << "Dane nie moga byc puste!" << endl;
    if (!regex_match(email, email_regex)) cout << "Nieprawidlowy zapis adresu mailowego" << endl;
    if (!regex_match(password, password_regex)) cout << "Haslo musi zawierac co najmniej 8 znakow, w tym jedna duza litere, jedna mala litere i jedna cyfre" << endl;

    admin->email = email; 
    admin->password = password;
    return admin;
}

