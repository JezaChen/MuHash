#include <iostream>
#include <string>
#include <cryptopp/base64.h>

#include "muhash.h"

using namespace std;
using namespace CryptoPP;

std::string BytesToBase64(byte *s, unsigned int s_len)
{
    std::string encoded;

    StringSource ss(s, s_len, true,
                    new Base64Encoder(new StringSink(encoded))
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

int main() {
    string s = "b";
    auto mh = MuHash3072((unsigned char*)(s.data()));
    s = "a";
    mh.Insert((unsigned char*)(s.data()));
    s = "a";
    mh.Remove((unsigned char*)(s.data()));
    uint256 out;
    mh.Finalize(out);
    char s_str[32];
    out.Serialize(s_str);
    string s_string = BytesToBase64((byte*)s_str, 32);
    cout << s_string << endl;

    return 0;
}
