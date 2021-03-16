//
// Created by jeza on 2021/3/11.
//
#include "util.h"

signed char HexDigit(char c)
{
    return p_util_hexdigit[(unsigned char)c];
}

std::string HexStr(const std::vector<uint8_t> s)
{
    std::string rv;
    static constexpr char hexmap[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                                         '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    rv.reserve(s.size() * 2);
    for (uint8_t v: s) {
        rv.push_back(hexmap[v >> 4]);
        rv.push_back(hexmap[v & 15]);
    }
    return rv;
}

std::string BytesToBase64(byte *s, unsigned int s_len)
{
    std::string encoded;

    StringSource ss(s, s_len, true,
                    new Base64Encoder(new StringSink(encoded), false) //不要往后面加入换行符
    );
    return encoded;
}

// BASE64解码
std::string Base64ToBytes(byte *s, unsigned int s_len)
{
    std::string decoded;

    StringSource ss(s, s_len, true,
                    new Base64Decoder(new StringSink(decoded))
    );
    return decoded;
}