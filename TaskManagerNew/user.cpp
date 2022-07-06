#include <stdio.h>
#include <regex>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <task.cpp>
#include "user.hpp"

#define __USER

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

	if (name == "" && lastName == "" && email == "" && password == "") cout << "Niepoprawnie wprowadzone dane" << endl;

	if (!regex_match(password, password_regex)) cout << "Haslo musi zawierac co najmniej 8 znakow, w tym jedna duza litere, jedna mala litere i jedna cyfre" << endl;

	if (!regex_match(email, email_regex)) cout << "Nieprawidlowy zapis adresu mailowego" << endl;

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
	int select, opt;
	string title, description, initDate, expDate, pass, keyword;

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
	cout << "Zalogowano uzytkownika: " << user->Name << user->LastName << endl;
	cout << "Wybierz opcje: " << endl;
	cout << "1 - Wyswietl dane uzytkownika\n 2 - Zmien dane uzytkownika\n 3 - Usun konto\n 4 - Wyswietl wszystkie zadania\n 5 - Znajdz zadanie\n 6 - Dodaj zadanie\n 7 - Usun zadanie\n" << endl;
	cin >> select;
	switch(select)
	{
		case 1:
			cout << "Dane uzytkownika:\n Imie: " << user->Name << " \nNazwisko: " << user->LastName << " \nEmail: " << user->Email;
		case 2:
			cout << "Zmiana danych" << endl;
		case 3:
			cout << "Usuwanie konta" << endl;
			cout << "Podaj haslo" << endl;
			cin >> pass;
			if (pass == user->Password)
			{
				DeleteUser(pass);
				cout << "Konto usuniete" << endl;
				break;
			}
			break;
		case 4:
			cout << "Wyswietl zadania: " << endl;
			break;
		case 5:
			cout << "Podaj slowo kluczowe (tytul zadania, data rozpoczecia/zakonczenia w formacie DD/MM/RRRR" << endl;
			cin >> keyword;

		case 6:
			cout << "Utwórz nowe zadanie" << endl;
			cout << "Podaj tytul" << endl;
			cin >> title;
			cout << "Podaj opis" << endl;
			cin >> description;
			cout << "Podaj date rozpoczecia zadania (DD/MM/RRRR)" << endl;
			cin >> initDate;
			cout << "Podaj date zakonczenia zadania (DD/MM/RRRR)" << endl;
			cin >> expDate;
			user->tasks.push_back(Task::CreateTask(title, description, initDate, expDate));
		case 7:
		default:
			break;
	}
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

void User::EditUser(uint32_t ID)
{
	User user = FindUserById(ID);
	int wybor;
	string name, lastName, email, password;
	cout << "Zmien dane uzytkownika:\n 1 - Zmien imie\n 2 - Zmien nazwisko\n 3 - Zmien adres email\n 4 - zmien haslo" << endl;
	cin >> wybor;
}

void User::DeleteUser(string password)
{
	for (int i = 0; i < usersArrSize(); i++)
	{
		if (users[i].Password == password)
		{
			users.erase(users[i]);
			break;
		}
	}
}
