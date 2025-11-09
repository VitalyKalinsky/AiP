#include "other.h"
#include <iostream>

using namespace std;
int main()
{
    {
        // TODO: добавить доп. исполняемый файл для тестирования
        //       где эта функция будет тестироваться с данными
        //       разной длины (цикл по длине от 1 до 40)
        int raw_data_size, enc32_size, dec32_size;
        for (int i = 0; i < 128; i++)
        {
            char raw_data[i + 1];
            for (char j = 0; j < i; j++)
            {
                raw_data[j] = j;
            }
            raw_data[i] = i;
            raw_data_size = sizeof(raw_data) / sizeof(raw_data[0]);
            enc32_size = encoded32_size(raw_data_size);
            dec32_size = decoded32_size(enc32_size);
            char *dst = new char[enc32_size]();
            char *dec_dst = new char[dec32_size]();
            encode32(raw_data, raw_data_size, dst);
            decode32(dst, enc32_size, dec_dst);
            for (int j = 0; j < i; j++)
            {
                if (raw_data[j] != dec_dst[j])
                {
                    cout << "Не совпадает!" << endl;
                    cout << "Было: {";
                    for (int index = 0; index < raw_data_size; index++)
                    {
                        cout << std::hex << int(dec_dst[index]) << " " << std::dec;
                    }
                    cout << endl;
                    cout << "Закодировано: ";
                    for (int index = 0; index < enc32_size; index++)
                    {
                        cout << dst[index];
                    }
                    cout << "\nДекодировано: ";
                    for (int index = 0; index < raw_data_size; index++)
                    {
                        cout << std::hex << int(dec_dst[index]) << " " << std::dec;
                    }
                    cout << endl;
                    cout << endl;
                }
            }
            delete[] dec_dst;
            delete[] dst;
        }
        cout << endl;
    }
}