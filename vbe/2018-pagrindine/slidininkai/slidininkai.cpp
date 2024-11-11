#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Slidininkas {
    string vardas;
    long startas;
    long finisas;
    long laikas;
};

void nuskaitymas(int& n, Slidininkas* S) {
    ifstream fIn("U2.txt");
    int val, min, sec;
    char buff[21];

    fIn >> n;
    for (int i = 0; i < n; i++) {
        fIn.read(buff, 20);
        buff[20] = '\0';
        S[i].vardas = buff;

        fIn >> val >> min >> sec;
        S[i].startas = val * 3600 + min * 60 + sec;
        S[i].finisas = 0;
    }

    int n2;
    fIn >> n2;
    for (int i = 0; i < n2; i++) {
        fIn.read(buff, 20);
        for (int j = 0; j < n; j++) {
            if (S[j].vardas == string(buff)) {
                fIn >> val >> min >> sec;
                S[j].finisas = val * 3600 + min * 60 + sec;
            }
        }
    }

    fIn.close();
}

void suskaiciuotiLaikus(int n, Slidininkas* S) {
    for (int i = 0; i < n; i++) {
        if (S[i].finisas != 0) {
            S[i].laikas = S[i].finisas - S[i].startas;
        } else {
            S[i].laikas = 0;
        }
    }
}

void surikiuotiPagalLaikus(int n, Slidininkas* S) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (S[i].laikas > S[j].laikas) {
                swap(S[i], S[j]);
            }
        }
    }
}

void isvestis(int n, Slidininkas* S) {
    ofstream fOut("U2rez.txt");
    for (int i = 0; i < n; i++) {
        if (S[i].laikas != 0 && S[i].laikas < 3600) {
            fOut << S[i].vardas << " " << S[i].laikas / 60 << " " << S[i].laikas % 60;
        }
    }
    fOut.close();
}

int main() {

    int n;
    Slidininkas s[35];

    nuskaitymas(n, s);
    suskaiciuotiLaikus(n, s);
    surikiuotiPagalLaikus(n, s);
    isvestis(n, s);

    return 0;
}