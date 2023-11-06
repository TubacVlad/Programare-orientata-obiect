#include <iostream>
#include <cstring>

using namespace std;

class Produs {
private:
    int id;
    char* nume;
    char* descriere;
    double pret;
    double istoricPret[100];

public:
    Produs(int id, const char* nume, const char* descriere, double pret, const double* istoricPret) {
        this->id = id;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->descriere = new char[strlen(descriere) + 1];
        strcpy(this->descriere, descriere);
        this->pret = pret;
        for (int i = 0; i < 100; i++) {
            this->istoricPret[i] = 0.0;
        }
        for (int i = 0; istoricPret[i] > 0; i++) {
            this->istoricPret[i] = istoricPret[i];
        }
    }

    Produs(const Produs& other) {
        this->id = other.id;
        this->nume = new char[strlen(other.nume) + 1];
        strcpy(this->nume, other.nume);
        this->descriere = new char[strlen(other.descriere) + 1];
        strcpy(this->descriere, other.descriere);
        this->pret = other.pret;
        for (int i = 0; other.istoricPret[i] > 0; i++) {
            this->istoricPret[i] = other.istoricPret[i];
        }
    }

    ~Produs() {
        delete[] nume;
        delete[] descriere;
    }

    void setPret(double newPrice) {
        pret = newPrice;
        for (int i = 0; i < 100; i++) {
            if (istoricPret[i] == 0) {
                istoricPret[i] = newPrice;
                break;
            }
        }
    }

    double getPret() const {
        return pret;
    }

    char* getNume() const {
        return nume;
    }

    double calculeazaPretMediu() const {
        if (istoricPret[0] == 0) {
            return pret;
        }

        double suma = 0.0;
        int count = 0;

        for (int i = 0; istoricPret[i] > 0; i++) {
            suma += istoricPret[i];
            count++;
        }

        return suma / count;
    }
};

int main() {
    int id;
    char name[100];
    char description[100];
    double price;
    double priceHistory[100] = {};

    cout << "Introduceti ID-ul produsului: ";
    cin >> id;

    cout << "Introduceti numele produsului: ";
    cin.ignore();
    cin.getline(name, 100);

    cout << "Introduceti descrierea produsului: ";
    cin.getline(description, 100);

    cout << "Introduceti pretul produsului: ";
    cin >> price;

    int i = 0;
    double newPrice;
    do {
        cout << "Introduceti istoricul de preturi (0 pentru a opri): ";
        cin >> newPrice;
        if (newPrice > 0) {
            priceHistory[i++] = newPrice;
        }
    } while (newPrice > 0);

    Produs produs1(id, name, description, price, priceHistory);

    cout << "Nume Produs: " << produs1.getNume() << endl;
    cout << "Pret Produs: " << produs1.getPret() << endl;
    cout << "Pret Mediu: " << produs1.calculeazaPretMediu() << endl;

    Produs produs2 = produs1;
    cout << "Nume Produs 2: " << produs2.getNume() << endl;
    cout << "Pret Produs 2: " << produs2.getPret() << endl;

    return 0;
}
