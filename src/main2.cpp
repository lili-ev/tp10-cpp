
#include <iostream>
#include <string>

using namespace std;

// Classe Personne
class Personne {
private:
    string nom;
    int age;

public:
    // Constructeur
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    // Methode afficher
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << " ans" << endl;
    }
};

// Programme principal
int main() {

    // Allocation dynamique de l'objet
    Personne* p = new Personne("Ahmed", 25);

    // Affichage
    p->afficher();

    // Liberation de la memoire
    delete p;

    return 0;
}
