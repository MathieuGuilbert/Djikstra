# ifndef __TAS_HPP
# define __TAS_HPP

#include <iostream>
#include <utility>
#include <vector>

using namespace std ;

template<class V> class Tas {

private:
   vector< V > tab; //tableau des données contenues dans le tas

public:
    Tas(){
        this->tab=vector< V >();
    }
    Tas(V s){
        this->tab=vector< V >();
        this->tab.push_back(s);
    }

    V extraireMin();
    void add(V s);
    bool recherche(V s,int index); //int pour donner la pos dans le vector

    ~Tas();
};
#include "tas.tpp"


#endif
