#include "book.h"
#include "library.h"
#include <cassert>

Library *create_library()
{
    Library *library = new Library();

    library->books = new Book *[10];

    library->cur_index = 0;
    library->capacity = 10;
    return library;
}

void free_library(Library *library)
{
    for (int i = 0; i < library->cur_index; i++)
    {
        if (library->books[i])
        {
            free_book(*library->books[i]);
            delete library->books[i];     
        }
    }
    delete[] library->books; 
    delete library;
}
void resize_library(Library *library)
{
    int new_capacity = library->capacity * 1.5 + 1;
    Book **new_books = new Book *[new_capacity];
    for (int i = 0; i < library->cur_index; i++)
    {
        new_books[i] = library->books[i];
    }
    for (int i = library->cur_index; i < new_capacity; i++)
    {
        new_books[i] = nullptr;
    }

    delete[] library->books;
    library->books = new_books;
    library->capacity = new_capacity;
}

void add_book(Library *library, Book *book)
{
    assert(library != nullptr && book != nullptr);
    if (library->cur_index >= library->capacity)
    {
        resize_library(library);
    }

    library->books[library->cur_index] = book;
    library->cur_index++;
}
