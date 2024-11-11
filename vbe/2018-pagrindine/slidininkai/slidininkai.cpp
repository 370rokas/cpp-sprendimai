#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct StartoDuom {
    string vardas;
    int val;
    int min;
    int sec;
};

struct FinisoDuom {
    string vardas;
    int val;
    int min;
    int sec;
};

void nuskaitymas(int& nS, int& nF, StartoDuom* S, FinisoDuom* F) {
    ifstream fIn("U2.txt");
    char buff[21];

    fIn >> nS;
    for (int i = 0; i < nS; i++) {
        fIn.read(buff, 20);
        S[i].vardas = buff;

        fIn >> S[i].val >> S[i].min >> S[i].sec;


        cout << S[i].vardas << S[i].val << " " << S[i].min << " " << S[i].sec << endl;
    }

    fIn.close();
}

int main() {

    int nS, nF;
    StartoDuom S[30];
    FinisoDuom F[30];

    nuskaitymas(nS, nF, S, F);

    return 0;
}