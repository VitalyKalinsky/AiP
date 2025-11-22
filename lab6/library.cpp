#include "book.h"
#include "library.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <climits>
#include <cstdio>
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

void print_library(Library *library) // TODO: для пустой библиотеки сделать пустой вывод
{
    for (int i = 0; i < library->cur_index; i++)
    {
        printf("%d. ", i + 1);
        print_book(*library->books[i]);
    }
}

void sort(Library *library, int field, bool ascending)
{
    if (!library || library->cur_index < 2)
        return;

    if (field < 1 || field > 5)
    {
        printf("Неправильное поле сортировки!\n");
        return;
    }
    for (int i = 0; i < library->cur_index - 1; i++)
    {
        for (int j = 0; j < library->cur_index - i - 1; j++)
        {
            if (!library->books[j] || !library->books[j + 1])
                continue;

            int should_swap = 0;
            switch (field)
            {
            case 1: // по названию
                if (ascending)
                {
                    should_swap = strcmp(library->books[j]->title, library->books[j + 1]->title) > 0;
                }
                else
                {
                    should_swap = strcmp(library->books[j]->title, library->books[j + 1]->title) < 0;
                }
                break;
            case 2: // по автору
                if (ascending)
                {
                    should_swap = strcmp(library->books[j]->author, library->books[j + 1]->author) > 0;
                }
                else
                {
                    should_swap = strcmp(library->books[j]->author, library->books[j + 1]->author) < 0;
                }
                break;
            case 3: // по году
                if (ascending)
                {
                    should_swap = library->books[j]->publicationYear > library->books[j + 1]->publicationYear;
                }
                else
                {
                    should_swap = library->books[j]->publicationYear < library->books[j + 1]->publicationYear;
                }
                break;
            case 4: // по цене
                if (ascending)
                {
                    should_swap = library->books[j]->price > library->books[j + 1]->price;
                }
                else
                {
                    should_swap = library->books[j]->price < library->books[j + 1]->price;
                }
                break;
            case 5: // по жанру
                if (ascending)
                {
                    should_swap = strcmp(library->books[j]->category, library->books[j + 1]->category) > 0;
                }
                else
                {
                    should_swap = strcmp(library->books[j]->category, library->books[j + 1]->category) < 0;
                }
                break;
            }

            if (should_swap)
            {
                Book *temp = library->books[j];
                library->books[j] = library->books[j + 1];
                library->books[j + 1] = temp;
            }
        }
    }
    printf("Картотека отсортирована ");
    switch (field)
    {
    case 1: // по названию
        printf("по названию.\n");
        break;
    case 2: // по автору
        printf("по автору.\n");
        break;
    case 3: // по году
        printf("по году выпуска.\n");
        break;
    case 4: // по цене
        printf("по цене.\n");
        break;
    case 5: // по жанру
        printf("по жанру.\n");
        break;
    }
}

/**
 * 1 - по названию книги,
 * 2 - по автору,
 * 3 - по жанру.
 */
void find_books_by_field(Library *library, char field[], int choice) // TODO: для пустой библиотеки сделать пустой вывод
{
    if (library->cur_index == 0)
    {
        printf("Библиотека пуста.\n");
        return;
    }

    switch (choice)
    {
    case 1:
        printf("Книги с названием '%s':\n", field);
        break;
    case 2:
        printf("Книги с автором '%s':\n", field);
        break;
    case 3:
        printf("Книги жанра '%s':\n", field);
        break;
    }

    int found = 0;
    for (int i = 0; i < library->cur_index; i++)
    {
        int compare;
        switch (choice)
        {
        case 1:
            compare = strcmp(library->books[i]->title, field);
            break;
        case 2:
            compare = strcmp(library->books[i]->author, field);
            break;
        case 3:
            compare = strcmp(library->books[i]->category, field);
            break;
        }
        if (compare == 0)
        {
            print_book(*library->books[i]);
            found++;
        }
    }

    if (!found)
    {
        printf("Книги не найдены.\n");
    }
}

void delete_book(Library *library, int index)
{
    free_book(*library->books[index - 1]);
    delete library->books[index - 1];

    for (int i = index - 1; i < library->cur_index - 1; i++)
    {
        library->books[i] = library->books[i + 1];
    }

    library->books[library->cur_index - 1] = nullptr;
    library->cur_index--;
}

// const char *author; 1
// const char *title; 2
// int publicationYear; 3
// double price; 4
// const char *category; 5
void change_book(Library *library, int index, int field, void *value)
{
    if (index < 1 || index > library->cur_index)
    {
        printf("Неверный индекс книги!\n");
        return;
    }

    Book *book = library->books[index - 1];

    switch (field)
    {
    case 1: // автор
        strcpy(book->author, (const char *)value);
        break;
    case 2: // название
        strcpy(book->title, (const char *)value);
        break;
    case 3: // год издания
        book->publicationYear = *(int *)value;
        break;
    case 4: // цена
        book->price = *(double *)value;
        break;
    case 5: // жанр
        strcpy(book->category, (const char *)value);
        break;
    default:
        printf("Неверное поле для изменения!\n");
        break;
    }
}