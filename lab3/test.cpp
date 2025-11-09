
#include <iostream>
#include <cstring>
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
    if (cur_enc_byte == 0 && cur_bit != 4)
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
using namespace std;
int main(int argc, char const *argv[])
{
    char raw_data[] = {0x1e, 0x47}; // 01100 11101 00011
    int raw_data_size = sizeof(raw_data) / sizeof(raw_data[0]);
    int enc32_size = encoded32_size(raw_data_size);
    int dec32_size = decoded32_size(enc32_size);
    char *dst = new char[enc32_size]();
    char *dec_dst = new char[dec32_size]();

    cout << enc32_size << endl;
    cout << dec32_size << endl;
    encode32(raw_data, raw_data_size, dst);

    cout << "Закодировано: ";
    for (int i = 0; i < enc32_size; i++)
    {
        cout << dst[i];
    }
    cout << endl;

    decode32(dst, enc32_size, dec_dst);
    cout << "Декодировано: ";
    for (int i = 0; i < raw_data_size; i++)
    {
        cout << std::hex << int(dec_dst[i]) << " ";
    }
    cout << endl;
    delete[] dec_dst;
    delete[] dst;
}
