#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Vertinimai {
    string pavadinimas;
    int taskai;
    int sugautaMase;
};

struct Zuvis {
    string pavadinimas;
    int svoris;
};

struct Dalyvis {
    string vardas;
    int nZuvu;
    int taskai;

    Zuvis zuvys[5];
};

void nuskaityti(int& nD, Dalyvis* d, int& nV, Vertinimai* v) {
    ifstream in("U2.txt");
    in >> nD;
    in.ignore(5, '\n');

    for (int i = 0; i < nD; i++) {
        char temp[20];
        in.get(temp, 20);

        d[i].vardas = temp;
        in >> d[i].nZuvu;
        in.ignore(5, '\n');

        for (int j = 0; j < d[i].nZuvu; j++) {
            in.get(temp, 20);

            d[i].zuvys[j].pavadinimas = temp;
            in >> d[i].zuvys[j].svoris;
            in.ignore(5, '\n');
        }
    }

    in >> nV;
    in.ignore(5, '\n');

    for (int i = 0; i < nV; i++) {
        char temp[20];
        in.get(temp, 20);

        v[i].pavadinimas = temp;
        in >> v[i].taskai;
        in.ignore(5, '\n');
    }

    in.close();
}

void suskaiciuotiRezultatus(int nD, Dalyvis* d, int nV, Vertinimai* v) {
    for (int i = 0; i < nV; i++) {
        v[i].sugautaMase = 0;
    }

    for (int i = 0; i < nD; i++) {
        d[i].taskai = 0;

        for (int j = 0; j < d[i].nZuvu; j++) {
            for (int k = 0; k < nV; k++) {
                if (d[i].zuvys[j].pavadinimas == v[k].pavadinimas) {
                    d[i].taskai += v[k].taskai;

                    v[k].sugautaMase += d[i].zuvys[j].svoris;
                }
            }

            if (d[i].zuvys[j].svoris >= 200) {
                d[i].taskai += 30;
            } else {
                d[i].taskai += 10;
            }
        }
    }
}

void rikiuotiDalyvius(int nD, Dalyvis* d) {
    for (int i = 0; i < nD - 1; i++) {
        for (int j = i + 1; j < nD; j++) {
            if (d[i].taskai < d[j].taskai) {
                swap(d[i], d[j]);
            }
        }
    }
}

void rikiuotiZuvis(int nZ, Vertinimai* z) {
    // Pagal mase mazejanciai, poto pagal pavadinima abecele

    for (int i = 0; i < nZ - 1; i++) {
        for (int j = i + 1; j < nZ; j++) {
            if (z[i].sugautaMase < z[j].sugautaMase) {
                swap(z[i], z[j]);
            } else if (z[i].sugautaMase == z[j].sugautaMase) {
                if (z[i].pavadinimas > z[j].pavadinimas) {
                    swap(z[i], z[j]);
                }
            }
        }
    }
}

void isvestis(int nD, Dalyvis* d, int nV, Vertinimai* v) {
    ofstream out("U2rez.txt");

    out << "Dalyviai" << endl;
    for (int i = 0; i < nD; i++) {
        out << d[i].vardas << " " << d[i].taskai << endl;
    }

    out << "Laimikis" << endl;
    for (int i = 0; i < nV; i++) {
        out << v[i].pavadinimas << " " << v[i].sugautaMase << endl;
    }

    out.close();
}

int main() {
    int nD, nV;
    Dalyvis d[30];
    Vertinimai v[30];

    nuskaityti(nD, d, nV, v);
    suskaiciuotiRezultatus(nD, d, nV, v);

    rikiuotiDalyvius(nD, d);
    rikiuotiZuvis(nV, v);

    isvestis(nD, d, nV, v);

    return 0;
}