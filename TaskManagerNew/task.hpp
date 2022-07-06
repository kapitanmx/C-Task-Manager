#include <iostream>

#ifndef __IDGENERATOR
#include "id_generator.hpp"
#endif

using namespace std;

class Task {
	private: 
		uint32_t ID;
		string Title, Description, InitDate, ExpDate;
	public:
		Task CreateTask(string, string, string, string);
		Task GetTaskByID(uint32_t);
		Task DisplayAllTasks();
		void EditTask(uint32_t);
		void DeleteTask(uint32_t);
};
