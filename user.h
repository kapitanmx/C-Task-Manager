#include <iostream>
#include "id_generator.h"
#include "task.h"
using namespace std;


class User
{
	private:
		uint32_t ID;
		string Name, LastName, Email, Password;
		Task[] tasks = task.tasks;
		int taskAmount;

	public:
		void CreateUser(string, string, string, string);
		void Login(string, string);
		User FindUserById(uint32_t);
		void ShowUserTasks();
		void EditUser();
		void DeleteUser(uint32_t);
};