
#include <cstdint>
#include <iostream>
#include <sys/types.h>
#include <vector>

#ifndef __IDGENERATOR
#include "id_generator.cpp"
#endif

#ifndef __TASK
#include "task.cpp"
#endif

using namespace std;


class User
{
	private:
		uint32_t ID;
		string Name, LastName, Email, Password;
		vector <Task> tasks;
		int taskAmount;

	public:
		void CreateUser(string, string, string, string);
		void Login(string, string);
		User FindUserById(uint32_t);
		void ShowUserTasks();
		void EditUser();
		void DeleteUser(uint32_t);
};