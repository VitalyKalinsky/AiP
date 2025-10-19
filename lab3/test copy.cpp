
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
#define MAX_WORDS 1024
#define MAX_LINE_LENGTH 40
        printf("6: \n");
        cout << "Введите строку: ";
        int cur_size = 10;
        char *cString = new char[cur_size]();
        char c = getchar();
        int cur_pos = 0;

        char **words = new char *[MAX_WORDS];
        int word_count = 0;
        int word_start = -1;

        while (true)
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
            if (c == ' ' or c == '\n')
            {
                if (word_start != -1)
                {
                    int word_length = cur_pos - word_start;
                    words[word_count] = new char[word_length + 1];

                    for (int i = 0; i < word_length; i++)
                    {
                        words[word_count][i] = cString[word_start + i];
                    }
                    words[word_count][word_length] = '\0';
                    word_count++;
                    word_start = -1;
                }
                if (c == '\n')
                {
                    break;
                }
            }
            else
            {
                if (word_start == -1)
                {
                    word_start = cur_pos;
                }
            }
            cur_pos++;
            c = getchar();
        }

        char **lines = new char *[word_count]();
        for (int i = 0; i < word_count + 1; i++)
        {
            lines[i] = new char[MAX_LINE_LENGTH + 1](); // Initialize with zeros
        }
        int potential_length = 0;
        int cur_line = 0;
        int max_len = 0;
        //todo for 40-digit word 
        for (int i = 0; i < word_count; i++)
        {
            potential_length = (strlen(lines[cur_line]) + strlen(words[i]) + 1);
            if (potential_length > 40)
            {
                int cur_length = potential_length - (strlen(words[i]) + 1);
                cur_line++;
                lines[cur_line] = words[i];
                if(cur_length > max_len){
                    max_len = cur_length;
                }
                potential_length = strlen(words[i]);
            }
            else
            {
                if (potential_length == (strlen(words[i]) + 1))
                {
                    lines[cur_line] = words[i];
                }
                else
                {
                    lines[cur_line] = strcat(strcat(lines[cur_line], " "), words[i]);
                }
            }
        }
        cout << " ";
        for (int i = 0; i < max_len; i++)
        {
            cout << "_";
        }
        cout << endl;
        
        //1 line
        if (cur_line == 1){
            cout << "|" " " << endl;
        }
        
        //2+ lines

        // Очистка памяти
        delete[] cString;
        for (int i = 0; i < word_count; i++)
        {
            delete[] words[i];
        }
        delete[] words;
    }
    // Here user input is shown. This line must be at most 40 characters long.
}