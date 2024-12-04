#include <fstream>
#include <string>

using namespace std;

struct avis {
    string vardas;
    int koeficientas;
    char DNR[20];
};

void nuskaitymas(int& n, int& m, int& t, avis* a) {
    ifstream fIn("U2.txt");
    fIn >> n >> m >> t;
    fIn.ignore(5, '\n');

    for (int i = 0; i < n; i++) {
        char vardas[11];
        fIn.read(vardas, 10);
        a[i].vardas = vardas;

        fIn.ignore(1, ' ');

        fIn.read(a[i].DNR, m);

        fIn.ignore(5, '\n');
    }

    fIn.close();
}

int skaiciuotiSutapimoKoeficienta(avis a1, avis a2, int m) {
    int koeficientas = 0;

    for (int i = 0; i < m; i++) {
        if (a1.DNR[i] == a2.DNR[i]) {
            koeficientas++;
        }
    }

    return koeficientas;
}

void rikiuotiPagalKoeficientus(int n, avis* a) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i].koeficientas < a[j].koeficientas) {
                swap(a[i], a[j]);
            } else if (a[i].koeficientas == a[j].koeficientas) {
                if (a[i].vardas > a[j].vardas) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
}

void tirtiAvis(int n, int m, int t, avis* a) {
    for (int i = 0; i < n; i++) {
        a[i].koeficientas = skaiciuotiSutapimoKoeficienta(a[t-1], a[i], m);
    }
}

void rezultatai(int n, avis* a) {
    ofstream fOut("U2rez.txt");

    fOut << a[0].vardas << endl;
    for (int i = 1; i < n; i++) {
        fOut << a[i].vardas << " " << a[i].koeficientas << endl;
    }

    fOut.close();
}

int main() {
    int n, m, t;
    avis a[20];

    nuskaitymas(n, m, t, a);
    tirtiAvis(n, m, t, a);
    rikiuotiPagalKoeficientus(n, a);
    rezultatai(n, a);

    return 0;
}