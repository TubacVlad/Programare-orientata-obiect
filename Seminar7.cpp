
#include <iostream>
#include <string.h>
using namespace std;

class Masina {
private:
    string marca;
    char* model;
    string nr_inmatriculare;
    static int total_masini;
public:
    Masina(string marca, char* model, string nr) :marca(marca), nr_inmatriculare(nr) {
        this->model = new char(strlen(model) + 1);
        strcpy_s(this->model, strlen(model) + 1, model);
        increment();
        //this->setModel(model)
    }

    void setMarca(string m) {
        this->marca = m;
    }

    void setModel(char* model) {
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);
    }

    void setInmatriculare(string nr) {
        this->nr_inmatriculare = nr;
    }

    string getMarca() {
        return this->marca;
    }

    char* getModel() {
        char* copy = new char[strlen(this->model) + 1];
        strcpy_s(copy, strlen(this->model) + 1, this->model);
        return copy;
        //return this->model;
    }

    string getNr() {
        return this->nr_inmatriculare;
    }

    static void increment() {
        Masina::total_masini++;
    }

    int getNrtotal() {
        return this->total_masini;
    }
    ~Masina(){}

};
int Masina::total_masini = 0;

int main()
{
    Masina m("dacia", (char*)"spring","b123a");
    m.increment;
    Masina m1("dacia", (char*)"galben","b72b");
    cout << m.getNrtotal();
}


