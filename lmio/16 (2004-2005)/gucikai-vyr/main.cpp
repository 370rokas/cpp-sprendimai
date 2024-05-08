#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int rankos, kojos, akys;
    int gR, gK, gA;
    int mR, mK, mA;
    int fR, fK, fA;

    int maxRusies = 500;

    ifstream failasIn("in.txt");
    ofstream failasOut("out.txt");

    failasIn >> rankos >> kojos >> akys;
    failasIn >> gR >> gK >> gA;
    failasIn >> mR >> mK >> mA;
    failasIn >> fR >> fK >> fA;

    failasIn.close();

    for (int iG = 1; iG <= maxRusies; iG++) {
        for (int iM = 1; iM <= maxRusies; iM++) {
            for (int iF = 1; iF <= maxRusies; iF++) {
                if (   iG * gR + iM * mR + iF * fR == rankos
                    && iG * gK + iM * mK + iF * fK == kojos
                    && iG * gA + iM * mA + iF * fA == akys) {

                    cout << iG << " " << iM << " " << iF << endl;
                    failasOut << iG << " " << iM << " " << iF;

                    break;
                }
            }
        }
    }

    failasOut.close();
    return 0;
}
