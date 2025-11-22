#include "library.h"
#include "book.h"
#include "ui.h"
#include <iostream>

int main()
{
    Library *library = create_library();
    
    // Показать главное меню
    show_main_menu(library);
    
    free_library(library);
    return 0;
}