#include <fstream>
#include <iostream>

using namespace std;

void nuskaitymas(int& R, int& G, int& Z) {
    ifstream in("U1.txt");

    R = 0; G = 0; Z = 0;

    int n, sk;
    char c;
    in >> n;

    for (int i = 0; i < n; i++) {
        in >> c >> sk;

        if (c == 'R') {
            R += sk;
        } else if (c == 'G') {
            G += sk;
        } else if (c == 'Z') {
            Z += sk;
        }
    }

    in.close();
}

int kiekBuvoSuklijuota(int R, int G, int Z) {
    if (Z < R && Z < G) {
        return Z / 2;
    } else if (R < G) {
        return R / 2;
    } else {
        return G / 2;
    }
}

void isvestis(int V, int R, int G, int Z) {
    ofstream out("U1rez.txt");

    out << V << endl;
    out << "G = " << G - (V * 2) << endl;
    out << "Z = " << Z - (V * 2) << endl;
    out << "R = " << R - (V * 2) << endl;

    out.close();
}

int main() {
    int R, G, Z;

    nuskaitymas(R, G, Z);
    int V = kiekBuvoSuklijuota(R, G, Z);
    isvestis(V, R, G, Z);

    return 0;
}