#include <fstream>
#include <iomanip>

using namespace std;

struct ZaidejoDuomenys {
    int zaidejoNr;
    int pataikytosBaudos;
    int mestosBaudos;
    int pataikytiDvitaskiai;
    int mestiDvitaskiai;
    int pataikytiTritaskiai;
    int mestiTritaskiai;
};

struct ZaidejoStatistika {
    int zaidejoNr = 0;
    int zaistiZaidimai = 0;
    double taskuVidurkis = 0;
    double pataikymuSantykis = 0;
};

void nuskaitytiDuomenis(int& nEiluciu, ZaidejoDuomenys* d) {
    ifstream failasIn("U1.txt");

    failasIn >> nEiluciu;
    for (int i = 0; i < nEiluciu; i++) {
        failasIn >> d[i].zaidejoNr >>
                    d[i].pataikytosBaudos >> d[i].mestosBaudos >>
                    d[i].pataikytiDvitaskiai >> d[i].mestiDvitaskiai >>
                    d[i].pataikytiTritaskiai >> d[i].mestiTritaskiai;

    }

    failasIn.close();
}

void skaiciuotiZaidejoStatistika(int& n, ZaidejoDuomenys* d, int zaidejoNr, ZaidejoStatistika& zaidejoStatistika) {
    zaidejoStatistika.zaidejoNr = zaidejoNr;

    int taskuSuma = 0;
    int pataikymuSuma = 0;
    int metimuSuma = 0;

    for (int i = 0; i < n; i++) {
        if (d[i].zaidejoNr == zaidejoNr) {
            zaidejoStatistika.zaistiZaidimai++;
            taskuSuma += d[i].pataikytosBaudos + (d[i].pataikytiDvitaskiai * 2) + (d[i].pataikytiTritaskiai * 3);
            pataikymuSuma += d[i].pataikytosBaudos + d[i].pataikytiDvitaskiai + d[i].pataikytiTritaskiai;
            metimuSuma += d[i].mestosBaudos + d[i].mestiDvitaskiai + d[i].mestiTritaskiai;
        }
    }

    zaidejoStatistika.taskuVidurkis = (double)taskuSuma / (double)zaidejoStatistika.zaistiZaidimai;
    zaidejoStatistika.pataikymuSantykis = (double)pataikymuSuma / (double)metimuSuma * 100;
}

void rasytiRezultatus(int n, ZaidejoStatistika* zs) {
    ofstream failasOut("U1rez.txt");

    int didzSuzaistuZaidimu = 0;
    for (int i = 0; i < n; i++) {
        if (zs[i].zaistiZaidimai > didzSuzaistuZaidimu) {
            didzSuzaistuZaidimu = zs[i].zaistiZaidimai;
        }
    }

    failasOut << didzSuzaistuZaidimu << endl;

    for (int i = 0; i < n; i++) {
        if (zs[i].zaistiZaidimai != didzSuzaistuZaidimu) continue;

        failasOut << zs[i].zaidejoNr << " " << fixed << setprecision(1) << zs[i].taskuVidurkis << " " << setprecision(0) << zs[i].pataikymuSantykis << " %" << endl;
    }

    failasOut.close();
}

void rastiVisusUnikaliusZaidejuNumerius(int& n, ZaidejoDuomenys* d, int& nZaideju, int* nrZaideju) {
    for (int i = 0; i < n; i++) {
        bool yra = false;

        for (int j = 0; j < nZaideju; j++) {
            if (nrZaideju[j] == d[i].zaidejoNr) {
                yra = true;
                continue;
            }
        }

        if (!yra) {
            nrZaideju[nZaideju] = d[i].zaidejoNr;
            nZaideju++;
        }
    }
}

int main() {
    int n = 0;                  // Zaideju duomenu skaicius
    ZaidejoDuomenys d[100];     // Zaideju duomenys

    int nZaideju = 0;           // Unikaliu zaideju skaicius
    int nrZaideju[100];         // Unikalus zaideju numeriai
    ZaidejoStatistika zs[100];  // Zaideju statistikos

    nuskaitytiDuomenis(n ,d);
    rastiVisusUnikaliusZaidejuNumerius(n, d, nZaideju, nrZaideju);

    for (int i = 0; i < nZaideju; i++) {
        skaiciuotiZaidejoStatistika(n, d, nrZaideju[i], zs[i]);
    }

    rasytiRezultatus(nZaideju, zs);

    return 0;
}