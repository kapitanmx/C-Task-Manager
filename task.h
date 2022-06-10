#include <iostream>
#include "id_generator.h"
using namespace std;

class Task {
	private: 
		uint32_t ID;
		string Title, Description, InitDate, ExpDate;
	public:
		void CreateTask(string, string, string, string);
		Task FindTaskByID(uint32_t);
		Task DisplayAllTasks();
		void EditTask(uint32_t);
		void DeleteTask(uint32_t);
};
