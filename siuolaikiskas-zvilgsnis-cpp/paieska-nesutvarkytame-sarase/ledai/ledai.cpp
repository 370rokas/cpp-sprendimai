#include <iostream>
#include <fstream>

using namespace std;

struct ledai {
    string pavadinimas;
    double suma;
};

void nuskaityti(int& nL, ledai* l) {
    ifstream fIn("in.txt");

    nL = 0;

    int n, kiekis;
    double kaina;

    fIn >> n;
    fIn.ignore(10, '\n');

    cout << n << endl;

    for (int i = 0; i < n; i++) {
        char eil[21];
        fIn.get(eil, 20);

        fIn >> kiekis >> kaina;

        bool rastas = false;
        for (int j = 0; j < nL; j++) {
            if (l[j].pavadinimas == string(eil)) {
                l[j].suma = l[j].suma + kiekis * kaina;
                rastas = true;
                break;
            }
        }

        if (!rastas) {
            l[nL].pavadinimas = string(eil);
            l[nL].suma = kiekis * kaina;
            nL++;
        }

        fIn.ignore(10, '\n');
    }

    fIn.close();
}

void rusiuotiPagalKainas(int nL, ledai* l) {
    for (int i = 0; i < nL - 1; i++) {
        for (int j = i + 1; j < nL; j++) {
            if (l[i].suma < l[j].suma) {
                swap(l[i], l[j]);
            }
        }
    }
}

void isvestis(int nL, ledai* l) {
    for (int i = 0; i < nL; i++) {
        cout << l[i].pavadinimas << " " << l[i].suma << endl;
    }
}

int main() {
    int n;
    ledai l[20];

    nuskaityti(n, l);
    rusiuotiPagalKainas(n, l);
    isvestis(n, l);

    return 0;
}