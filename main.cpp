#include <iostream>
#include <string>
#include <cryptopp/base64.h>

#include "muhash.h"

using namespace std;
using namespace CryptoPP;



int main() {
    string s = "b";
    auto mh = MuHash3072((unsigned char*)(s.data()));
    s = "a";
    mh.Insert((unsigned char*)(s.data()));

    uint256 out;
    mh.Finalize(out);
    cout << out.SerializeBase64() << endl;

    //增量哈希计算
    s = "a";
    auto mh1 = MuHash3072((unsigned char*)(s.data()));
    s = "b";
    auto mh2 = MuHash3072((unsigned char*)(s.data()));
    mh2 *= mh1; //哈希合并
    mh2.Finalize(out);
    cout << out.SerializeBase64() << endl;

    return 0;
}
