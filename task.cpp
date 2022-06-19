#include "task.h"
#include "id_generator.h"
#include <regex>
#include <vector>
#include <stdlib.h>

vector <Task> tasks;

int tasksArrSize() 
{
	return sizeof(tasks) / sizeof(tasks[0]);
}

void Task::CreateTask(string title, string description, string initDate, string expDate)
{
	Task* task;
	regex dateRegex("\s+(?:0[1-9]|[12][0-9]|3[01])[-/.](?:0[1-9]|1[012])[-/.](?:19\d{2}|20[01][0-9]|2020)\b");
	if (title == "" && description == "" && initDate == "" && expDate == "")
	{
		cout << "Tytul oraz opis nie moga byc puste" << endl;
	}

	if (!regex_match(initDate, dateRegex))
	{
		cout << "Niewlasciwy format daty rozpoczecia zadania" << endl;
	}

	if (!regex_match(expDate, dateRegex)) 
	{
		cout << "Niewlasciwy format daty zakonczenia zadania" << endl;
	}

	task->Title = title;
	task->Description = description;
	task->InitDate = initDate;
	task->ExpDate = expDate;

	tasks.push_back(*task);
}


Task Task::FindTaskByID(uint32_t ID)
{
	for (int i = 0; i < tasksArrSize(); i++)
	{
		if (tasks[i].ID == ID)
		{
			return tasks[i];
			break;
		}
	}
}

Task Task::DisplayAllTasks() 
{
	for (int i = 0; i < tasksArrSize(); i++)
	{
		return tasks[i];
	}
}


void Task::EditTask(uint32_t ID)
{
	Task task = FindTaskByID(ID);
	int choice;
	string title, description, initDate, expDate;
	regex dateRegex("\s+(?:0[1-9]|[12][0-9]|3[01])[-/.](?:0[1-9]|1[012])[-/.](?:19\d{2}|20[01][0-9]|2020)\b");

	cout << "Wybierz opcje: \n" << endl;
	cout << "1 - Zmien tytul\n 2 - Zmien opis\n 3 - Zmien date rozpoczecia\n 4 - Zmien date zakonczenia " << endl;

	switch (choice) {
		case 1:
			cout << "Podaj nowy tytul: " << endl;
			cin >> title;
			if (title == "")
			{
				cout << "Tytul nie moze byc pusty" << endl;
				break;
			}
			task.Title = title;
			break;
		case 2:
			cout << "Podaj nowy opis: " << endl;
			cin >> description;
			if (description == "")
			{
				cout << "Opis nie moze byc pusty" << endl;
				break;
			}
			task.Description = description;
			break;
		case 3:
			cout << "Ustaw nowa date rozpoczecia zadania " << endl;
			cin >> initDate;
			if (initDate == "")
			{
				cout << "Data nie moze byc pusta" << endl;
				break;
			}
			if (!regex_match(initDate, dateRegex))
			{
				cout << "Wprowadzono zly format daty. Prawidlowy format: DD\MM\RRRR" << endl;
				break;
			}
			task.InitDate = initDate;
			break;
		case 4:
			cout << "Ustaw nowa date zakonczenia zadania " << endl;
			cin >> expDate;
			if (expDate == "")
			{
				cout << "Data nie moze byc pusta" << endl;
				break;
			}
			if (!regex_match(expDate, dateRegex))
			{
				cout << "Wprowadzono zly format daty. Prawidlowy format: DD\MM\RRRR" << endl;
				break;
			}
			task.ExpDate = expDate;
			break;
		default:
			cout << "Nie wybrano zadnej opcji." << endl;
			break;
	}

}

void Task::DeleteTask(uint32_t ID)
{
	for (int i = 0; i < tasksArrSize(); i++)
	{ 
		if (tasks[i].ID == ID)
		{
			tasks.erase(tasks[i]);
			break;
		}
	}
}

