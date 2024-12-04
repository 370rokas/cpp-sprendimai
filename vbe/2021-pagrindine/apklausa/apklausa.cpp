#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct mokinys {
    string vardas;
    string dalykas;
    int nPazymiu;
    int pazymiai[100];
    double vidurkis;
};

struct dalykas {
    string pavadinimas;
    int nMokiniu;
    int sum;
};

void skaityti(int& m, mokinys* M) {
    ifstream fIn("U2.txt");

    fIn >> m;
    for (int i = 0; i < m; i++) {
        fIn >> M[i].vardas >> M[i].dalykas >> M[i].nPazymiu;

        int sum = 0;
        for (int j = 0; j < M[i].nPazymiu; j++) {
            fIn >> M[i].pazymiai[j];
            sum += M[i].pazymiai[j];
        }

        M[i].vidurkis = (double) sum / (double) M[i].nPazymiu;
    }

    fIn.close();
}

void dalykuStatistika(int& m, mokinys* M, int& d, dalykas* D) {
    d = 0;

    for (int i = 0; i < m; i++) {
        if (M[i].vidurkis < 9) continue;

        bool rasta = false;
        for (int j = 0; j < d; j++) {
            if (M[i].dalykas == D[j].pavadinimas) {
                rasta = true;
                D[j].nMokiniu++;
                D[j].sum += M[i].vidurkis;
                break;
            }
        }

        if (!rasta) {
            D[d].pavadinimas = M[i].dalykas;
            D[d].nMokiniu = 1;
            D[d].sum = M[i].vidurkis;
            d++;
        }
    }
}

void rikiuoti(int& d, dalykas* D) {
    for (int i = 0; i < d - 1; i++) {
        for (int j = i + 1; j < d; j++) {
            if (D[i].nMokiniu < D[j].nMokiniu) {
                swap(D[i], D[j]);
            } else {
                if (D[i].nMokiniu == D[j].nMokiniu) {
                    if (D[i].pavadinimas > D[j].pavadinimas) {
                        swap(D[i], D[j]);
                    }
                }
            }
        }
    }
}

void rezultatai(int m, mokinys* M, int d, dalykas* D) {
    ofstream fOut("U2rez.txt");

    int nIsspausdintu = 0;
    for (int i = 0; i < d; i++) {
        if ((double) round(D[i].sum / (double) D[i].nMokiniu) >= 9) {
            // Jeigu dalyko vidurkis > 9, spausdinti ji

            fOut << D[i].pavadinimas << " " << D[i].nMokiniu << endl;
            for (int j = 0; j < m; j++) {
                if (M[j].dalykas == D[i].pavadinimas) {
                    fOut << M[j].vardas << endl;
                }
            }

            nIsspausdintu++;
        }
    }

    if (nIsspausdintu == 0) {
        fOut << "Neatitinka vidurkis";
    }

    fOut.close();
}

int main() {
    int m, d;
    mokinys M[50];
    dalykas D[50];

    skaityti(m, M);
    dalykuStatistika(m, M, d, D);
    rikiuoti(d, D);
    rezultatai(m, M, d, D);

    return 0;
}