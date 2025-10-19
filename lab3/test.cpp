
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{ /**
   * Задание 6. Работа со строками.
   *
   * Реализуйте следующую программу. Пользователь вводит строку (любого
   * размера), после чего пользователю выводится на консоль следующее
   * изображение, где его ввод помещен в "speech bubble":
   *
   *  _____________________________________
   * / Here user input is shown. This line \
   * \ must be at most 40 characters long. /
   *  ------------------------------------
   *     \
   *      \
   *        /\_/\  (
   *       ( ^.^ ) _)
   *         \"/  (
   *       ( | | )
   *      (__d b__)
   *
   *  При этом длина строки в "облачке" должна быть не более 40 символов, при
   *  этом слова должны переноситься аккуратно. Это означет, что не должно
   *  быть переносов в центре слова (если только это слово не больше 40
   *  символов).
   *
   *  Дизайн облачка и ASCII-арт допустимо поменять по усмотрению.
   *
   *  Подсказка: обратите внимание на конкатенацию строковых литералов в
   *  языке С, это позволит задавать подобные рисунки так, чтобы они
   *  адекватно выглядели в коде.
   */
    {

        printf("6: \n");
        /** Цикл ввода строки: */
        int cur_size = 10;
        char *cString = new char[cur_size]();
        cout << "Введите строку:";
        char c = cin.get();
        int cur_pos = 0;
        while (c != '\n')
        {
            if (cur_pos >= cur_size - 1)
            {
                char *new_cString = new char[cur_size * 2]();
                for (int i = 0; i < cur_size; i++)
                {
                    new_cString[i] = cString[i];
                }
                delete[] cString;
                cString = new_cString;
                cur_size *= 2;
            }
            cString[cur_pos] = c;
            cur_pos++;
            c = cin.get();
        }
        cString[cur_pos] = '\0'; //(*) завершаем строку
        // делим строку на слова
        // char *cWord;
        // char **cWords = new 
        // for (int i = 0; i < cur_pos; i++)
        // {
        //     if (cur_pos >= cur_size - 1)
        //     {
        //         char *new_cString = new char[cur_size * 2]();
        //         for (int i = 0; i < cur_size; i++)
        //         {
        //             new_cString[i] = cString[i];
        //         }
        //         delete[] cString;
        //         cString = new_cString;
        //         cur_size *= 2;
        //     }
        //     if (cString[i] == '0')
        //     {
        //     }
        // }
        const char *cat = "     \\\n      \\\n        /\\_/\\  (\n       ( ^.^ ) _)\n         \\\"/  (\n       ( | | )\n      (__d b__)";
        cout << cat << endl;
        cout << endl
             << "------------------------------------" << endl
             << endl;
    }
}
