#include <iostream>
#include <string>


#include "muhash.h"

using namespace std;

int main() {
    string s = "b";
    auto mh = MuHash3072((unsigned char*)(s.data()));
    s = "a";
    mh.Insert((unsigned char*)(s.data()));

    cout << "H(a + b) = " << mh.FinalizeBase64() << endl;

    //增量哈希计算
    s = "a";
    auto mh1 = MuHash3072((unsigned char*)(s.data()));
    s = "b";
    auto mh2 = MuHash3072((unsigned char*)(s.data()));
    mh2 *= mh1; //哈希合并;
    cout << "H(a) + H(b) = " << mh2.FinalizeBase64() << endl;

    return 0;
}
