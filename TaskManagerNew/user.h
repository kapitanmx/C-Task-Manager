#include <iostream>
#include "id_generator.h"
using namespace std;


class User
{
	private:
		uint32_t ID;
		string Name, LastName, Email, Password;
		int taskAmount;

	public:
		User(string, string, string, string);
		void CreateUser(string, string, string, string);
		void Login(string, string);
		template<typename type>
		User FindUserById(uint32_t);
		void EditUser();
		void DeleteUser(string, string);
};