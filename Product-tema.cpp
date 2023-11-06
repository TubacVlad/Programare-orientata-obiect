#include <iostream>
#include <cstring>

using namespace std;

class Produs {
private:
    int id;
    char* nume;
    char* descriere;
    double pret;
    double istoricPreturi[100];

public:
    Produs(int id, const char* nume, const char* descriere, double pret, const double* istoricPreturi) {
        this->id = id;

        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        this->descriere = new char[strlen(descriere) + 1];
        strcpy(this->descriere, descriere);

        this->pret = pret;

        for (int i = 0; istoricPreturi[i] > 0; i++) {
            this->istoricPreturi[i] = istoricPreturi[i];
        }
    }

    Produs(const Produs& altProdus) {
        this->id = altProdus.id;

        this->nume = new char[strlen(altProdus.nume) + 1];
        strcpy(this->nume, altProdus.nume);

        this->descriere = new char[strlen(altProdus.descriere) + 1];
        strcpy(this->descriere, altProdus.descriere);

        this->pret = altProdus.pret;

        for (int i = 0; altProdus.istoricPreturi[i] > 0; i++) {
            this->istoricPreturi[i] = altProdus.istoricPreturi[i];
        }
    }

    ~Produs() {
        delete[] nume;
        delete[] descriere;
    }

    void setPret(double noulPret) {
        pret = noulPret;
        istoricPreturi[0] = noulPret;
    }

    double getPret() const {
        return pret;
    }

    const char* getNume() const { // Highlighted: Changed return type to const char*
        return nume;
    }

    double calculeazaPretMediu() const {
        double suma = pret;
        int count = 0;
        for (int i = 0; istoricPreturi[i] > 0; i++) {
            suma += istoricPreturi[i];
            count++;
        }
        if (count > 0) {
            return suma / count;
        }
        return suma;
    }
};

int main() {
    int id;
    char nume[100];
    char descriere[100];
    double pret;
    double istoricPreturi[100] = {};

    cout << "Introduceti ID-ul produsului: ";
    cin >> id;

    cin.ignore(); // Highlighted: Added this line to consume the newline character

    cout << "Introduceti numele produsului: ";
    cin.getline(nume, 100);

    cout << "Introduceti descrierea produsului: ";
    cin.getline(descriere, 100);

    cout << "Introduceti pretul produsului: ";
    cin >> pret;

    int i = 0;
    double noulPret;
    do {
        cout << "Introduceti istoricul preturilor (0 pentru a opri): ";
        cin >> noulPret;
        if (noulPret > 0) {
            istoricPreturi[i++] = noulPret;
        }
    } while (noulPret > 0);

    Produs produs1(id, nume, descriere, pret, istoricPreturi);

    cout << "Nume Produs: " << produs1.getNume() << endl;
    cout << "Pret Produs: " << produs1.getPret() << endl;
    cout << "Pret Mediu: " << produs1.calculeazaPretMediu() << endl;

    Produs produs2 = produs1;
    cout << "Nume Produs 2: " << produs2.getNume() << endl;
    cout << "Pret Produs 2: " << produs2.getPret() << endl;

    return 0;
}
