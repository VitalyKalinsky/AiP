#include "ui.h"
#include "library.h"
#include "book.h"
#include <iostream>
#include <cstdio>
#include <cstring>

void show_main_menu(Library* library)
{
    int choice;
    
    do {
        printf("\n========================================\n");
        printf("          БИБЛИОТЕКА - ГЛАВНОЕ МЕНЮ\n");
        printf("========================================\n");
        printf("1. Распечатать библиотеку\n");
        printf("2. Добавить книгу\n");
        printf("3. Удалить книгу\n");
        printf("4. Изменить информацию о книге\n");
        printf("5. Сортировать книги\n");
        printf("6. Найти книги\n");
        printf("7. Сохранить в файл\n");
        printf("8. Загрузить из файла\n");
        printf("9. Найти книгу с минимальным годом после заданного\n");
        printf("10. Показать список категорий\n");
        printf("0. Выход из программы\n");
        printf("----------------------------------------\n");
        printf("Ваше действие: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка: введите число от 0 до 10!\n");
            clean_buffer();
            continue;
        }
        clean_buffer();
        
        switch (choice) {
            case 1:
                printf("\n========================================\n");
                printf("           СОДЕРЖИМОЕ БИБЛИОТЕКИ\n");
                printf("========================================\n");
                if (library->cur_index == 0) {
                    printf("Библиотека пуста.\n");
                } else {
                    print_library(library);
                }
                break;
                
            case 2: {
                printf("\n========================================\n");
                printf("             ДОБАВЛЕНИЕ КНИГИ\n");
                printf("========================================\n");
                Book* new_book = new Book();
                user_input_book(*new_book, library->categories);
                add_book(library, new_book);
                printf("Книга успешно добавлена!\n");
                break;
            }
                
            case 3: {
                printf("\n========================================\n");
                printf("              УДАЛЕНИЕ КНИГИ\n");
                printf("========================================\n");
                if (library->cur_index == 0) {
                    printf("Библиотека пуста - нечего удалять.\n");
                    break;
                }
                
                printf("Текущее содержимое библиотеки:\n");
                print_library(library);
                
                int index;
                printf("Введите номер книги для удаления: ");
                if (scanf("%d", &index) != 1 || index < 1 || index > library->cur_index) {
                    printf("Ошибка: неверный номер книги!\n");
                    clean_buffer();
                } else {
                    delete_book(library, index);
                    printf("Книга успешно удалена!\n");
                }
                break;
            }
                
            case 4:
                show_edit_menu(library);
                break;
                
            case 5:
                show_sort_menu(library);
                break;
                
            case 6:
                show_search_menu(library);
                break;
                
            case 7:
                printf("\n========================================\n");
                printf("           СОХРАНЕНИЕ В ФАЙЛ\n");
                printf("========================================\n");
                export_library(library);
                break;
                
            case 8:
                printf("\n========================================\n");
                printf("           ЗАГРУЗКА ИЗ ФАЙЛА\n");
                printf("========================================\n");
                import_library(library);
                break;
                
            case 9:
                printf("\n========================================\n");
                printf("    ПОИСК КНИГИ С МИНИМАЛЬНЫМ ГОДОМ\n");
                printf("========================================\n");
                find_min_year_book_after_users_input(library);
                break;
                
            case 10: {
                printf("\n========================================\n");
                printf("           СПИСОК КАТЕГОРИЙ\n");
                printf("========================================\n");
                print_categories(library->categories);
                break;
            }
                
            case 0:
                printf("Выход из программы...\n");
                break;
                
            default:
                printf("Ошибка: неверный выбор! Введите число от 0 до 10.\n");
                break;
        }
    } while (choice != 0);
}

void show_sort_menu(Library *library)
{
    if (library->cur_index == 0)
    {
        printf("Библиотека пуста - нечего сортировать.\n");
        return;
    }

    int field, order;

    printf("\n========================================\n");
    printf("              СОРТИРОВКА\n");
    printf("========================================\n");
    printf("Выберите поле для сортировки:\n");
    printf("1. По названию\n");
    printf("2. По автору\n");
    printf("3. По году издания\n");
    printf("4. По цене\n");
    printf("5. По жанру\n");
    printf("----------------------------------------\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &field) != 1 || field < 1 || field > 5)
    {
        printf("Ошибка: неверный выбор поля!\n");
        clean_buffer();
        return;
    }

    printf("\nВыберите порядок сортировки:\n");
    printf("1. По возрастанию\n");
    printf("2. По убыванию\n");
    printf("----------------------------------------\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &order) != 1 || (order != 1 && order != 2))
    {
        printf("Ошибка: неверный выбор порядка!\n");
        clean_buffer();
        return;
    }

    clean_buffer();
    sort(library, field, order == 1);
    printf("Сортировка завершена успешно!\n");
}

void show_search_menu(Library *library)
{
    if (library->cur_index == 0)
    {
        printf("Библиотека пуста - нечего искать.\n");
        return;
    }

    int choice;
    char search_term[1024];

    printf("\n========================================\n");
    printf("                ПОИСК\n");
    printf("========================================\n");
    printf("Выберите критерий поиска:\n");
    printf("1. По названию книги\n");
    printf("2. По автору\n");
    printf("3. По жанру\n");
    printf("----------------------------------------\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3)
    {
        printf("Ошибка: неверный выбор!\n");
        clean_buffer();
        return;
    }
    clean_buffer();

    switch (choice)
    {
    case 1:
        printf("Введите название для поиска: ");
        break;
    case 2:
        printf("Введите автора для поиска: ");
        break;
    case 3:
        printf("Введите жанр для поиска: ");
        break;
    }

    if (scanf("%1023[^\n]", search_term) != 1)
    {
        printf("Ошибка ввода!\n");
        clean_buffer();
        return;
    }

    find_books_by_field(library, search_term, choice);
}

void show_edit_menu(Library *library)
{
    if (library->cur_index == 0)
    {
        printf("Библиотека пуста - нечего изменять.\n");
        return;
    }

    int book_index, field;

    printf("\n========================================\n");
    printf("           ИЗМЕНЕНИЕ КНИГИ\n");
    printf("========================================\n");
    printf("Текущее содержимое библиотеки:\n");
    print_library(library);

    printf("Введите номер книги для изменения: ");
    if (scanf("%d", &book_index) != 1 || book_index < 1 || book_index > library->cur_index)
    {
        printf("Ошибка: неверный номер книги!\n");
        clean_buffer();
        return;
    }
    clean_buffer();

    printf("\nВыберите поле для изменения:\n");
    printf("1. Автор\n");
    printf("2. Название\n");
    printf("3. Год издания\n");
    printf("4. Цена\n");
    printf("5. Жанр\n");
    printf("----------------------------------------\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &field) != 1 || field < 1 || field > 5)
    {
        printf("Ошибка: неверный выбор поля!\n");
        clean_buffer();
        return;
    }
    clean_buffer();

    Book *book = library->books[book_index - 1];

    switch (field)
    {
    case 1:
    {
        char new_author[1024];
        printf("Введите нового автора: ");
        if (scanf("%1023[^\n]", new_author) == 1)
        {
            change_book(library, book_index, 1, new_author);
            printf("Автор успешно изменен!\n");
        }
        break;
    }
    case 2:
    {
        char new_title[1024];
        printf("Введите новое название: ");
        if (scanf("%1023[^\n]", new_title) == 1)
        {
            change_book(library, book_index, 2, new_title);
            printf("Название успешно изменено!\n");
        }
        break;
    }
    case 3:
    {
        int new_year;
        printf("Введите новый год издания: ");
        if (scanf("%d", &new_year) == 1)
        {
            change_book(library, book_index, 3, &new_year);
            printf("Год издания успешно изменен!\n");
        }
        break;
    }
    case 4:
    {
        double new_price;
        printf("Введите новую цену: ");
        if (scanf("%lf", &new_price) == 1)
        {
            change_book(library, book_index, 4, &new_price);
            printf("Цена успешно изменена!\n");
        }
        break;
    }
    case 5:
    {
        char new_category[1024];
        printf("Введите новый жанр: ");
        if (scanf("%1023[^\n]", new_category) == 1)
        {
            change_book(library, book_index, 5, new_category);
            printf("Жанр успешно изменен!\n");
        }
        break;
    }
    }

    clean_buffer();
}