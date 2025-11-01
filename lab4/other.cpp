#include "other.h"
#include <climits>
#include <cassert>
#include <iostream>
#include <cstdarg>

using namespace std;
void print_array(const int arr1D[], const int size1D)
{
    assert(arr1D != nullptr && size1D > 0);
    cout << "{";
    for (int i = 0; i < size1D; i++)
    {
        cout << arr1D[i];
        cout << ((i == size1D - 1) ? "}" : ", ");
    }
}
using namespace std;
void print_2D_array(const int **arr2D, const int rows, const int cols)
{
    assert(arr2D != nullptr && rows > 0 && cols > 0);
    cout << "{";
    for (int i = 0; i < rows; i++)
    {
        print_array(arr2D[i], cols);
        cout << ((i == rows - 1) ? "}" : ", ");
    }
}

int inc_by_value(int x)
{
    return x + 1;
}

void inc_by_pointer(int *x)
{
    assert(x != nullptr);
    (*x)++;
}

void inc_by_reference(int &x)
{
    x++;
}

void swap(int *a, int *b)
{
    assert(a != nullptr && b != nullptr);
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int find_Min_1D(const int arr[], const int size)
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
    return minVal;
}

int find_Min_2D(const int **const arr, const int rows, const int cols)
{
    assert(arr != nullptr && rows > 0 && cols > 0);

    int minVal = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
        if (arr[i] != nullptr)
        {
            int rowMin = find_Min_1D(arr[i], cols);
            if (rowMin < minVal)
            {
                minVal = rowMin;
            }
        }
    }
    return minVal;
}
int my_Str_Cmp(const char *str1, const char *str2)
{
    while ((*str1 && *str2) && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return static_cast<unsigned char>(*str1) - static_cast<unsigned char>(*str2);
}
int day_of_year(const int day, const int month, const int year, const int nDayTab[2][12])
{
    bool isLeapYear = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0); // из 1 лабы

    int dayOfYear = day;
    for (int i = 0; i < month - 1; i++)
    {
        dayOfYear += nDayTab[isLeapYear][i];
    }

    return dayOfYear;
}

void day_of_month(const int dayOfYear, const int year, int &day, int &month, const int nDayTab[2][12])
{
    bool isLeapYear = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);

    int daysPassed = 0;

    for (int i = 0; i < 12; i++)
    {
        if (dayOfYear <= daysPassed + nDayTab[isLeapYear][i])
        {
            month = i + 1;
            day = dayOfYear - daysPassed;
            break;
        }
        daysPassed += nDayTab[isLeapYear][i];
    }
}

int *add_unique(int arr[], int &n, const int new_value)
{
    for (int i = 0; i < n; i++)
    {
        if (new_value == arr[i])
            return arr;
    }
    int *res = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        res[i] = arr[i];
    }
    delete[] arr;
    res[n++] = new_value;
    return res;
}

int sum_of_natural_numbers(const int N)
{
    assert(N < 1);
    if (N == 1)
    {
        return 1;
    }
    return N + sum_of_natural_numbers(N - 1);
}
const char ENCODING_CHARS[32] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6'};

int encoded32_size(int raw_size)
{
    return (raw_size * 8 + 4) / 5;
}

int decoded32_size(int encode_size)
{
    return encode_size * 5 / 8;
}
int encode32(const char *raw_data, int raw_size, char *dst)
{
    if (raw_data == nullptr || raw_size < 1 || dst == nullptr)
    {
        return 1;
    }
    int cur_bit = 4, cur_enc_byte = 0, cur_enc_five = 0;
    for (int byte = 0; byte < raw_size; byte++)
    {
        for (int bit = 0; bit < 8; bit++)
        {
            // cout << ((raw_data[byte] >> (7 - bit)) & 1); // побитовый вывод
            cur_enc_byte += (((raw_data[byte] >> (7 - bit)) & 1) << cur_bit--);
            if (cur_bit < 0)
            {
                dst[cur_enc_five++] = ENCODING_CHARS[cur_enc_byte];
                cur_bit = 4;
                cur_enc_byte = 0;
            }
        }
    }
    if (cur_enc_byte != 0 || cur_bit != 4)
    {
        dst[cur_enc_five++] = ENCODING_CHARS[cur_enc_byte];
    }
    return 0;
}

int decode32(const char *encoded_data, int encoded_size, char *dst)
{
    if (encoded_data == nullptr || encoded_size < 1 || dst == nullptr)
    {
        return 1;
    }

    int cur_dec_byte = 0, bits_in_dec_byte = 0, cur_dst_index = 0;
    for (int byte = 0; byte < encoded_size; byte++)
    {
        if ((encoded_data[byte] < 'A' || encoded_data[byte] > 'Z') && (encoded_data[byte] < '1' || encoded_data[byte] > '6'))
        {
            return 2;
        }

        int char_index = 0;
        for (; ENCODING_CHARS[char_index] != encoded_data[byte]; char_index++)
            ;

        for (int bit = 4; bit >= 0; bit--)
        {
            cur_dec_byte += ((char_index >> bit) & 1) << (7 - (bits_in_dec_byte++));
            if (bits_in_dec_byte == 8)
            {
                dst[cur_dst_index++] = cur_dec_byte;
                cur_dec_byte = 0;
                bits_in_dec_byte = 0;
            }
        }
    }
    return 0;
}

void var_args(int first, ...)
{
    va_list args;
    va_start(args, first);
    int count = 0;
    int value = first;
    while (value != 0)
    {
        std::cout << (int)value << ' ';
        count++;
        value = va_arg(args, int);
    }
    va_end(args);
    std::cout << '\n' << "Количество: " << count << '\n';
}

int *my_min(int arr[], const int size)
{
    assert(size > 0);

    int *min_ptr = &arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min_ptr)
        {
            min_ptr = &arr[i];
        }
    }

    return min_ptr;
}
