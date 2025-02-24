#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Zmogus {
    string gyventojas;
    int amzius;
    int atlyginimas;
    int kreditoBalas;
};

void nuskaitymas(int& n, Zmogus* z) {
    ifstream fIn("Zmones.csv");
    fIn.ignore(256, '\n');

    string line;
    while (getline(fIn, line)) {

        stringstream ss(line);
        string gyventojas;
        int amzius, atlyginimas, kreditoBalas;

        getline(ss, gyventojas, ',');
        ss >> amzius;
        ss.ignore(1);
        ss >> atlyginimas;
        ss.ignore(1);
        ss >> kreditoBalas;

        z[n].gyventojas = gyventojas;
        z[n].amzius = amzius;
        z[n].atlyginimas = atlyginimas;
        z[n].kreditoBalas = kreditoBalas;
        n++;
    }

}

void sprendimas(int n, Zmogus* z) {
    ofstream fOut("Sprendimas.csv");
    fOut << "Asmens vardas,Sprendimas" << endl;

    for (int i = 0; i < n; i++) {
        fOut << z[i].gyventojas << ",";

        if (z[i].amzius < 18) {
            fOut << "Per mažas amžius." << endl;
        } else if (z[i].amzius > 65) {
            fOut << "Per didelis amžius." << endl;
        } else if (z[i].atlyginimas < 1000) {
            fOut << "Netinkamos pajamos." << endl;
        } else if (z[i].kreditoBalas < 600) {
            fOut << "Žemas kredito balas." << endl;
        } else {
            fOut << "Paskola gali būti suteikta." << endl;
        }
    }
}

int main() {
    Zmogus z[200];
    int n;

    nuskaitymas(n,z);
    sprendimas(n, z);

    return 0;
}