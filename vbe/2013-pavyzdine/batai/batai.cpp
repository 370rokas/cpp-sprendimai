#include <iostream>
#include <fstream>

using namespace std;

void nuskaityti(int& vKn, int* vK, int& vDn, int* vD, int& mKn, int* mK, int& mDn, int* mD) {
    vKn = 0;
    vDn = 0;
    mKn = 0;
    mDn = 0;

    ifstream fIn("u1.txt");

    int n, l, p;
    fIn >> n;

    for (int i = 0; i < n; i++) {
        fIn >> l >> p;

        if (l == 3) {
            if (p == 1) {
                fIn >> vK[vKn];
                vKn++;
            } else if (p == 2) {
                fIn >> vD[vDn];
                vDn++;
            }

        } else if (l == 4) {
            if (p == 1) {
                fIn >> mK[mKn];
                mKn++;
            } else if (p == 2) {
                fIn >> mD[mDn];
                mDn++;
            }
        }
    }

    fIn.close();
}

int rastiPoras(int Kn, int* K, int Dn, int* D) {
    int poros = 0;

    for (int i = 0; i < Kn; i++) {
        for (int j = 0; j < Dn; j++) {
            if (K[i] == D[j]) {
                poros++;
                D[j] = 0;
            }
        }
    }

    return poros;
}

int main()
{
    int vKn, vDn, mKn, mDn;
    int vK[100], vD[100], mK[100], mD[100];

    nuskaityti(vKn, vK, vDn, vD, mKn, mK, mDn, mD);
    int vyriskosPoros =     rastiPoras(vKn, vK, vDn, vD);
    int moteriskosPoros =   rastiPoras(mKn, mK, mDn, mD);

    cout << vyriskosPoros << "\n" << moteriskosPoros << endl;

    return 0;
}
