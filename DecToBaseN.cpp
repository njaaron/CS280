#include <iostream>
#include <string>

using namespace std;

string DecToBaseN(int num, int base) {
    if (base < 2 || (base > 10 && base != 16)) {
        cout << "Invalid Base: " << base << endl;
        return "";
    }
    if (num == 0) {
        return "";
    } else {
        int remainder = num % base;
        string result = DecToBaseN(num / base, base);
        if (remainder < 10) {
            result += to_string(remainder);
        } else {
            result += ('A' + remainder - 10);
        }
        return result;
    }
}

