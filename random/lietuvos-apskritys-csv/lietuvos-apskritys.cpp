#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Apskritis {
    string apskritis;
    int savivaldybiuSkaicius;
    long plotas;
    long gyventojuSkaicius;
};

void nuskaityti(int& n, Apskritis* a) {
    ifstream fIn("duomenys.csv");
    n = 0;

    fIn.ignore(256, '\n');
    string eil;

    while (getline(fIn, eil)) {
        stringstream ss(eil);

        string nSav, plotas, gyventojuSkaicius;

        getline(ss, a[n].apskritis, ';');
        getline(ss, nSav, ';');
        getline(ss, plotas, ';');
        getline(ss, gyventojuSkaicius, '\n');

        a[n].savivaldybiuSkaicius = stoi(nSav);
        a[n].plotas = stol(plotas);
        a[n].gyventojuSkaicius = stol(gyventojuSkaicius);

        n++;
    }
}

// Rikiuoti pagal tanki
void rikiuoti(int& n, Apskritis* a) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].gyventojuSkaicius / a[i].plotas < a[j].gyventojuSkaicius / a[j].plotas) {
                swap(a[i], a[j]);
            }
        }
    }
}

void rezultatai(int n, Apskritis* a) {
    cout << "Top 3 tankiausios apskritys:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << a[i].apskritis << " - "  << fixed << setprecision(2) << a[i].gyventojuSkaicius / a[i].plotas << endl;
    }
}

int main() {
    int n;
    Apskritis a[100];

    nuskaityti(n, a);
    rikiuoti(n, a);
    rezultatai(n, a);

    return 0;
}