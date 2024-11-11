#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct olimpines {
    string pavarde;
    double rezultatas;
};

struct pasiekimai {
    string pavarde;
    string valstybe;

    long data;
    double rezultatas;
};

struct bendrasRez {
    string pavarde;

    double olimpRez;
    double pasiekRez;
    double skirtumas;
};

void nuskaitymas(int& n, olimpines* o, pasiekimai* p) {
    ifstream fOlimpines("Olimpines.txt");

    fOlimpines >> n;
    for (int i = 0; i < n; i++) {
        fOlimpines >> o[i].pavarde >> o[i].rezultatas;
    }

    fOlimpines.close();
    ifstream fPasiekimai("Pasiekimai.csv");

    for (int i = 0; i < n; i++) {
        fPasiekimai.ignore(1);
        getline(fPasiekimai, p[i].pavarde, ';');

        fPasiekimai >> p[i].rezultatas;
        fPasiekimai.ignore(1);

        fPasiekimai >> p[i].data;
        fPasiekimai.ignore(1);

        fPasiekimai >> p[i].valstybe;
        fPasiekimai.ignore(5, '\n');
    }

    fPasiekimai.close();
}

void sukurtiFaila() {
    ofstream fRez("Rezultatai.txt");

    fRez << "Disko metimo duomenu analizes rezultatai:" << endl;
    fRez << endl;
    fRez << "Olimpines zaidynes:" << endl;

    fRez.close();
}

double skirtumasTarpDidIrMazOlimpinese(int n, olimpines* o) {
    double didziausias = o[0].rezultatas;
    double maziausias = o[0].rezultatas;

    for (int i = 1; i < n; i++) {
        if (o[i].rezultatas > didziausias) {
            didziausias = o[i].rezultatas;
        }

        if (o[i].rezultatas < maziausias) {
            maziausias = o[i].rezultatas;
        }
    }

    double skirtumas = didziausias - maziausias;

    ofstream fRez("Rezultatai.txt", ios::app);
    fRez << "Skirtumas tarp didziausio ir maziausio rezultato " << skirtumas << " m." << endl;
    fRez.close();

    return skirtumas;
}

double vidutinisRezultatasOlimpinese(int n, olimpines* o) {
    double suma = 0;

    for (int i = 0; i < n; i++) {
        suma += o[i].rezultatas;
    }

    double vidurkis = suma / n;

    ofstream fRez("Rezultatai.txt", ios::app);
    fRez << "Vidutiniskai diskas skirejo " << vidurkis << " m." << endl;
    fRez.close();

    return vidurkis;
}

double vidurkiuSkirtumas(double vidOlimpinese, double vidPasiekimuose) {
    double vidurkiuSkirtumas = vidPasiekimuose - vidOlimpinese;
    ofstream fRez("Rezultatai.txt", ios::app);

    if (vidurkiuSkirtumas > 0) {
        fRez << "Vidurkis " << vidurkiuSkirtumas << " m didesnis negu olimpinese zaidynese." << endl;
    } else {
        fRez << "Vidurkis " << vidurkiuSkirtumas << " m mazesnis negu olimpinese zaidynese." << endl;
    }

    fRez.close();
    return vidurkiuSkirtumas;
}

double vidutinisRezultatasPasiekimuose(int n, pasiekimai* p) {
    double suma = 0;

    for (int i = 0; i < n; i++) {
        suma += p[i].rezultatas;
    }

    double vidurkis = suma / n;

    ofstream fRez("Rezultatai.txt", ios::app);
    fRez << endl;
    fRez << "Geriausi rezultatai:" << endl;
    fRez << "Vidutiniskai diskas skriejo " << vidurkis << " m." << endl;
    fRez.close();

    return vidurkis;
}

int dataIMetus(long data) {
    return data / 10000;
}

void seniausiasPasiekimas(int n, pasiekimai* p) {
    ofstream fRez("Rezultatai.txt", ios::app);

    double seniausia = p[0].data;
    int indeksas = 0;

    for (int i = 1; i < n; i++) {
        if (p[i].data < seniausia) {
            seniausia = p[i].data;
            indeksas = i;
        }
    }

    fRez << endl;
    fRez << "Seniausiai pasiektas geriausias rezultatas: " << endl;
    fRez << p[indeksas].pavarde << " " << p[indeksas].valstybe << " " << dataIMetus(p[indeksas].data) << " " << p[indeksas].rezultatas << " m." << endl;

    fRez.close();
}

string kodasIPavarde(string kodas) {
    return kodas.erase(0, 1);
}

void skirtumaiTarpPasiekimu(int n, pasiekimai* p, olimpines* o) {
    ofstream fRez("Rezultatai.txt", ios::app);

    // Surasti visu sportininku rezultatus
    int nR = 0;
    bendrasRez r[25];

    // Pridet pasiekimus
    for (int i = 0; i < n; i++) {
        r[i].pavarde = p[i].pavarde;
        r[i].pasiekRez = p[i].rezultatas;
        nR = nR + 1;
    }

    // Pridet olimpiniu rezultata ir suskaiciuot skirtuma
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < nR; j++) {
            if (kodasIPavarde(o[i].pavarde) == r[j].pavarde) {
                r[j].olimpRez = o[i].rezultatas;

                r[j].skirtumas = r[j].pasiekRez - r[j].olimpRez;
            }
        }
    }

    // Rusiuoti masyva
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (r[i].skirtumas > r[j].skirtumas) {
                swap(r[i], r[j]);
            }
        }
    }

    fRez << endl;
    fRez << "Skirtumas tarp sportininku pasiekimu:" << endl;

    for (int i = 0; i < n; i++) {
        fRez << r[i].pavarde << " " << r[i].skirtumas << " m" << endl;
    }

    fRez.close();
}

int main() {
    int n;
    olimpines o[25];
    pasiekimai p[25];

    nuskaitymas(n, o, p);

    sukurtiFaila();
    double vidOlimpinese = vidutinisRezultatasOlimpinese(n, o);
    skirtumasTarpDidIrMazOlimpinese(n, o);

    double vidPasiekimuose = vidutinisRezultatasPasiekimuose(n, p);
    vidurkiuSkirtumas(vidOlimpinese, vidPasiekimuose);

    seniausiasPasiekimas(n, p);
    skirtumaiTarpPasiekimu(n, p, o);

    return 0;
}