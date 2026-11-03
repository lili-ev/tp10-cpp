
#include <iostream>
#include <string>

using namespace std;

// Classe Livre
class Livre {
private:
    string titre;
    double prix;

public:
    // Constructeur par defaut
    Livre() {
        titre = "";
        prix = 0;
    }

    // Methode pour saisir les informations
    void saisir() {
        cout << "Donner le titre du livre : ";
        getline(cin, titre);

        cout << "Donner le prix du livre : ";
        cin >> prix;

        cin.ignore();
    }

    // Methode pour afficher les informations
    void afficher() {
        cout << "Titre : " << titre << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }
};

// Programme principal
int main() {

    int n;

    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;

    if (n <= 0) {
        cout << "Nombre invalide !" << endl;
        return 0;
    }

    // Allocation dynamique du tableau
    Livre* livres = new Livre[n];

    // Saisie des livres
    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << endl;
        cin.ignore();
        livres[i].saisir();
    }

    // Affichage des livres
    cout << "\n===== LISTE DES LIVRES =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << endl;
        livres[i].afficher();
    }

    // Liberation de la memoire
    delete[] livres;

    return 0;
}
