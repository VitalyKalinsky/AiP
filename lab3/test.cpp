#include <iostream>

int main(int argc, char const *argv[])
{
    int myArr[5];
    int *p = myArr; // p указывает на первый элемент myArr

    myArr[3] = 7; // OK
    p[3] = 8;     // OK: эквивалентно myArr[3] = 8

    *(p + 3) = 100;     // OK: эквивалентно p[3] = 100
    *(myArr + 3) = 100; // OK: эквивалентно myArr[3] = 100

    p++; // OK: p теперь указывает на myArr[1]
    // myArr++; // ОШИБКА КОМПИЛЯЦИИ: myArr - это константный указатель

    std::cout << *p;     // Выводит значение myArr[1]
    std::cout << *myArr; // Выводит значение myArr[0]
    return 0;
}
