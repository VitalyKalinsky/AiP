#include "book.h"

void clean_buffer();
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double division(double a, double b);
void print_int(void *a);
void print_double(void *a);
void print_str(void *a);
void print_array(char *pcFirst, const int arrSize, int typeSize, void (*type_print)(void *));
// Прототипы используемых в данном задании функций:
void sort(char *pcFirst, int nNumber, int size,
          void (*Swap)(void *, void *), int (*Compare)(void *, void *));

void swap_int(void *p1, void *p2);
int cmp_int(void *p1, void *p2);
void swap_double(void *p1, void *p2);
int cmp_double(void *p1, void *p2);
void swap_str(void *p1, void *p2);
int cmp_str(void *p1, void *p2);

void print_max(int arr[], int size);
void print_min(int arr[], int size);
void sort_asc(int arr[], int size);
void sort_desc(int arr[], int size);

double integrate(double (*func)(double), double a, double b, int n);
double linear(double x);
double linear_integral(double a, double b);
double quadratic(double x);
double quadratic_integral(double a, double b);
double sinus(double x);
double sinus_integral(double a, double b);
double exponenta(double x);
double exponenta_integral(double a, double b);
void compare_results(const char *func_name, double our_value, double theoretical_value, double a, double b, int n);

void print_book(Book book);
void initialize_book(Book &book, const char *author, const char *title, int publicationYear, double price, const char *category);
void user_input_book(Book &book);
void free_book(Book &book);