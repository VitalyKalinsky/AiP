#ifndef UI_H
#define UI_H

#include "library.h"

void show_main_menu(Library* library);
void show_sort_menu(Library* library);
void show_search_menu(Library* library);
void show_edit_menu(Library* library);
void clean_input_buffer();
void wait_for_enter();

#endif