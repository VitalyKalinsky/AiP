#include "other.h"
#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>
#include "book.h"

void clean_buffer()
{
    while (getchar() != '\n')
        ;
}
double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double division(double a, double b)
{
    assert(b != 0);
    return a / b;
}

void print_int(void *a)
{
    printf("%d", *(int *)a);
}

void print_double(void *a)
{
    printf("%.10g", *(double *)a);
}

void print_str(void *a)
{
    std::cout << *(const char **)a;
}
using namespace std;
void print_array(char *pcFirst, const int arrSize, int typeSize, void (*type_print)(void *))
{
    assert(pcFirst != nullptr && arrSize > 0 && typeSize > 0);
    cout << "{";
    char *current = pcFirst - typeSize;
    for (int i = 0; i < arrSize; i++)
    {
        current += typeSize;
        (*type_print)(current);
        cout << ((i == arrSize - 1) ? "}\n" : ", ");
    }
}

void sort(char *pcFirst, int nNumber, int size,
          void (*Swap)(void *, void *), int (*Compare)(void *, void *))
{
    int i;
    for (i = 1; i < nNumber; i++)
        for (int j = nNumber - 1; j >= i; j--)
        {
            char *pCurrent = pcFirst + j * size;
            char *pPrevious = pcFirst + (j - 1) * size;
            if ((*Compare)(pPrevious, pCurrent) > 0) // требуется
                                                     // переставить
                (*Swap)(pPrevious, pCurrent);
        }
}

void swap_int(void *p1, void *p2)
{
    int temp = *(int *)p1;
    *(int *)p1 = *(int *)p2;
    *(int *)p2 = temp;
}

int cmp_int(void *p1, void *p2)
{
    int a = *(int *)p1;
    int b = *(int *)p2;

    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

void swap_double(void *p1, void *p2)
{
    double temp = *(double *)p1;
    *(double *)p1 = *(double *)p2;
    *(double *)p2 = temp;
}

int cmp_double(void *p1, void *p2)
{
    double a = *(double *)p1;
    double b = *(double *)p2;

    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

void swap_str(void *p1, void *p2)
{
    const char **str1 = (const char **)p1;
    const char **str2 = (const char **)p2;

    const char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int cmp_str(void *p1, void *p2)
{
    return strcmp(*(const char **)p1, *(const char **)p2);
}

void print_max(int arr[], int size)
{
    assert(arr != nullptr && size > 0);
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    std::cout << "Максимальное значение: " << maxVal << std::endl;
}

void print_min(int arr[], int size)
{
    assert(arr != nullptr && size > 0);
    int minVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    std::cout << "Минимальное значение: " << minVal << std::endl;
}

void sort_asc(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int max = i;
        for (int j = i; j > -1; j--)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        int tmp = arr[max];
        arr[max] = arr[i];
        arr[i] = tmp;
    }
    print_array(reinterpret_cast<char *>(arr), size, sizeof(int), print_int);
}
void sort_desc(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int min = i;
        for (int j = i; j > -1; j--)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
    print_array(reinterpret_cast<char *>(arr), size, sizeof(int), print_int);
}

double integrate(double (*func)(double), double a, double b, int n)
{
    assert(n > 0);

    double h = (b - a) / n; // ширина прямоугольника по x
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        double x_middle = a + (i + 0.5) * h; // середина прямоугольника
        sum += func(x_middle);
    }

    return sum * h;
}

double linear(double x)
{
    return x;
}

double linear_integral(double a, double b)
{
    return (b * b - a * a) / 2.0;
}

double quadratic(double x)
{
    return x * x;
}

double quadratic_integral(double a, double b)
{
    return (b * b * b - a * a * a) / 3.0;
}

double sinus(double x)
{
    return sin(x);
}

double sinus_integral(double a, double b)
{
    return -cos(b) + cos(a);
}

double exponenta(double x)
{
    return exp(x);
}

double exponenta_integral(double a, double b)
{
    return exp(b) - exp(a);
}

void compare_results(const char *func_name, double our_value, double theoretical_value, double a, double b, int n)
{
    printf("Функция %s на отрезке [%.10g;%.10g] с n = %d: теорерический=%.10g, вычисленный=%.10g\n", func_name, a, b, n, theoretical_value, our_value);
}

void print_book(Book book)
{
    printf("author='%s', ", book.author);
    printf("title='%s', ", book.title);
    printf("publicationYear=%d, ", book.publicationYear);
    printf("price=%.10g, ", book.price);
    printf("category='%s'.\n", book.category);
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
    clean_buffer();
    scanf("%1023[^\n]", author);

    printf("Введите название книги: ");
    clean_buffer();
    scanf("%1023[^\n]", title);
    do
    {
        printf("Введите год публикации книги: ");
        clean_buffer();
        if (scanf("%d", &publicationYear) != 1)
        {
            printf("Ошибка: введите целое число!\n");
            publicationYear = -3001;
            continue;
        }
        if (publicationYear < -3000)
        {
            printf("Неверный год публикации!\n");
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
            printf("%s - Неверный жанр!\n", category);
        }

    } while (flag);

    initialize_book(book, author, title, publicationYear, price, category);
}