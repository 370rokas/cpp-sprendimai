#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int rastiBendra(int* S1, int* S2, int* S3) {
    int X1 = max({S1[0], S2[0], S3[0]});
    int Y1 = max({S1[1], S2[1], S3[1]});

    int X2 = min({S1[2], S2[2], S3[2]});
    int Y2 = min({S1[3], S2[3], S3[3]});

    return abs(X1 - X2) * abs(Y1 - Y2);
}

int main()
{
    ifstream fIn("in.txt");

    int S1[4];
    int S2[4];
    int S3[4];

    fIn >> S1[0] >> S1[1] >> S1[2] >> S1[3];
    fIn >> S2[0] >> S2[1] >> S2[2] >> S2[3];
    fIn >> S3[0] >> S3[1] >> S3[2] >> S3[3];

    fIn.close();

    int nMedziu = rastiBendra(S1, S2, S3);
    cout << nMedziu << endl;

    ofstream fOut("out.txt");
    fOut << nMedziu;
    fOut.close();

    return 0;
}
