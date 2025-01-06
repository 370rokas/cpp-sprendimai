#include <iostream>
#include <fstream>

using namespace std;

struct balai {
    string nuo;
    string kam;
    int balai;
};

struct gavejas {
    string kam;
    int balai;
    int kiekGavo12;
};

void rikiuoti(int n, balai* b) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i].nuo > b[j].nuo) {
                swap(b[i], b[j]);
            } else if (b[i].nuo == b[j].nuo && b[i].balai < b[j].balai) {
                swap(b[i], b[j]);
            }
        }
    }
}

void nuskaitymas(int& n, balai* b) {
    ifstream f("Eurovizija.csv");
    n = 0;

    while (!f.eof()) {
        getline(f, b[n].nuo, ';');
        getline(f, b[n].kam, ';');
        f >> b[n].balai;

        f.ignore(5, '\n');
        n++;
    }

    if (b[n].balai == 0) {
        n--;
    }

    f.close();

    rikiuoti(n, b);

    ofstream o("rezultatai.txt");
    o << "Pradinis sarasas:" << endl;
    for (int i = 0; i < n; i++) {
        o << b[i].nuo << " " << b[i].kam << " " << b[i].balai << endl;
    }
    o << endl;
    o.close();
}

void kiekKasGavoTasku(int&n, balai*b) {
    int nGaveju = 0;
    gavejas g[2500];

    for (int i = 0; i < n; i++) {
        bool rasta = false;
        for (int j = 0; j < nGaveju; j++) {
            if (g[j].kam == b[i].kam) {
                g[j].balai += b[i].balai;
                if (b[i].balai == 12) {
                    g[j].kiekGavo12++;
                }
                rasta = true;
                break;
            }
        }

        if (!rasta) {
            g[nGaveju].kam = b[i].kam;
            g[nGaveju].balai = b[i].balai;
            if (b[i].balai == 12) {
                g[nGaveju].kiekGavo12 = 1;
            } else {
                g[nGaveju].kiekGavo12 = 0;
            }
            nGaveju++;
        }
    }

    // Rikiuoti pagal pavadinimus
    for (int i = 0; i < nGaveju - 1; i++) {
        for (int j = i + 1; j < nGaveju; j++) {
            if (g[i].kam > g[j].kam) {
                swap(g[i], g[j]);
            }
        }
    }

    // Spausdinimas
    ofstream o("rezultatai.txt", ios::app);
    o << "Saliu gauti taskai:" << endl;
    for (int i = 0; i < nGaveju; i++) {
        o << g[i].kam << " " << g[i].balai << endl;
    }

    int max12Skirimu = 0;
    for (int i = 0; i < nGaveju; i++) {
        if (g[i].kiekGavo12 > max12Skirimu) {
            max12Skirimu = g[i].kiekGavo12;
        }
    }

    o << endl << "Daugiausiai " << max12Skirimu << " kartu(-us) vienai saliai buvo skirta 12 balu" << endl;
    o << "Sios salys yra: ";
    for (int i = 0; i < nGaveju; i++) {
        if (g[i].kiekGavo12 == max12Skirimu) {
            o << g[i].kam << " ";
        }
    }

    o.close();
}

int main() {
    int n;
    balai b[2500];

    nuskaitymas(n ,b);
    kiekKasGavoTasku(n, b);

    return 0;
}