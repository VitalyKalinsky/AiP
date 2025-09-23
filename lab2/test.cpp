#include <iostream>
#include <cmath>
#define LENGHT(r) (2 * M_PI * (r))
int main(int argc, char const *argv[]){
 /**
     * Задание 2.2.2.
     * 
     * Определите макрос MAX(A, B) для вычисления б'ольшего значения из двух.
     */

    {
/*#define NNN
#define MMM
для iNN = 0*/
// #define MMM для iNN = 1
// #define NNN для iNN = 2
    int iNN;
    #if defined NNN && defined MMM
            iNN = 0;
    #elif defined MMM
            iNN = 1;
    #elif defined NNN 
            iNN = 2;

    #else
            iNN = -1;
    #endif

    std::cout << iNN;
    }
}
