#include <iostream>
#include <fstream>

using namespace std;

struct Keleivis {
    string vardas;
    int k;
    int s[20];
};

void nuskaityti(int& n, int& m, int&x, int& y, Keleivis* k) {
    ifstream fIn("in.txt");

    fIn >> n;
    for (int i = 0; i < n; i++) {
        fIn >> k[i].vardas >> k[i].k;
        for (int j = 0; j < k[i].k; j++) {
            fIn >> k[i].s[j];
        }
    }

    fIn >> m >> x >> y;
    fIn.close();
}

int kiekMazesniuNeguM(int n, int m, Keleivis* k) {
    int kiek = 0;

    for (int i = 0; i < n; i++) {
        if (k[i].k <= m) {
            kiek++;
        }
    }

    return kiek;
}

int kiekDaugiauUz(int n, int x, Keleivis* k) {
    int kiek = 0;

    for (int i = 0; i < n; i++) {
        int masesSuma = 0;
        for (int j = 0; j < k[i].k; j++) {
            masesSuma = masesSuma + k[i].s[j];
        }

        if (masesSuma > x) {
            kiek++;
        }
    }

    return kiek;
}

int kiekVirsijaVidurki(int n, Keleivis* k) {
    double vid = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[i].k; j++) {
            vid = vid + k[i].s[j];
        }
    }

    vid = vid / n;

    int kiek = 0;
    for (int i = 0; i < n; i++) {
        double bagazoMase = 0;

        for (int j = 0; j < k[i].k; j++) {
            bagazoMase = bagazoMase + k[i].s[j];
        }

        if (abs(vid - bagazoMase) > 1) {
            kiek++;
        }
    }

    return kiek;
}

int vienoKeleivioDidziausiaMase(int n, Keleivis* k) {
    int didMase = 0;

    for (int i = 0; i < n; i++) {
        int mase = 0;

        for (int j = 0; j < k[i].k; j++) {
            mase = mase + k[i].s[j];
        }

        if (mase > didMase) {
            didMase = mase;
        }
    }

    return didMase;
}

void rezultatai(int n, Keleivis* k, int kiekNevirsija, int kiekVirsijaX, int kiekVirsijaVid, int y) {
    cout << kiekNevirsija << endl << kiekVirsijaX << endl << kiekVirsijaVid << endl;

    int didMase = vienoKeleivioDidziausiaMase(n, k);
    for (int i = 0; i < n; i++) {
        int mase = 0;

        for (int j = 0; j < k[i].k; j++) {
            mase = mase + k[i].s[j];
        }

        if (abs(mase-didMase) >= y) {
            cout << k[i].vardas << endl;
        }
    }
}

int main() {
    int n, m, x, y;
    Keleivis k[20];

    nuskaityti(n, m, x, y, k);
    int kiekNevirsija = kiekMazesniuNeguM(n, m, k);
    int kiekVirsijaX = kiekDaugiauUz(n, x, k);
    int kiekVirsijaVid = kiekVirsijaVidurki(n, k);

    rezultatai(n, k, kiekNevirsija, kiekVirsijaX, kiekVirsijaVid, y);

    return 0;
}