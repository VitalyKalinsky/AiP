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
    if (library->cur_index >= library->capacity)
    {
        resize_library(library);
    }

    library->books[library->cur_index] = book;
    library->cur_index++;
}

void print_library(Library *library)
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
    case 1:
        printf("по названию.\n");
        break;
    case 2:
        printf("по автору.\n");
        break;
    case 3:
        printf("по году выпуска.\n");
        break;
    case 4:
        printf("по цене.\n");
        break;
    case 5:
        printf("по жанру.\n");
        break;
    }
}

void find_books_by_field(Library *library, char field[], int choice)
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
    case 1:
    { // автор
        const char *new_author = static_cast<const char *>(value);
        char *author_copy = new char[strlen(new_author) + 1];
        strcpy(author_copy, new_author);
        if (book->author)
            delete[] book->author;
        book->author = author_copy;
        break;
    }
    case 2:
    { // название
        const char *new_title = static_cast<const char *>(value);
        char *title_copy = new char[strlen(new_title) + 1];
        strcpy(title_copy, new_title);
        if (book->title)
            delete[] book->title;
        book->title = title_copy;
        break;
    }
    case 3: // год издания
        book->publicationYear = *(int *)value;
        break;
    case 4: // цена
        book->price = *(double *)value;
        break;
    case 5:
    { // жанр
        const char *new_category = static_cast<const char *>(value);
        char *category_copy = new char[strlen(new_category) + 1];
        strcpy(category_copy, new_category);
        if (book->category)
            delete[] book->category;
        book->category = category_copy;
        break;
    }
    default:
        printf("Неверное поле для изменения!\n");
        break;
    }
}

void export_library(Library *library)
{
    if (library->cur_index == 0) {
        printf("Библиотека пуста - нечего экспортировать.\n");
        return;
    }

    char filename[256];
    printf("Введите имя файла для сохранения: ");
    if (scanf("%255s", filename) != 1) {
        printf("Ошибка ввода имени файла!\n");
        clean_buffer();
        return;
    }
    clean_buffer();

    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка: не удалось создать файл '%s'!\n", filename);
        return;
    }

    fprintf(file, "%d\n", library->cur_index);

    for (int i = 0; i < library->cur_index; i++) {
        Book *book = library->books[i];
        fprintf(file, "%s\n", book->author);
        fprintf(file, "%s\n", book->title);
        fprintf(file, "%d\n", book->publicationYear);
        fprintf(file, "%.10g\n", book->price);
        fprintf(file, "%s\n", book->category);
    }

    fclose(file);
    printf("Библиотека успешно экспортирована в файл '%s' (%d книг)\n", filename, library->cur_index);
}

void import_library(Library *library)
{
    char filename[256];
    printf("Введите имя файла для загрузки: ");
    if (scanf("%255s", filename) != 1) {
        printf("Ошибка ввода имени файла!\n");
        clean_buffer();
        return;
    }
    clean_buffer();

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка: не удалось открыть файл '%s'!\n", filename);
        return;
    }

    int book_count;
    if (fscanf(file, "%d", &book_count) != 1 || book_count < 0) {
        printf("Ошибка: неверный формат файла!\n");
        fclose(file);
        return;
    }
    fgetc(file);

    if (book_count == 0) {
        printf("Файл не содержит книг.\n");
        fclose(file);
        return;
    }

    int imported_count = 0;
    for (int i = 0; i < book_count; i++) {
        char author[1024], title[1024], category[1024];
        int year;
        double price;

        if (fgets(author, sizeof(author), file) == NULL) break;
        if (fgets(title, sizeof(title), file) == NULL) break;
        if (fscanf(file, "%d", &year) != 1) break;
        if (fscanf(file, "%lf", &price) != 1) break;
        fgetc(file);
        if (fgets(category, sizeof(category), file) == NULL) break;

        author[strcspn(author, "\n")] = 0;
        title[strcspn(title, "\n")] = 0;
        category[strcspn(category, "\n")] = 0;

        Book *new_book = new Book();
        initialize_book(*new_book, author, title, year, price, category);
        add_book(library, new_book);
        imported_count++;
    }

    fclose(file);
    printf("Успешно импортировано %d книг из файла '%s'\n", imported_count, filename);
}

void find_min_year_book_after_users_input(Library *library)
{
    if (library->cur_index == 0) {
        printf("Библиотека пуста - нечего искать.\n");
        return;
    }

    int target_year;
    printf("Введите год для поиска: ");
    if (scanf("%d", &target_year) != 1) {
        printf("Ошибка: введите корректный год!\n");
        clean_buffer();
        return;
    }
    clean_buffer();

    Book *min_year_book = nullptr;
    int min_year = INT_MAX;

    for (int i = 0; i < library->cur_index; i++) {
        Book *book = library->books[i];
        if (book->publicationYear > target_year && book->publicationYear < min_year) {
            min_year = book->publicationYear;
            min_year_book = book;
        }
    }

    if (min_year_book == nullptr) {
        printf("Не найдено книг, изданных после %d года.\n", target_year);
    } else {
        printf("Книга с самым маленьким годом издания после %d года:\n", target_year);
        print_book(*min_year_book);
    }
}