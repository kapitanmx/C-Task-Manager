#include <cstdint>
#include <iostream>
#include <sys/types.h>

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
		int taskAmount;
		Task *tasks;
	public:
		void CreateUser(string, string, string, string);
		void Login(string, string);
		User FindUserById(uint32_t);
		void ShowUserTasks();
		void EditUser(uint32_t);
		void DeleteUser(string);
		
};