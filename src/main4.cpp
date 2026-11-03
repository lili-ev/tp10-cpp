
#include <iostream>
#include <string>

using namespace std;

// Classe Contact
class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    string getNom() {
        return nom;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};

// Ajouter un contact
void ajouterContact(Contact** carnet, int& nombre) {

    string nom, telephone, email;

    cout << "Donner le nom : ";
    getline(cin >> ws, nom);

    cout << "Donner le telephone : ";
    getline(cin, telephone);

    cout << "Donner l'email : ";
    getline(cin, email);

    carnet[nombre] = new Contact(nom, telephone, email);

    nombre++;

    cout << "Contact ajoute avec succes !" << endl;
}

// Afficher les contacts
void afficherContacts(Contact** carnet, int nombre) {

    if (nombre == 0) {
        cout << "Le carnet est vide." << endl;
        return;
    }

    for (int i = 0; i < nombre; i++) {
        cout << "\nContact " << i + 1 << endl;
        carnet[i]->afficher();
    }
}

// Supprimer un contact
void supprimerContact(Contact** carnet, int& nombre, string nom) {

    bool trouve = false;

    for (int i = 0; i < nombre; i++) {

        if (carnet[i]->getNom() == nom) {

            delete carnet[i];

            for (int j = i; j < nombre - 1; j++) {
                carnet[j] = carnet[j + 1];
            }

            nombre--;

            trouve = true;

            cout << "Contact supprime avec succes !" << endl;

            break;
        }
    }

    if (!trouve) {
        cout << "Contact introuvable !" << endl;
    }
}

// Programme principal
int main() {

    const int capacite = 100;

    // Tableau dynamique de pointeurs
    Contact** carnet = new Contact*[capacite];

    int nombre = 0;
    int choix;
    string nom;

    do {
        cout << "\n===== CARNET D'ADRESSES =====" << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "4. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {

        case 1:
            if (nombre < capacite) {
                ajouterContact(carnet, nombre);
            } else {
                cout << "Carnet plein !" << endl;
            }
            break;

        case 2:
            afficherContacts(carnet, nombre);
            break;

        case 3:
            cout << "Donner le nom du contact a supprimer : ";
            getline(cin >> ws, nom);

            supprimerContact(carnet, nombre, nom);
            break;

        case 4:
            cout << "Au revoir !" << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 4);

    // Liberer les contacts restants
    for (int i = 0; i < nombre; i++) {
        delete carnet[i];
    }

    // Liberer le tableau de pointeurs
    delete[] carnet;

    return 0;
}
