#ifndef BOOK_H
#define BOOK_H
#include "categories.h"
struct Book
{
    char *author;
    char *title;
    int publicationYear;
    double price;
    char *category;
};
void clean_buffer();
void print_book(Book book);
void initialize_book(Book &book, const char *author, const char *title, int publicationYear, double price, const char *category);
void user_input_book(Book &book, CategoriesList *categories);
void free_book(Book &book);
#endif