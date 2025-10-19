
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    {
#define MAX_WORDS 1024
#define MAX_LINE_LENGTH 40
        printf("6: \n");
        cout << "Введите строку: ";
        int cur_size = 10;
        char *cString = new char[cur_size]();
        char c = getchar();
        int cur_pos = 0;

        char **words = new char *[MAX_WORDS]();
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
            if (c == ' ' || c == '\n')
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

        char **lines = new char *[MAX_WORDS]();
        for (int i = 0; i < MAX_WORDS; i++)
        {
            lines[i] = nullptr;
        }

        lines[0] = new char[MAX_LINE_LENGTH + 1]();
        strcpy(lines[0], "");

        int potential_length = 0;
        int cur_line = 0;
        int max_len = 0;
        for (int i = 0; i < word_count; i++)
        {
            potential_length = (strlen(lines[cur_line]) + strlen(words[i]) + 1);
            if (strlen(words[i]) > MAX_LINE_LENGTH)
            {
                max_len = MAX_LINE_LENGTH;

                if (strlen(lines[cur_line]) > 0)
                {
                    cur_line++;
                    lines[cur_line] = new char[MAX_LINE_LENGTH + 1]();
                }

                strncpy(lines[cur_line], words[i], MAX_LINE_LENGTH);
                lines[cur_line][MAX_LINE_LENGTH] = '\0';

                cur_line++;
                lines[cur_line] = new char[MAX_LINE_LENGTH + 1]();
                strcpy(lines[cur_line], words[i] + MAX_LINE_LENGTH);

                potential_length = strlen(lines[cur_line]);
            }
            else if (potential_length > MAX_LINE_LENGTH)
            {
                int cur_length = potential_length - (strlen(words[i]) + 1);
                cur_line++;
                lines[cur_line] = new char[MAX_LINE_LENGTH + 1]();
                strcpy(lines[cur_line], words[i]);
                if (cur_length > max_len)
                {
                    max_len = cur_length;
                }
                potential_length = strlen(words[i]);
            }
            else
            {
                if (potential_length == (strlen(words[i]) + 1))
                {
                    strcpy(lines[cur_line], words[i]);
                }
                else
                {
                    strcat(lines[cur_line], " ");
                    strcat(lines[cur_line], words[i]);
                }
            }
        }
        if (cur_line == 0)
        {
            max_len = strlen(lines[cur_line]);
        }
        cout << " ";
        for (int i = 0; i < max_len + 2; i++)
        {
            cout << "_";
        }
        cout << endl;

        // 1 line
        if (cur_line == 0)
        {
            cout << "|"
                    " "
                 << lines[cur_line] << " "
                                       "|"
                 << endl;
        }
        else
        { // 2+ lines
            for (int i = 0; i <= cur_line; i++)
            {
                if (i == 0)
                {
                    cout << "/"
                            " "
                         << lines[i];
                    for (int j = 0; j < (max_len + 1) - strlen(lines[i]); j++)
                    {
                        cout << " ";
                    }
                    cout << "\\" << endl;
                }
                else if (i == cur_line)
                {
                    cout << "\\"
                            " "
                         << lines[i];
                    for (int j = 0; j < (max_len + 1) - strlen(lines[i]); j++)
                    {
                        cout << " ";
                    }
                    cout << "/" << endl;
                }
                else
                {
                    cout << "|"
                            " "
                         << lines[i];
                    for (int j = 0; j < (max_len + 1) - strlen(lines[i]); j++)
                    {
                        cout << " ";
                    }
                    cout << "|" << endl;
                }
            }
        }
        cout << " ";
        for (int i = 0; i < max_len + 2; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "     \\\n      \\\n        /\\_/\\  (\n       ( ^.^ ) _)\n         \\\"/  (\n       ( | | )\n      (__d b__)" << endl;
        cout << endl
             << "------------------------------------" << endl
             << endl;
        delete[] cString;

        for (int i = 0; i < word_count; i++)
        {
            delete[] words[i];
        }
        delete[] words;

        for (int i = 0; i <= cur_line; i++)
        {
            delete[] lines[i];
        }
        delete[] lines;
    }
    // Реализуйте следующую программу. Пользователь вводит строку (любого размера), после чего
    //  Here user input is shown. This line must be at most 40 characters long. input i shasd ownat most
    /**
     * Задание 6. Работа со строками.
     * aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccc
     * aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb cccccccccccccccccccccccccccccccccccccccc
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
}