#include <iostream>
#include "functions.h"

int main()
{
    Task* to_do_list = new Task[100];
    main_menu(to_do_list);
    delete[]to_do_list;
}
