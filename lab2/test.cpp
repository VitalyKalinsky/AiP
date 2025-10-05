#include <iostream>
using namespace std;

int main()
{
    {
        const int nN = 1;
        const int *pnN = &nN;
        int m = *pnN;
        //*const_pn = 2; //не получится, т.к. значение неизменяемое
        pnN = &m;
    }

}