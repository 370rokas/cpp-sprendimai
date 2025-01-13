#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct Televizorius {
    string Pavadinimas;
    string Gamintojas;
    string SkiramojiGeba;
    double IstrizaineInch;
    double IstrizaineCm;
    double Mase;
    double Kaina;
};

void nuskaityti(int& n, Televizorius* t) {
    ifstream fd("Knyga1.csv");

    // Ignoruoti pirmą eilutę (nenaudojama)
    fd.ignore('\n');

    // Skaityti eilutes kol nesibaigė;

    string line;
    getline(fd, line); // Nuskaitom pirma eil, ir su ja nieko nedarom (ignoruojam)

    while (getline(fd, line)) {
        stringstream ss(line);

        // Skaicius nuskaitom i laikinus kintamuosius
        string istrizaineInch, istrizaineCm, mase, kaina;

        // Nuskaitom eilutes duomenis
        getline(ss, t[n].Pavadinimas, ';');
        getline(ss, t[n].SkiramojiGeba, ';');
        getline(ss, istrizaineInch, ';');
        getline(ss, istrizaineCm, ';');
        getline(ss, t[n].Gamintojas, ';');
        getline(ss, mase, ';');
        getline(ss, kaina, '\n');

        // Konvertuojam string i double
        t[n].IstrizaineInch = stof(istrizaineInch);
        t[n].IstrizaineCm = stof(istrizaineCm);
        t[n].Mase = stof(mase);
        t[n].Kaina = stof(kaina);

        n++;
    }

    fd.close();
}


string brangiausiasTelevizorius(int n, Televizorius* t) {
    double maxKaina = t[0].Kaina;
    string pavadinimas = t[0].Pavadinimas;

    for (int i = 1; i < n; i++) {
        if (t[i].Kaina > maxKaina) {
            maxKaina = t[i].Kaina;
            pavadinimas = t[i].Pavadinimas;
        }
    }

    return pavadinimas;
}

string pigiausiasTelevizorius(int n, Televizorius* t) {
    double minKaina = t[0].Kaina;
    string pavadinimas = t[0].Pavadinimas;

    for (int i = 1; i < n; i++) {
        if (t[i].Kaina < minKaina) {
            minKaina = t[i].Kaina;
            pavadinimas = t[i].Pavadinimas;
        }
    }

    return pavadinimas;
}

string didzPasiula(int n, Televizorius* t) {
    int pasiula = 0;
    string gamintojas = t[0].Gamintojas;

    for (int i = 1; i < n; i++) {
        if (t[i].Gamintojas == gamintojas) {
            pasiula++;
        }
    }

    return gamintojas;
}

void isvestis(int n, Televizorius* t) {
    string brangiausias = brangiausiasTelevizorius(n, t);
    string pigiausias = pigiausiasTelevizorius(n, t);
    string didziausiaPasiula = didzPasiula(n, t);

    for (int i = 0; i < n; i++) {
        cout << t[i].Pavadinimas << " " << t[i].SkiramojiGeba << " " << t[i].IstrizaineInch << " " << t[i].IstrizaineCm << " " << t[i].Gamintojas << " " << t[i].Mase << " " << t[i].Kaina << endl;
    }

    cout << "Brangiausias televizorius: " << brangiausias << endl;
    cout << "Pigiausias televizorius: " << pigiausias << endl;
    cout << "Didziausia pasiula " << didziausiaPasiula << " gamintojo televizoriu" << endl;
}

int main() {
    int n;
    Televizorius t[100];

    nuskaityti(n, t);
    isvestis(n, t);

    return 0;
}
