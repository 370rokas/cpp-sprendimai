#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Parduotuve {
    string Pavadinimas;
    string Adresas;
    int PrekiuSkaicius;
    int PardavimuSuma;
    int Nuolaidos;
    int EfekKof;
};

void nuskaitymas(int& n, Parduotuve* p) {
    ifstream fIn("Parduotuves.csv");
    string line;
    n = 0;

    fIn.ignore(256, '\n');

    while (getline(fIn, line)) {
        stringstream iss(line);
        string nPrekiu, nPardav, nuol;

        getline(iss, p[n].Pavadinimas, ',');
        getline(iss, p[n].Adresas, ',');
        getline(iss, nPrekiu, ',');
        getline(iss, nPardav, ',');
        getline(iss, nuol, '\n');

        p[n].PrekiuSkaicius = stoi(nPrekiu);
        p[n].PardavimuSuma = stoi(nPardav);
        p[n].Nuolaidos = stoi(nuol);

        n++;
    }

    fIn.close();
}

void skaiciuotiKoeficientus(int n, Parduotuve* p) {
    for (int i = 0; i < n; i++) {
        p[i].EfekKof = p[i].PardavimuSuma - p[i].Nuolaidos + (p[i].PrekiuSkaicius * 2);
    }
}

void rikiuoti(int n, Parduotuve* p) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].EfekKof < p[j].EfekKof) {
                swap(p[i], p[j]);
            }
        }
    }
}

void rezultatai(int n, Parduotuve* p) {
    ofstream fOut("Efektyvumas.csv");

    fOut << "Pavadinimas,Adresas,Efektyvumas" << endl;
    for (int i = 0; i < n; i++) {
        fOut << p[i].Pavadinimas << "," << p[i].Adresas << "," << p[i].EfekKof << endl;
    }

    fOut.close();
}

int main() {
    int n;
    Parduotuve p[100];

    nuskaitymas(n, p);
    skaiciuotiKoeficientus(n, p);
    rikiuoti(n, p);
    rezultatai(n, p);

    return 0;
}