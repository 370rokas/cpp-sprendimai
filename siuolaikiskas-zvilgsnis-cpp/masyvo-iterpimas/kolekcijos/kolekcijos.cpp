#include <iostream>
#include <fstream>

using namespace std;

void rikiuoti(int n, int* mas) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas[i] > mas[j]) {
                int temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
            }
        }
    }
}

void iterptiSkaiciu(int& n, int* seka, int sk) {
    seka[n] = sk;
    n++;
    rikiuoti(n, seka);
}

void naikintiIndeksa(int& n, int* seka, int skI) {
    for (int i = skI; i < n; i++) {
        seka[i] = seka[i + 1];
    }
    n--;
}

void dovanoti(int& nIs, int* mIs, int& nI, int* mI, int k) {
    for (int i = 0; i < nIs; i++) {
        if (mIs[i] / k > 0) {
            iterptiSkaiciu(nI, mI, mIs[i]);
            naikintiIndeksa(nIs, mIs, i);
            i--;
        }
    }
}

void nuskaityti(char* failas, int& n, int* seka) {
    ifstream fIn(failas);

    fIn>>n;
    for (int i = 0; i < n; i++) {
        fIn >> seka[i];
    }

    fIn.close();
}

void isvestiMasyva(int n, int* m) {
    for (int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n1, m1[100], n2, m2[100];
    nuskaityti("in1.txt", n1, m1);
    nuskaityti("in2.txt", n2, m2);

    dovanoti(n2, m2, n1, m1, 10);
    dovanoti(n1, m1, n2, m2, 100);

    cout << "Rasos kolekcija: " << endl;
    isvestiMasyva(n1, m1);
    cout << "Rimo kolekcija: " << endl;
    isvestiMasyva(n2, m2);

    return 0;
}
