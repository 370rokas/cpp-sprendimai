#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int a, b, k[50];
    ifstream failasIn("in.txt");

    failasIn >> a >> b;
    for (int i = 0; i < a; i++) {
        k[i] = 1;
    }

    int l = a;
    int i = 0;
    int d = b;
    while (l > 1) {
        d -= k[i % a];
        if (d == 0) {
            k[i % a] = 0;
            d = b;
            l--;
        }
        i++;
    }

    int res = 0;
    for (int i = 0; i < a; i++) {
        if (k[i] == 1) {
            res = i + 1;
        }
    }

    cout << res << endl;
    return 0;
}