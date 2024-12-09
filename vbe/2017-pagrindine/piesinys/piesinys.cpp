#include <fstream>
#include <iostream>

using namespace std;

struct staciakampis {
    int x;
    int y;
    int dx;
    int dy;
    int R;
    int G;
    int B;
};

struct langelis {
    int R;
    int G;
    int B;
};

void nuskaitymas(int &n, staciakampis* s) {
    ifstream fIn("U2.txt");

    fIn >> n;

    for (int i = 0; i < n; i++) {
        fIn >> s[i].x >> s[i].y >> s[i].dx >> s[i].dy >> s[i].R >> s[i].G >> s[i].B;
    }

    fIn.close();
}

void uzpildytiBaltai(langelis p[100][100]) {
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            p[x][y].R = 255;
            p[x][y].G = 255;
            p[x][y].B = 255;
        }
    }
}

void nupiestiStaciakampi(langelis p[100][100], staciakampis s) {
    for (int i = s.x; i < s.x + s.dx; i++) {
        for (int j = s.y; j < s.y + s.dy; j++) {
            p[i][j].R = s.R;
            p[i][j].G = s.G;
            p[i][j].B = s.B;
        }
    }
}

void rastiPiesinioRibas(langelis p[100][100], int& xMax, int& yMax) {
    xMax = 0;
    yMax = 0;

    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (p[x][y].R != 255 || p[x][y].G != 255 || p[x][y].B != 255) {
                if (x > xMax) {
                    xMax = x;
                }

                if (y > yMax) {
                    yMax = y;
                }
            }
        }
    }
}

void rezultatai(int xMax, int yMax, langelis p[100][100]) {
    ofstream fOut("U2rez.txt");

    fOut << yMax + 1 << " " << xMax + 1 << endl;

    for (int y = 0; y <= yMax; y++) {
        for (int x = 0; x <= xMax; x++) {
            fOut << p[x][y].R << " " << p[x][y].G << " " << p[x][y].B << endl;
        }
    }

    fOut.close();
}

int main() {
    int n;
    staciakampis s[100];
    langelis piesinys[100][100];

    nuskaitymas(n, s);
    uzpildytiBaltai(piesinys);

    // Nupiesti visus staciakampius piesinyje
    for (int i = 0; i < n; i++) {
        nupiestiStaciakampi(piesinys, s[i]);
    }

    // Surasti piesinio ribas
    int maxX, maxY;
    rastiPiesinioRibas(piesinys, maxX, maxY);

    rezultatai(maxX, maxY, piesinys);

    return 0;
}