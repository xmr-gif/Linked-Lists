#include "Liste.h"
#include <iostream>

using namespace std;

int main()
{
    Liste A ;
    A.afficher() ;
    A.ins_debut_liste("Hello");
    A.ins_debut_liste("World") ;
    A.afficher() ;
    A.supp_debut();
    A.afficher() ;
    Liste B(A) ; // appel de constructeur de recopie 
    
    Liste C  ; // appel de constructeur par défaut 
    
    C = A ; // appel d'op d'affectaion 

    return 0;
}
