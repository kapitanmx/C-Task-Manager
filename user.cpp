#include "user.h"
#include "id_generator.h"
#include <regex>
#include <vector>
#include <stdlib.h>
#include <time.h>

vector <User> users;

int usersArrSize()
{
	return sizeof(users) / sizeof(users[0]);
}


void User::CreateUser(string name, string lastName, string email, string password) 
{
	User* newUser;
	uint32_t ID;
	regex password_regex("^(? = .*[A - Za - z])(? = .*\d)[A - Za - z\d]{8,}$");
	regex email_regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	if (name == "" && lastName == "" && email == "" && password == "") 
	{
		cout << "Niepoprawnie wprowadzone dane" << endl;
	}

	if (!regex_match(password, password_regex))
	{
		cout << "Haslo musi zawierac co najmniej 8 znakow, w tym jedna duza litere, jedna mala litere i jedna cyfre" << endl;
	}

	if (!regex_match(email, email_regex))
	{
		cout << "Nieprawidlowy zapis adresu mailowego" << endl;
	}

	newUser->ID = ID;
	newUser->Name = name;
	newUser->LastName = lastName;
	newUser->Email = email;
	newUser->Password = password;
	users.push_back(*newUser);
}

void User::Login(string email, string password) 
{
	User* user;

	for (int i = 0; i < usersArrSize(); i++) 
	{
		if (users[i].Email == email && users[i].Password == password)
		{
			user->Name = users[i].Name;
			user->LastName = users[i].LastName;
			user->Email = users[i].Email;
			user->Password = users[i].Password;
			break;
		}
		else 
		{
			cout << "Nieprawidlowy adres email lub haslo. Sprobuj ponownie" << endl;
			continue;
		}
	}
	cout << "Zalogowano u¿ytkownika: " << user->Name << user->LastName << endl;
}

User User::FindUserById(uint32_t ID)
{
	for (int i = 0; i < usersArrSize(); i++)
	{
		if (users[i].ID == ID)
		{
			return users[i];
			break;
		}
	}
}

void User::EditUser()
{
	uint32_t ID;
	User user = FindUserById(ID);
	int wybor;
	string name, lastName, email, password;
	cout << "Zmien dane uzytkownika:\n 1 - Zmien imie\n 2 - Zmien nazwisko\n 3 - Zmien adres email\n 4 - zmien haslo" << endl;
	cin >> wybor;
}

void User::DeleteUser(uint32_t ID)
{
	for (int i = 0; i < usersArrSize(); i++)
	{
		if (users[i].ID == ID)
		{
			users.erase(users[i]);
			break;
		}
	}
}