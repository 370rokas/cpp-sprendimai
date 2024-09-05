#include <fstream>

using namespace std;

void nuskaityti(int& prN, int* prZ, int& papN, int* papZ) {
    ifstream fI("Duomenys4.txt");
    fI >> prN;
    for (int i = 0; i < prN; i++) {
        fI >> prZ[i];
    }
    fI >> papN;
    for (int i = 0; i < papN; i++) {
        fI >> papZ[i];
    }
    fI.close();
}

void iterptiPastoZenklus(int& prN, int* prZ, int& papN, int* papZ) {
    for (int i = 0; i < papN; i++) {
        prZ[prN] = papZ[i];
        prN++;
    }
}

void rusiuotiPastoZenklus(int& n, int* z) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (z[i] > z[j]) {
                int temp = z[i];
                z[i] = z[j];
                z[j] = temp;
            }
        }
    }
}

void isvesti(int& n, int* z) {
    ofstream fO("Rezultatai4.txt");
    for (int i = 0; i < n; i++) {
        fO << z[i] << endl;
    }
    fO.close();
}

int main() {
    int prN, prZ[100], papN, papZ[100];

    nuskaityti(prN, prZ, papN, papZ);
    iterptiPastoZenklus(prN, prZ, papN, papZ);
    rusiuotiPastoZenklus(prN, prZ);
    isvesti(prN, prZ);

    return 0;
}