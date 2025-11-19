#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"

struct Library
{
    Book **books;
    int capacity;
    int cur_index;
};
Library *create_library();
void free_library(Library *library);
void resize_library(Library *library);

void print_library(Library *library);
void add_book(Library *library, Book *book);
void delete_book(Library *library);
void change_book(Library *library);
void export_library(Library *library);
void import_library(Library *library);
void find_min_year_book_after_users_input(Library *library);

#endif