#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct begikoDuomenys {
    string vardas;
    int startoNr;

    int baudos;
    int startoLaikas;
    int finisoLaikas;
};

struct begikoRezultatai {
    string vardas;
    int startoNr;

    int H;
    int M;
    int S;
};

void nuskaitymas(int& n, begikoDuomenys* begikas) {
    ifstream fIn("U2.txt");
    int m;

    fIn >> n;
    fIn.ignore(5, '\n');

    for (int i = 0; i < n; i++) {
        char vardas[21];
        fIn.read(vardas, 20);

        begikas[i].vardas = vardas;
        fIn >> begikas[i].startoNr;

        int H, M, S;
        fIn >> H >> M >> S;
        begikas[i].startoLaikas = H * 3600 + M * 60 + S;
        begikas[i].finisoLaikas = 0;

        fIn.ignore(5, '\n');
    }

    fIn >> m;
    fIn.ignore(5, '\n');

    for (int i = 0; i < m; i++) {
        int begikoNr;
        fIn >> begikoNr;

        for (int j = 0; j < n; j++) {
            if (begikas[j].startoNr == begikoNr) {
                int H, M, S;
                fIn >> H >> M >> S;

                begikas[j].finisoLaikas = H * 3600 + M * 60 + S;

                begikas[j].baudos = 0;
                int nSuviu = 0;

                if (begikas[j].startoNr / 100 == 1) {
                    nSuviu = 2; // Merginos po 2 suvius isviso
                } else {
                    nSuviu = 4; // Vaikinai po 4 suvius isviso
                }

                for (int x = 0; x < nSuviu; x++) {
                    int pataikymai;
                    fIn >> pataikymai;

                    begikas[j].baudos += 5 - pataikymai;
                }
            }
        }
    }

    fIn.close();
}

void skaiciuotiRezultatus(int& nStart, begikoDuomenys* begikas, int& nRez, begikoRezultatai* rez) {
    nRez = 0;

    for (int i = 0; i < nStart; i++) {
        if (begikas[i].finisoLaikas == 0) continue;

        rez[nRez].vardas = begikas[i].vardas;
        rez[nRez].startoNr = begikas[i].startoNr;

        int trukme = begikas[i].finisoLaikas - begikas[i].startoLaikas;

        rez[nRez].H = trukme / 3600;
        rez[nRez].M = (trukme % 3600) / 60;
        rez[nRez].S = trukme % 60;

        rez[nRez].M += begikas[i].baudos;
        if (rez[nRez].M > 60) {
            rez[nRez].H += rez[nRez].M / 60;
            rez[nRez].M %= 60;
        }

        nRez++;
    }
}

void rikiuotiRezultatus(int& nRez, begikoRezultatai* rez) {
    for (int i = 0; i < nRez; i++) {
        for (int j = i + 1; j < nRez; j++) {
            if (rez[i].H > rez[j].H) {
                swap(rez[i], rez[j]);
            } else if (rez[i].H == rez[j].H) {
                if (rez[i].M > rez[j].M) {
                    swap(rez[i], rez[j]);
                } else if (rez[i].M == rez[j].M) {
                    if (rez[i].S > rez[j].S) {
                        swap(rez[i], rez[j]);
                    } else {
                        if (rez[i].vardas > rez[j].vardas) {
                            swap(rez[i], rez[j]);
                        }
                    }
                }
            }
        }
    }
}

void isvestis(int nRez, begikoRezultatai* rez) {
    ofstream fOut("U2rez.txt");

    fOut << "Merginos" << endl;
    for (int i = 0; i < nRez; i++) {
        if (rez[i].startoNr / 100 == 1) {
            fOut << rez[i].startoNr << " " << rez[i].vardas << " " << rez[i].H << " " << rez[i].M << " " << rez[i].S << endl;
        }
    }

    fOut << "Vaikinai" << endl;
    for (int i = 0; i < nRez; i++) {
        if (rez[i].startoNr / 100 == 2) {
            fOut << rez[i].startoNr << " " << rez[i].vardas << " " << rez[i].H << " " << rez[i].M << " " << rez[i].S << endl;
        }
    }

    fOut.close();
}

int main() {
    int nStartavusiu, nRezultatu;
    begikoDuomenys start[30];
    begikoRezultatai rez[30];

    nuskaitymas(nStartavusiu, start);
    skaiciuotiRezultatus(nStartavusiu, start, nRezultatu, rez);
    rikiuotiRezultatus(nRezultatu, rez);
    isvestis(nRezultatu, rez);


    return 0;
}