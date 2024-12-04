#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct irasas {
    string pavadinimas;
    int metai;
    int trukmeH;
    int trukmeM;
    int kartai;
};

void nuskaityti(int& n, irasas* i) {
    ifstream fIn("DuomAlbumai.txt");

    fIn >> n;
    fIn.ignore(2, '\n');
    for (int j = 0; j < n; j++) {
        char eil[21];
        fIn.get(eil, 21);
        i[j].pavadinimas = eil;

        fIn >> i[j].metai >> i[j].trukmeH >> i[j].trukmeM >> i[j].kartai;
        fIn.ignore(2, '\n');
    }

    fIn.close();
}

void apskaiciuotiKolekcijosTrukme(int n, irasas* i, int& sH, int& sM) {
    sH = 0;
    sM = 0;

    for (int j = 0; j < n; j++) {
        sH += i[j].trukmeH;
        sM += i[j].trukmeM;
    }

    sH += sM / 60;
    sM %= 60;
}

void suskaiciuotiVidPerklausas(int n, irasas* i, double& vidPerklausos) {
    int s = 0;

    for (int j = 0; j < n; j++) {
        s += i[j].kartai;
    }

    vidPerklausos = (double) s / (double) n;
}

void surikiuotiAlbumus(int n, irasas* i) {
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (i[j].kartai > i[k].kartai) {
                swap(i[j], i[k]);
            }
        }
    }
}

void isvestis(int n, irasas* i, int sH, int sM, double vidPerklausos) {
    ofstream fOut("RezAlbumai.txt");

    fOut << sH << " " << sM << endl;
    fOut << setprecision(3) << vidPerklausos << endl;
    for (int j = 0; j < n; j++) {
        fOut << i[j].pavadinimas << " " << i[j].metai << endl;
    }

    fOut.close();
}

int main() {
    int n, sH, sM;
    double vidPerklausos;
    irasas albumai[300];

    nuskaityti(n, albumai);
    apskaiciuotiKolekcijosTrukme(n, albumai, sH, sM);
    suskaiciuotiVidPerklausas(n, albumai, vidPerklausos);
    surikiuotiAlbumus(n, albumai);
    isvestis(n, albumai, sH, sM, vidPerklausos);

    return 0;
}