#ifndef OTHER_H
#define OTHER_H
void print_array(const int arr1D[], const int size1D);
void print_2D_array(const int **arr2D, const int rows, const int cols);

int inc_by_value(int x);
void inc_by_pointer(int *x);
void inc_by_reference(int &x);

void swap(int *a, int *b);
void swap(int &a, int &b);

int find_Min_1D(const int arr[], const int size);
int find_Min_2D(const int **const arr, const int rows, const int cols);

int my_Str_Cmp(const char *str1, const char *str2);

int day_of_year(const int day, const int month, const int year, const int nDayTab[2][12]);
void day_of_month(const int dayOfYear, const int year, int &day, int &month, const int nDayTab[2][12]);

int *add_unique(int arr[], int &n, const int new_value);

int sum_of_natural_numbers(const int N);
void var_args(int first, ...);

int* my_min(int arr[], int size);
#endif
