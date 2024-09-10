#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool arAutomorfinis(int sk) {
    int kv = sk * sk;

    for (int i2 = sk; i2 > 0; i2 = i2 / 10) {
        if (i2 % 10 != kv % 10) { return false; }
        kv = kv / 10;
    }

    return true;
}

int main()
{
    int sk;
    cin >> sk;

    if (arAutomorfinis(sk)) {
        cout << sk << " yra automorfinis";
    } else {
        cout << sk << " nera automorfinis";
    }

    return 0;
}
