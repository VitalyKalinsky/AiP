#include "other.h"

void inc_by_value(int x)
{
    x = x + 1;
}

void inc_by_pointer(int *x)
{
    if (x != nullptr)
    {
        *x = *x + 1;
    }
}

void inc_by_reference(int &x)
{
    x = x + 1;
}

void swap(int *a, int *b)
{
    if (a != nullptr && b != nullptr)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}