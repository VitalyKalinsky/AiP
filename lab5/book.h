#ifndef BOOK_H
#define BOOK_H

struct Book
{
    const char *author;
    const char *title;
    int publicationYear;
    double price;
    const char *category;
};

#endif