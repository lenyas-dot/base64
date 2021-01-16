#include <iostream>
#include "Functions.h"

using namespace std;

int main() {


    string result = DecodeBase64("TWFuIGkgbGlrZSB5b3U=");
    cout << result;
    return 0;
}
