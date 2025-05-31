#ifndef Liste_hpp
#define Liste_hpp

#include <stdio.h>

struct Element{
    char * donnee ;
    Element *suivant ;
};

class Liste{
    public :
    Liste() ;
    Liste(const Liste &) ;
    virtual ~Liste();
    Liste &operator=(const Liste &) ;
    void afficher() const ;
    
    Liste &ins_debut_liste(const char *d) ;
    Liste &ins_fin_liste(const char *d) ;
    Liste &ins_liste(const char *d, const int &pos) ;
    
    Liste &supp_debut() ;
    Liste &supp_ailleur(const int& pos) ;
    
    private :
    Element *L ;
};

#endif /* Liste_hpp */
