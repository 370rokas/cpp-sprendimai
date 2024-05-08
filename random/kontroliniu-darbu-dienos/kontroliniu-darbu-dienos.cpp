#include <iostream>
#include <fstream>

using namespace std;

const int MAX_N = 31;

void nuskaitytiFaila(char* f, int& k, int* diena, int* kontr) {
    ifstream fIn(f);

    fIn >> k;
    for (int i = 0; i < k; i++) {
        fIn >> diena[i] >> kontr[i];
    }

    fIn.close();
}

void spausdinti(int k, int* diena, int* kontr) {
    for (int i = 0; i < k; i++) {
        cout << diena[i] << " " << kontr[i] << endl;
    }
}

void iterptiDarba(int& k, int* d, int* v, int& diena, int& kontr) {
    int pI = -1;
    for (int i = 0; i < k; i++) {
        if (d[i] > diena) {
            pI = i;
            break;
        }
    }

    if (pI == -1) {
        d[k] = diena;
        v[k] = kontr;
        pI = k;
        k++;
    } else {
        for (int i = k; i > pI; i--) {
            d[i] = d[i - 1];
            v[i] = v[i - 1];
        }

        d[pI] = diena;
        v[pI] = kontr;
        k++;
    }

    if (v[k] > 2) {
        kontr = v[k] - 2;
        v[k] = 2;
    } else {
        kontr = 0;
    }
}

void perkeltiDarbus(int& prK, int* prD, int* prV, int perK, int* perD, int* perV) {
    for (int i = 0; i < perK; i++) {
        for (int j = 0; j < prK; j++) {
            if (perD[i] == prD[j]) {
                prV[j] -= perV[i];

                if (prV[j] <= 0) {
                    prK--;
                    for (int k = j; k < prK; k++) {
                        prD[k] = prD[k + 1];
                        prV[k] = prV[k + 1];
                    }
                }

                break;
            }
        }
    }
}

void papildytiDarbus(int& prK, int* prD, int* prV, int& papK, int* papD, int* papV) {
    for (int i = 0; i < papK; i++) {
        bool rasta = false;

        for (int j = 0; j < prK; j++) {
            if (papD[i] == prD[j]) {
                rasta = true;

                prV[j] += papV[i];
                if (prV[j] > 2) {
                    papV[i] = prV[j] - 2;
                    prV[j] = 2;
                } else {
                    papV[i] = 0;
                }

                if (papV[i] <= 0) {
                    papK--;
                    for (int k = i; k < papK; k++) {
                        papD[k] = papD[k + 1];
                        papV[k] = papV[k + 1];
                    }
                    i--;
                }

                break;
            }
        }

        if (!rasta) {
            iterptiDarba(prK, prD, prV, papD[i], papV[i]);

            if (papV[i] <= 0) {
                papK--;
                for (int k = i; k < papK; k++) {
                    papD[k] = papD[k + 1];
                    papV[k] = papV[k + 1];
                }
            }
        }
    }
}

void spausdintiFaila(char* f, int k, int* diena, int* kontr, int papK, int* papD, int* papV) {
    ofstream fOut(f);

    fOut << "Galutinis" << endl;
    for (int i = 0; i < k; i++) {
        fOut << diena[i] << " " << kontr[i] << endl;
    }

    fOut << "Papildomas" << endl;
    for (int i = 0; i < papK; i++) {
        fOut << papD[i] << " " << papV[i] << endl;
    }

    fOut.close();
}

int main() {
    int prK, prD[MAX_N], prV[MAX_N];
    int perK, perD[MAX_N], perV[MAX_N];
    int papK, papD[MAX_N], papV[MAX_N];

    nuskaitytiFaila("duomenys1.txt", prK, prD, prV);
    nuskaitytiFaila("duomenys2.txt", perK, perD, perV);
    nuskaitytiFaila("duomenys3.txt", papK, papD, papV);

    perkeltiDarbus(prK, prD, prV, perK, perD, perV);
    papildytiDarbus(prK, prD, prV, papK, papD, papV);

    spausdintiFaila("rezultatai1.txt", prK, prD, prV, papK, papD, papV);

    return 0;
}