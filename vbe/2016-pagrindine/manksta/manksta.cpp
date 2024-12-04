#include <fstream>
#include <string>

using namespace std;

struct Pratimas {
    string pavadinimas;
    int kartai;
};

void ivestis(int& n, Pratimas* p) {
    ifstream fIn("U2.txt");

    fIn >> n;
    fIn.ignore(5, '\n');

    for (int i = 0; i < n; i++) {
        char eil[21];
        fIn.read(eil, 20);

        p[i].pavadinimas = eil;
        fIn >> p[i].kartai;
        fIn.ignore(5, '\n');
    }

    fIn.close();
}

void isvestis(int n, Pratimas* p) {
    ofstream fOut("U2rez.txt");

    fOut << n << endl;

    for (int i = 0; i < n; i++) {
        fOut << p[i].pavadinimas << " " << p[i].kartai << endl;
    }

    fOut.close();
}

void rikiuoti(int n, Pratimas* p) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (p[i].kartai < p[j].kartai) {
                swap(p[i], p[j]);
            } else if (p[i].kartai == p[j].kartai && p[i].pavadinimas > p[j].pavadinimas) {
                swap(p[i], p[j]);
            }
        }
    }
}

void skaiciuoti(int& n, int& nRes, Pratimas* p, Pratimas* pRes) {
    nRes = 0;

    for (int i = 0; i < n; i++) {
        bool rasta = false;

        for (int j = 0; j < nRes; j++) {
            if (p[i].pavadinimas == pRes[j].pavadinimas) {
                pRes[j].kartai += p[i].kartai;
                rasta = true;
                break;
            }
        }

        if (!rasta) {
            pRes[nRes] = p[i];
            nRes++;
        }
    }
}

int main() {
    int n, nRes;
    Pratimas p[100], pRes[100];

    ivestis(n, p);
    skaiciuoti(n, nRes, p, pRes);
    rikiuoti(nRes, pRes);
    isvestis(nRes, pRes);

    return 0;
}
