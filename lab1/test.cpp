#include <iostream>

int main(){
/**
 * Задание 10.3. 
 *
 * Напишите фрагмент кода, который реализует с помощью while следующую логику: 
 *
 * 1. исходно int x = 0; 
 * 2. на каждой итерации x = x + 1, sum = sum + 1 / x;
 * 3. необходимо найти значение x, при котором sum > 1.7.
 */

{
// char start = 120, sum = 0;
// for (char n = start; n < start + 10; ++n) {
//    sum += n;
// }
// в char не поместятся значения больше 127, поэтому я изменил тип start и sum на short
short start = 120, sum = 0;
for (short n = start; n < start + 10; ++n) {
   sum += n;
}
std::cout << sum;
}
}