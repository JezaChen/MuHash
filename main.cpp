#include <iostream>
#include <string>


#include "muhash.h"

using namespace std;

int main() {
//    string s = "bbbbbb";
//    auto mh = MuHash3072((unsigned char*)(s.data()));
//    s = "aaaaaa";
//    mh.Insert((unsigned char*)(s.data()));
//
//    cout << "H(a + b) = " << mh.FinalizeBase64() << endl;
//
//    //增量哈希计算
//    s = "aaaaaa";
//    auto mh1 = MuHash3072((unsigned char*)(s.data()));
//    s = "bbbbbb";
//    auto mh2 = MuHash3072((unsigned char*)(s.data()));
//    mh2 *= mh1; //哈希合并;
//    cout << "H(a) + H(b) = " << mh2.FinalizeBase64() << endl;

    string a = "This is a test";
    auto mh = MuHash3072((unsigned char*)(a.data()), a.size());
    cout << mh.FinalizeBase64() << endl;

    a = "This is a test";
    mh = MuHash3072((unsigned char*)(a.data()), a.size());
    cout << mh.FinalizeBase64() << endl;

    return 0;
}
