#include <iostream>

#ifndef __IDGENERATOR
#include "id_generator.cpp"
#endif

using namespace std;
class Task {
	private: 
		uint32_t ID;
		string Title, Description, InitDate, ExpDate;
	public:
		static void CreateTask(string, string, string, string);
		Task FindTaskByID(uint32_t);
		Task DisplayAllTasks();
		void EditTask(uint32_t);
		void DeleteTask(uint32_t);
};
