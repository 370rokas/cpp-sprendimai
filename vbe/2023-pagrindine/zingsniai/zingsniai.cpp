#include <iomanip>
#include <fstream>

using namespace std;

struct dalyviuDuomenys {
    int kategorija;
    int ilgis;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
};

struct kategorijosDuomenys {
    int kategorija = 0;
    int dalyviuSkaicius = 0;
    double atstumas = 0;
};

void nuskaityti(dalyviuDuomenys* dalyviai, int& nDalyviu) {
    ifstream fIn("U1.txt");

    fIn >> nDalyviu;

    for (int i = 0; i < nDalyviu; i++) {
        fIn >> dalyviai[i].kategorija >> dalyviai[i].ilgis >>
            dalyviai[i].d1 >> dalyviai[i].d2 >> dalyviai[i].d3 >> dalyviai[i].d4 >> dalyviai[i].d5 >> dalyviai[i].d6 >> dalyviai[i].d7;
    }

    fIn.close();
}

void apdorotiDuomenis(dalyviuDuomenys* dalyviai, int nDalyviu, kategorijosDuomenys* kategorijuAtstumai, int& nKategoriju) {
    nKategoriju = 0;

    for (int i = 0; i < nDalyviu; i++) {
        // Jeigu bent viena diena neivede zingsniu, praleidziam
        if (dalyviai[i].d1 == 0 || dalyviai[i].d2 == 0 || dalyviai[i].d3 == 0 || dalyviai[i].d4 == 0 ||
            dalyviai[i].d5 == 0 || dalyviai[i].d6 == 0 || dalyviai[i].d7 == 0) { continue; }

        // Skaicius kiek zingsniu nuejo per savaite
        int zingsniai = dalyviai[i].d1 + dalyviai[i].d2 + dalyviai[i].d3 + dalyviai[i].d4 + dalyviai[i].d5 + dalyviai[i].d6 + dalyviai[i].d7;

        // Pridedam prie kategoriju atstumu duomenu
        bool kategorijaRasta = false;

        // Ziurim ar netycia nera priestai sukurtos jau tokios kategorijos
        for (int j = 0; j < nKategoriju; j++) {
            if (kategorijuAtstumai[j].kategorija == dalyviai[i].kategorija) {
                kategorijuAtstumai[j].dalyviuSkaicius++;
                kategorijuAtstumai[j].atstumas += (double) zingsniai * dalyviai[i].ilgis / 1000;
                kategorijaRasta = true;
                break;
            }
        }

        // Tokios kategorijos dar nebuvo, sukuriam
        if (!kategorijaRasta) {
            kategorijuAtstumai[nKategoriju].kategorija = dalyviai[i].kategorija;
            kategorijuAtstumai[nKategoriju].dalyviuSkaicius = 1;
            kategorijuAtstumai[nKategoriju].atstumas = (double) zingsniai * dalyviai[i].ilgis / 1000;
            nKategoriju++;
        }
    }
}

void isvestis(kategorijosDuomenys* kategorijos, int nKategoriju) {
    ofstream fOut("U1rez.txt");

    for (int i = 0; i < nKategoriju; i++) {
        fOut << kategorijos[i].kategorija << " " << kategorijos[i].dalyviuSkaicius << " " << fixed << setprecision(2) << kategorijos[i].atstumas / 100 << endl;
    }

    fOut.close();
}

int main()
{
    dalyviuDuomenys dalyviai[50];
    kategorijosDuomenys kategorijos[12];
    int nDalyviu, nKategoriju;

    nuskaityti(dalyviai, nDalyviu);
    apdorotiDuomenis(dalyviai, nDalyviu, kategorijos, nKategoriju);
    isvestis(kategorijos, nKategoriju);

    return 0;
}
