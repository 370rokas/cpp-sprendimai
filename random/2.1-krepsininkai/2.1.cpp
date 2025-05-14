#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Zaidejas {
    string vardas;
    string komanda;
    int PTS;
    int FGA;
    int FTA;
    double TS;
};

void nuskaityti(int &n, Zaidejas* z) {
    ifstream fIn("duomenys.csv");
    n = 0;

    string eil;
    while (!fIn.eof()) {
        getline(fIn, eil);
        if (eil.empty()) continue;

        stringstream ss(eil);
        getline(ss, z[n].vardas, ',');
        getline(ss, z[n].komanda, ',');

        string PTS, FGA, FTA;
        getline(ss, PTS, ',');
        getline(ss, FGA, ',');
        getline(ss, FTA, ',');

        z[n].PTS = stoi(PTS);
        z[n].FGA = stoi(FGA);
        z[n].FTA = stoi(FTA);

        n++;
    }

    fIn.close();
}

void suskaiciuotiTS(int n, Zaidejas* z) {
    for (int i = 0; i < n; i++) {
        z[i].TS = z[i].PTS / (2 * (z[i].FGA + 0.44 * z[i].FTA));
    }
}

void rikiuoti(int n, Zaidejas* z) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (z[i].komanda > z[j].komanda ||
                (z[i].komanda == z[j].komanda && z[i].TS < z[j].TS)) {
                swap(z[i], z[j]);
            }
        }
    }
}

void rezultatai(int n, Zaidejas* z) {
    ofstream fOut("rezultatai.csv");
    for (int i = 0; i < n; i++) {
        fOut << z[i].vardas << "," << z[i].komanda << "," << z[i].PTS << "," << z[i].FGA << "," << z[i].FTA << "," << setprecision(2) << z[i].TS << endl;
    }
    fOut.close();
}

int main() {
    int n;
    Zaidejas z[50];

    nuskaityti(n, z);
    suskaiciuotiTS(n, z);
    rikiuoti(n, z);
    rezultatai(n, z);

    return 0;
}
