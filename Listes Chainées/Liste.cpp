#include "Liste.hpp"
#include <iostream>

#include <cstring> // Pour strlen et strcpy
using namespace std;


Liste::Liste(){
    L = NULL ;
    cout << "Constructeur" << endl;
}


Liste::Liste(const Liste& obj){
    L = NULL ;
    if(obj.L != NULL) {
        this->ins_debut_liste(obj.L->donnee);
        for(Element* courant = obj.L->suivant; courant != NULL; courant = courant->suivant) {
            this->ins_fin_liste(courant->donnee);
        }
    }
    cout << "Constructeur de recopie" << endl;
}

Liste::~Liste() {
    while(L != NULL) {
        this->supp_debut();
    }
    cout << "Destructeur" << endl;
}


Liste& Liste::operator=(const Liste& obj) {
    if(&obj != this) { // Protection contre l'auto-affectation
        // Vidage de la liste actuelle
        while(L != NULL) {
            this->supp_debut();
        }
        
        // Copie des éléments
        if(obj.L != NULL) {
            this->ins_debut_liste(obj.L->donnee);
            for(Element* courant = obj.L->suivant; courant != NULL; courant = courant->suivant) {
                this->ins_fin_liste(courant->donnee);
            }
        }
    }
    cout << "Operateur =" << endl;
    return *this;
}

// Insertion en début de liste
Liste& Liste::ins_debut_liste(const char* d) {
    Element* nouveau_element = new Element;
    if(nouveau_element == NULL) return *this;
    
    nouveau_element->donnee = new char[strlen(d) + 1];
    if(nouveau_element->donnee == NULL) {
        delete nouveau_element;
        return *this;
    }
    
    strcpy(nouveau_element->donnee, d);
    nouveau_element->suivant = L;
    L = nouveau_element;
    return *this;
}


Liste& Liste::ins_fin_liste(const char* d) {
    Element* nouveau_element = new Element;
    if(nouveau_element == NULL) return *this;
    
    nouveau_element->donnee = new char[strlen(d) + 1];
    if(nouveau_element->donnee == NULL) {
        delete nouveau_element;
        return *this;
    }
    strcpy(nouveau_element->donnee, d);
    nouveau_element->suivant = NULL;
    
    if(L == NULL) { // Liste vide
        L = nouveau_element;
    } else {
        Element* dernier_element = L;
        while(dernier_element->suivant != NULL) {
            dernier_element = dernier_element->suivant;
        }
        dernier_element->suivant = nouveau_element;
    }
    return *this;
}

// Insertion à une position spécifique (par défaut en fin)
Liste& Liste::ins_liste(const char* d, const int &pos) {
    if(pos <= 1) return ins_debut_liste(d);
    
    Element* nouveau_element = new Element;
    if(nouveau_element == NULL) return *this;
    
    nouveau_element->donnee = new char[strlen(d) + 1];
    if(nouveau_element->donnee == NULL) {
        delete nouveau_element;
        return *this;
    }
    strcpy(nouveau_element->donnee, d);
    
    Element* courant = L;
    for(int i = 1; i < pos-1 && courant != NULL; i++) {
        courant = courant->suivant;
    }
    
    if(courant == NULL) { // Position trop grande, on insère en fin
        return ins_fin_liste(d);
    }
    
    nouveau_element->suivant = courant->suivant;
    courant->suivant = nouveau_element;
    return *this;
}

// Suppression du premier élément
Liste& Liste::supp_debut() {
    if(L == NULL) return *this;
    
    Element* supp_element = L;
    L = L->suivant;
    delete[] supp_element->donnee;
    delete supp_element;
    return *this;
}

// Suppression à une position spécifique
Liste& Liste::supp_ailleur(const int & pos) {
    if(L == NULL || pos < 1) return *this;
    if(pos == 1) return supp_debut();
    
    Element* courant = L;
    for(int i = 1; i < pos-1 && courant->suivant != NULL; i++) {
        courant = courant->suivant;
    }
    
    if(courant->suivant == NULL) {
        cout << "Position invalide" << endl;
        return *this;
    }
    
    Element* supp_element = courant->suivant;
    courant->suivant = supp_element->suivant;
    delete[] supp_element->donnee;
    delete supp_element;
    cout << "Suppression effectuée" << endl;
    return *this;
}

// Affichage de la liste
void Liste::afficher() const {
    Element* courant = L;
    cout << "Liste content:" << endl;
    while(courant != NULL) {
        cout << courant->donnee << endl;
        courant = courant->suivant;
    }
}
