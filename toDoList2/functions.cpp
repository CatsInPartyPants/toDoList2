#include "functions.h"
#include <iostream>


bool operator >(Task task1, Task task2)
{
	if (task1.date.year > task2.date.year)
		return true;
	else if (task1.date.month > task2.date.month)
		return true;
	else if (task1.date.day > task2.date.day)
		return true;
	return false;
}

void main_menu(Task* task)
{
	int choise;
	static int current_position = 0;
	do {
		std::cout << "\t\t\"To-Do List\"\n";
		std::cout << "Main menu:\n\n";
		std::cout << "[1] Add a new task to the to-do list.\n";
		std::cout << "[2] Show tasks in the to-do list.\n";
		std::cout << "[3] Delete a task from the to-do list.\n";
		std::cout << "[4] Edit a task in the to-do list.\n";
		std::cout << "[5] Find by name.\n";
		std::cout << "[6] Find by priority.\n";
		std::cout << "[7] Find by discription.\n";
		std::cout << "[8] Find by date and time.\n";
		std::cout << "[0] Exit.\n";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			system("CLS");
			std::cin.get();
			add_task(task, current_position);
			current_position++;
			break;
		case 2:
			system("CLS");
			show_all(task, current_position);
			break;
		case 3:
			system("CLS");
			task = delete_task(task, current_position);
			current_position--;
			break;
		case 4:
			system("CLS");
			edit_task(task);
			break;
		case 5:
			system("CLS");
			find_by_name(task, current_position);
			break;
		case 6:
			system("CLS");
			find_by_priority(task, current_position);
			break;
		case 7:
			find_by_discription(task, current_position);
		case 8:
			find_by_date_and_time(task, current_position);
		case 0:
			break;
		}
	} while (choise != 0);
}

void add_task(Task* task, int position)
{
	std::cout << "Enter task name: " << std::endl;
	std::getline(std::cin, task[position].name);
	std::cout << "Enter task priority(3 - high, 2 - standart, 1 - low): " << std::endl;
	std::cin >> task[position].priority;
	std::cin.get();
	std::cout << "Enter task discription: " << std::endl;
	std::getline(std::cin, task[position].discription);

	std::cout << "Now enter task date. " << std::endl;
	std::cout << "First of all enter task day: " << std::endl;
	std::cin >> task[position].date.day;
	std::cout << "Enter task month: " << std::endl;
	std::cin >> task[position].date.month;
	std::cout << "Enter task year: " << std::endl;
	std::cin >> task[position].date.year;
	std::cout << "Enter task hour: " << std::endl;
	std::cin >> task[position].date.hour;
	std::cout << "Enter task minutes: " << std::endl;
	std::cin >> task[position].date.minutes;
	std::cin.get();
}

void show_all(Task* task, int size) // need show for month and week
{
	int user_choise;

	std::cout << "For show all tasks press 1\n";
	std::cout << "For show tasks for a day press 2\n";
	std::cout << "For show task for a week press 3\n";
	std::cout << "For show tasks for a month press 4\n";
	std::cin >> user_choise;
	switch (user_choise) 
	{
	case 1:
		if (size == 0)
		{
			std::cout << "To-do list is empty!" << std::endl;
		}
		for (int i = 0; i < size; i++)
		{
			std::cout << std::endl;
			std::cout << i + 1 << ". ";
			std::cout << "Name of the task: " << task[i].name << std::endl;
			std::cout << "Date:" << task[i].date.day << "." << task[i].date.month << "." << task[i].date.year << " " << task[i].date.hour << ":" << task[i].date.minutes << std::endl;
			std::cout << "Discription: " << task[i].discription << std::endl;
			std::cout << "Priority: " << task[i].priority << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		break;
	case 2:
		if (size == 0)
		{
			std::cout << "To-do list is empty!" << std::endl;
			break;
		}
		int day_for_find, month_for_find, year_for_find;
		std::cout << "Enter task date for find. " << std::endl;
		std::cout << "First of all enter task day: " << std::endl;
		std::cin >> day_for_find;
		std::cout << "Enter task month: " << std::endl;
		std::cin >> month_for_find;
		std::cout << "Enter task year: " << std::endl;
		std::cin >> year_for_find;
		std::cin.get();

		for (int i = 0; i < size; i++)
		{
			if (task->date.day == day_for_find && task->date.month == month_for_find && task->date.year == year_for_find)
			{
				std::cout << std::endl;
				std::cout << i + 1 << ". ";
				std::cout << "Name of the task: " << task[i].name << std::endl;
				std::cout << "Date:" << task[i].date.day << "." << task[i].date.month << "." << task[i].date.year << " " << task[i].date.hour << ":" << task[i].date.minutes << std::endl;
				std::cout << "Discription: " << task[i].discription << std::endl;
				std::cout << "Priority: " << task[i].priority << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
			}
		}
		break;
	case 3:
		//here show for a week
		break;
	case 4:
		//here show for a month
		break;
	}
	
}

void edit_task(Task* task) 
{
	int position;
	std::cout << "What task do you want to edit?";
	std::cin >> position;
	position--;
	std::cin.get();
	std::cout << "Enter task name: " << std::endl;
	std::getline(std::cin, task[position].name);
	std::cout << "Enter task priority(3 - high, 2 - standart, 1 - low): " << std::endl;
	std::cin >> task[position].priority;
	std::cin.get();
	std::cout << "Enter task discription: " << std::endl;
	std::getline(std::cin, task[position].discription);

	std::cout << "Now enter task date. " << std::endl;
	std::cout << "First of all enter task day: " << std::endl;
	std::cin >> task[position].date.day;
	std::cout << "Enter task month: " << std::endl;
	std::cin >> task[position].date.month;
	std::cout << "Enter task year: " << std::endl;
	std::cin >> task[position].date.year;
	std::cout << "Enter task hour: " << std::endl;
	std::cin >> task[position].date.hour;
	std::cout << "Enter task minutes: " << std::endl;
	std::cin >> task[position].date.minutes;
	std::cin.get();
}

Task* delete_task(Task* task, int size)
{
	int position;
	Task* tmp = new Task[100];
	std::cout << "What task do you want to delete?";
	std::cin >> position;
	position--;
	for (int i = 0, j = 0; i < size; )
	{
		if (j == position)
		{
			j++;
		}
		else
		{
			tmp[i] = task[j];
			i++;
			j++;
		}
	}
	delete[]task;
	return tmp;
}

void find_by_name(Task* task, int size)
{
	std::string name_for_find;
	std::cin.get();
	std::cout << "Please enter the name of the task for find?";
	getline(std::cin, name_for_find);
	for (int i = 0; i < size; i++)
	{
		if (task[i].name == name_for_find)
		{
			std::cout << std::endl;
			std::cout << i + 1 << ". ";
			std::cout << "Name of the task: " << task[i].name << std::endl;
			std::cout << "Date:" << task[i].date.day << "." << task[i].date.month << "." << task[i].date.year << " " << task[i].date.hour << ":" << task[i].date.minutes << std::endl;
			std::cout << "Discription: " << task[i].discription << std::endl;
			std::cout << "Priority: " << task[i].priority << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
}

void find_by_priority(Task* task, int size)
{
	int priority_for_find;
	std::cin.get();
	std::cout << "Please enter the priority of the task for find?";
	std::cin >> priority_for_find;
	for (int i = 0; i < size; i++)
	{
		if (task[i].priority == priority_for_find)
		{
			std::cout << std::endl;
			std::cout << i + 1 << ". ";
			std::cout << "Name of the task: " << task[i].name << std::endl;
			std::cout << "Date:" << task[i].date.day << "." << task[i].date.month << "." << task[i].date.year << " " << task[i].date.hour << ":" << task[i].date.minutes << std::endl;
			std::cout << "Discription: " << task[i].discription << std::endl;
			std::cout << "Priority: " << task[i].priority << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
}

void find_by_discription(Task* task, int size)
{
	std::string discription_for_find;
	std::cin.get();
	std::cout << "Please enter the discription of the task for find?";
	getline(std::cin, discription_for_find);
	for (int i = 0; i < size; i++)
	{
		if (task[i].name == discription_for_find)
		{
			std::cout << std::endl;
			std::cout << i + 1 << ". ";
			std::cout << "Name of the task: " << task[i].name << std::endl;
			std::cout << "Date:" << task[i].date.day << "." << task[i].date.month << "." << task[i].date.year << " " << task[i].date.hour << ":" << task[i].date.minutes << std::endl;
			std::cout << "Discription: " << task[i].discription << std::endl;
			std::cout << "Priority: " << task[i].priority << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
}

void find_by_date_and_time(Task* task, int size)
{
	int day_for_find, month_for_find, year_for_find, hour_for_find, minutes_for_find;
	std::cout << "Enter task date for find. " << std::endl;
	std::cout << "First of all enter task day: " << std::endl;
	std::cin >> day_for_find;
	std::cout << "Enter task month: " << std::endl;
	std::cin >> month_for_find;
	std::cout << "Enter task year: " << std::endl;
	std::cin >> year_for_find;
	std::cout << "Enter task hour: " << std::endl;
	std::cin >> hour_for_find;
	std::cout << "Enter task minutes: " << std::endl;
	std::cin >> minutes_for_find;
	std::cin.get();

	for (int i = 0; i < size; i++)
	{
		if (task->date.day == day_for_find && task->date.month == month_for_find && task->date.year == year_for_find
			&& task->date.hour == hour_for_find && task->date.minutes == minutes_for_find)
		{
			std::cout << std::endl;
			std::cout << i + 1 << ". ";
			std::cout << "Name of the task: " << task[i].name << std::endl;
			std::cout << "Date:" << task[i].date.day << "." << task[i].date.month << "." << task[i].date.year << " " << task[i].date.hour << ":" << task[i].date.minutes << std::endl;
			std::cout << "Discription: " << task[i].discription << std::endl;
			std::cout << "Priority: " << task[i].priority << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
	
}

void save_to_file(Task* task, int size)
{
}