#include "book.h"
#include <iostream>
#include <cstring>

void clean_buffer()
{
    while (getchar() != '\n')
        ;
}

void print_book(Book book)
{
    printf("Автор='%s', ", book.author);
    printf("Название='%s', ", book.title);
    printf("Год выпуска=%d, ", book.publicationYear);
    printf("Цена=%.10g, ", book.price);
    printf("Жанр='%s'.\n", book.category);
}

void free_book(Book &book)
{
    if (book.author)
        delete[] book.author;
    if (book.title)
        delete[] book.title;
    if (book.category)
        delete[] book.category;
}

void initialize_book(Book &book, const char *author, const char *title, int publicationYear, double price, const char *category)
{
    free_book(book);
    char *new_author = new char[strlen(author) + 1];
    strcpy(new_author, author);
    char *new_title = new char[strlen(title) + 1];
    strcpy(new_title, title);
    char *new_category = new char[strlen(category) + 1];
    strcpy(new_category, category);
    book.author = new_author;
    book.title = new_title;
    book.publicationYear = publicationYear;
    book.price = price;
    book.category = new_category;
}

void user_input_book(Book &book)
{
    char author[1024] = "";
    char title[1024] = "";
    char category[1024] = "";

    int publicationYear;
    double price;
    const char *categories[] = {"ROMANCE", "FAIRY TAIL", "NOVELLA", "MANGA"};

    printf("Введите автора книги: ");
    scanf("%1023[^\n]", author);
    clean_buffer();

    printf("Введите название книги: ");
    scanf("%1023[^\n]", title);
    clean_buffer();
    do
    {
        printf("Введите год публикации книги: ");
        if (scanf(" %d", &publicationYear) != 1)
        {
            printf("Ошибка: введите целое число!\n");
            publicationYear = -3001;
            clean_buffer();
            continue;
        }
        if (publicationYear < -3000)
        {
            printf("Неверный год публикации!\n");
            clean_buffer();
        }

    } while (publicationYear < -3000);

    do
    {
        printf("Введите цену книги: ");
        clean_buffer();
        if (scanf("%lf", &price) != 1)
        {
            printf("Ошибка: введите число!\n");
            price = -1;
            continue;
        }

        if (price < 0)
        {
            printf("Цена не может быть отрицательной!\n");
        }
    } while (price < 0);

    bool flag = true;
    do
    {
        printf("Введите жанр книги (Romance, Fairy tail, Novella, Manga): ");
        clean_buffer();
        scanf("%1023[^\n]", category);

        for (int i = 0; category[i]; i++)
        {
            category[i] = std::toupper(category[i]);
        }

        flag = true;
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(category, categories[i]) == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            printf("Неверный жанр!\n");
        }

    } while (flag);

    initialize_book(book, author, title, publicationYear, price, category);
}

// void set_author()
// {
//     int cur_size = 10;
//     char *cString = new char[cur_size]();
//     printf("Введите строку: ");
//     char c = cin.get();
//     int cur_pos = 0;
//     while (c != '\n')
//     {
//         // расширение массива
//         if (cur_pos >= cur_size - 1) // не >, тк тогда не вместится \0 и будет переполнение, не получится вписать (*)
//         {
//             char *new_cString = new char[cur_size * 2]();
//             for (int i = 0; i < cur_size; i++)
//             {
//                 new_cString[i] = cString[i];
//             }
//             delete[] cString;
//             cString = new_cString;
//             cur_size *= 2;
//         }

//         cString[cur_pos] = c;
//         cur_pos++;
//         c = cin.get();
//     }

//     cString[cur_pos] = '\0';
// }