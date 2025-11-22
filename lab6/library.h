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

void sort(Library* library, int field, bool ascending);

void find_books_by_field(Library *library, char field[], int choice);

void delete_book(Library *library, int index);
void change_book(Library *library, int index, int field, void * value);
void export_library(Library *library);
void import_library(Library *library);
void find_min_year_book_after_users_input(Library *library);

#endif