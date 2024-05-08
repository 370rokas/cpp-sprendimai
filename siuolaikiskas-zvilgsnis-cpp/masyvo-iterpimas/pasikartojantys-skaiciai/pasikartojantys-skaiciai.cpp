#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int kurYraSkaiciusSekoje(int& n, int* seka, int sk) {
    for (int i = 0; i < n; i++) {
        if (seka[i] == sk) {
            return i;
        }
    }

    return -1;
}

void nuskaityti(int& n, int* seka) {
    ifstream fIn("in.txt");

    fIn >> n;
    for (int i = 0; i < n; i++) {
        fIn >> seka[i];
    }

    fIn.close();
}

void isvestiSeka(int n, int* seka) {
    int dabSk = seka[0];
    for (int i = 0; i < n; i++) {
        if (dabSk == seka[i]) {
            cout << seka[i] << " ";
        } else {
            cout << endl << seka[i] << " ";
            dabSk = seka[i];
        }
    }

    cout << endl;
}

void iterptiSkaiciu(int& n, int* seka, int sk) {
    int idx = kurYraSkaiciusSekoje(n, seka, sk);

    if (idx == -1) {
        seka[n] = sk;
        n++;
    } else {
        for (int i = n; i >= idx; i--) {
            seka[i+1] = seka[i];
        }

        n++;
        seka[idx] = sk;
    }
}

void iterptiSkaicius(int& n, int* seka, int iN, int* iS) {
    for (int i = 0; i < iN; i++) {
        iterptiSkaiciu(n, seka, iS[i]);
    }
}

void sekosDazniuLentele(int& n, int* seka) {
    int dabSk = seka[0];
    int dabN = 0;

    for (int i = 0; i < n; i++) {
        if (dabSk == seka[i]) {
            dabN++;
        } else {
            cout << setw(4) << dabSk << setw(1) << "|" << dabN << endl;
            dabSk = seka[i];
            dabN = 1;
        }
    }

    cout << setw(4) << dabSk << setw(1) << "|" << dabN << endl;
}

int main()
{
    int n, seka[100];
    nuskaityti(n, seka);

    cout << "Skaiciu seka" << endl;
    cout << "--------------" << endl;
    isvestiSeka(n, seka);
    cout << "--------------" << endl;
    cout << "Skaiciaus 11 indeksas masyve " << kurYraSkaiciusSekoje(n, seka, 11) << endl;

    iterptiSkaiciu(n, seka, 11);
    cout << "Skaiciu seka" << endl;
    cout << "--------------" << endl;
    isvestiSeka(n, seka);
    cout << "--------------" << endl;

    cout << "Papildomos uzduotys: " << endl;
    cout << "--------------" << endl;
    sekosDazniuLentele(n, seka);
    cout << "--------------" << endl;
    int iN, sN[100];
    cout << "Sekos kuria ivesti ilgis: " << endl;
    cin >> iN;
    cout << "Sekos skaiciai: " << endl;
    for (int i = 0; i < iN; i++) {
        cin >> sN[i];
    }
    cout << "--------------" << endl;
    iterptiSkaicius(n, seka, iN, sN);
    cout << "Skaiciu seka" << endl;
    cout << "--------------" << endl;
    isvestiSeka(n, seka);
    cout << "--------------" << endl;
    return 0;
}
