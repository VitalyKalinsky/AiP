#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    int arr[n]; // ошибка при компиляции
    int *pArr = new int[n];
    pArr[0] = 4;
    delete []pArr; // НЕПРАВИЛЬНО!
}
