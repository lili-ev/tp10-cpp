
#include <iostream>

using namespace std;

int main() {

    int taille;

    // Demander la taille du tableau
    cout << "Donner la taille du tableau : ";
    cin >> taille;

    // Vérifier la taille
    if (taille <= 0) {
        cout << "Taille invalide !" << endl;
        return 0;
    }

    // Allocation dynamique
    int* tableau = new int[taille];

    // Saisie des valeurs
    for (int i = 0; i < taille; i++) {
        cout << "Donner la valeur " << i + 1 << " : ";
        cin >> tableau[i];
    }

    // Affichage des valeurs
    cout << "\nLes valeurs du tableau sont :" << endl;

    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }

    cout << endl;

    // Libération de la mémoire
    delete[] tableau;

    return 0;
}
