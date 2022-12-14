#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include <string>

#define SECONDS_IN_WEEK 604800
#define SECONDS_IN_MONTH 2419200

struct Task {
	std::string name;
	int priority;
	std::string discription;
	struct {
		int day;
		int month;
		int year;
		int hour;
		int minutes;
	}date;
};

void main_menu(Task* task);

void add_task(Task* task, int position);
void show_all(Task* task, int size);
void edit_task(Task* task);
Task* delete_task(Task* task, int size);

void find_by_name(Task* task, int size);
void find_by_priority(Task* task, int size);
void find_by_discription(Task* task, int size);
void find_by_date_and_time(Task* task, int size);

bool operator >(Task, Task);
void sort_by_date(Task* task, int size);// not ready

void show_with_priority(Task* task, int size);
void save_to_file(Task* task, int size);


#endif