#include <iostream>
#include <vector>

using namespace std;

// Returns:
//   nullptr if the digit is parsed OK
//   pointer to the first invalid digit, if `buff` cannot be parsed
const char * parseInt(const char * buff, int & digit) {

    digit = 0;

    for(const char * curr = buff; *curr != '\0'; curr++) {

        int currDigit = *curr - '0';

        if (currDigit > 9 || currDigit < 0) {
            return curr;
        }

        digit *= 10;
        digit += currDigit;

    }

    return nullptr;
}

int main(void) {

    string as, bs;

    cin >> as >> bs;

    int a, b;
    const char *aR, *bR;

    aR = parseInt(as.c_str(), a);
    bR = parseInt(bs.c_str(), b);

    if (aR == nullptr && bR == nullptr)
        cout << a + b << endl;
    else {
        if (aR != nullptr)
            cout << "[error] " << as << endl;
        else
            cout << a << endl;
        if (bR != nullptr)
            cout << "[error] " << bs << endl;
        else
            cout << b << endl;
    }

    return 0;
}