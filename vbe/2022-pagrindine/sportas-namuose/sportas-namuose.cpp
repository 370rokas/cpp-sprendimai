#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct pratimas {
    string pav;
    string laikas;
    int ilgis;
};

struct diena {
    int nPratimu;
    pratimas pratimai[7];
};

struct pratimoInfo {
    string pav;
    int sugaista;
    int nDienu;
    int rytas;
    int diena;
    int vakaras;
};

void nuskaityti(int &n, diena *d) {
    ifstream fIn("U2.txt");

    fIn >> n;

    for (int i = 0; i < n; i++) {
        fIn >> d[i].nPratimu;

        for (int j = 0; j < d[i].nPratimu; j++) {
            char pav[16] = {0}, laik[9] = {0};

            fIn.ignore(1, ' ');
            fIn.get(pav, 15);
            fIn.ignore(1, ' ');

            fIn.get(laik, 8);
            fIn.ignore(1, ' ');

            d[i].pratimai[j].pav = pav;
            d[i].pratimai[j].laikas = laik;

            fIn >> d[i].pratimai[j].ilgis;
        }

        fIn.ignore(1, '\n');
    }
}

void apdorotiDuomenis(int n, diena* d, int& nR, pratimoInfo* r) {
    nR = 0;

    for (int dIdx = 0; dIdx < n; dIdx++) {
        int nSiandienBuvusiuPratimu = 0;
        string siandienBuvePratimai[7] = {""};

        for (int pIdx = 0; pIdx < d[dIdx].nPratimu; pIdx++) {
            int idx = -1; // Pratimo indeksas pratimo info masyve

            for (int rIdx = 0; rIdx < nR; rIdx++) {
                if (r[rIdx].pav == d[dIdx].pratimai[pIdx].pav) {
                    idx = rIdx; // Jau turim si pratima info masyve, reik tik duomenis papildyti
                    break;
                }
            }

            // Sukuriam nauja pratimo info, nes jo nera
            if (idx == -1) {
                r[nR].pav = d[dIdx].pratimai[pIdx].pav;
                r[nR].sugaista = 0;
                r[nR].nDienu = 0;
                r[nR].rytas = 0;
                r[nR].diena = 0;
                r[nR].vakaras = 0;

                idx = nR;
                nR++;
            }

            // Pratimo sugaistas laikas
            r[idx].sugaista += d[dIdx].pratimai[pIdx].ilgis;

            // Paziurim ar siandien dar sito pratimo nedare
            bool pratimasSiandienDarytas = false;
            for (int i = 0; i < nSiandienBuvusiuPratimu; i++) {
                if (siandienBuvePratimai[i] == d[dIdx].pratimai[pIdx].pav) {
                    pratimasSiandienDarytas = true;
                    break;
                }
            }

            // Jeigu dar siandien nedare to pratimo
            if (!pratimasSiandienDarytas) {
                // Pridedam pratima i siandien buvusiu pratimu sarasa
                siandienBuvePratimai[nSiandienBuvusiuPratimu] = d[dIdx].pratimai[pIdx].pav;
                nSiandienBuvusiuPratimu++;

                // Padidinam kiek dienu dare si pratima reiksme
                r[idx].nDienu++;
            }

            // Paros laiko statistika
            if (d[dIdx].pratimai[pIdx].laikas == "Rytas  ") {
                r[idx].rytas += 1;
            } else if (d[dIdx].pratimai[pIdx].laikas == "Diena  ") {
                r[idx].diena += 1;
            } else if (d[dIdx].pratimai[pIdx].laikas == "Vakaras") {
                r[idx].vakaras += 1;
            }
        }
    }
}

void rikiuotiMasyva(int& n, pratimoInfo* d) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (d[i].pav > d[j].pav) {
                swap(d[i], d[j]);
            }
        }
    }
}

void isvestis(int& n, pratimoInfo* d) {
    ofstream fOut("U2rez.txt");

    for (int i = 0; i < n; i++) {
        fOut << d[i].pav << " " << d[i].nDienu << " " << d[i].sugaista << endl;

        if (d[i].rytas > 0) {
            fOut << "Rytas   " << d[i].rytas << endl;
        }

        if (d[i].diena > 0) {
            fOut << "Diena   " << d[i].diena << endl;
        }

        if (d[i].vakaras > 0) {
            fOut << "Vakaras " << d[i].vakaras << endl;
        }
    }

    fOut.close();
}

int main() {
    diena p[31];
    pratimoInfo data[200];
    int nDienu, nPratimu;

    nuskaityti(nDienu, p);
    apdorotiDuomenis(nDienu, p, nPratimu, data);
    rikiuotiMasyva(nPratimu, data);
    isvestis(nPratimu, data);

    return 0;
}