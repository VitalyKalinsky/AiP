#include "other.h"
#include <cassert>
#include <iostream>
#include <cstring>
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
        cout << ((i == arrSize - 1) ? "}" : ", ");
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

using namespace std;
int main(int argc, char const *argv[])
{
    {
        const char *arr[] = {"QQQ", "SDF", "ABC"};
        int nTotal = sizeof(arr) / sizeof(*arr);
        /** Печать исходного массива */
        printf("До сортировки: ");
        print_array(reinterpret_cast<char *>(arr), nTotal, sizeof(char *), print_str);
        printf("\n");
        sort(reinterpret_cast<char *>(arr), nTotal, sizeof(char *), swap_str, cmp_str);

        /** Печать результатов сортировки */
        printf("После сортировки: ");
        print_array(reinterpret_cast<char *>(arr), nTotal, sizeof(char *), print_str);
        printf("\n\n-----------------------------\n\n");
    }
}
