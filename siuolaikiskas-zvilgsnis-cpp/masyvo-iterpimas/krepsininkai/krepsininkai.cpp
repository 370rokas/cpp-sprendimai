#include <iostream>
#include <fstream>

using namespace std;

void nuskaitytiFaila(int& n, int* m, char* failas) {
    ifstream fIn(failas);

    fIn >> n;
    for (int i = 0; i < n; i++) {
        fIn >> m[i];
    }

    fIn.close();
}

void isvestiMasyva(int& n, int* m) {
    for (int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
    cout << endl;
}

void rikiuotiMasyva(int n, int* m) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i] > m[j]) {
                int t = m[i];
                m[i] = m[j];
                m[j] = t;
            }
        }
    }
}

void sujungtiMasyvus(int& n1, int* m1, int& n2, int* m2) {
    for (int i = 0; i < n2; i++) {
        m1[n1 + i] = m2[i];
    }
    n1 += n2;
    rikiuotiMasyva(n1, m1);
}

int main()
{
    int n1, m1[100], n2, m2[100];

    nuskaitytiFaila(n1, m1, "in1.txt");
    nuskaitytiFaila(n2, m2, "in2.txt");

    sujungtiMasyvus(n1, m1, n2, m2);

    isvestiMasyva(n1, m1);

    return 0;
}
