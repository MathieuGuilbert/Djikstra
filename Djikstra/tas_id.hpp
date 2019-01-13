# ifndef __TASID_HPP
# define __TASID_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <map>

# include "couple.hpp"

using namespace std ;

template<class W, class V> class Tas_id {

private:
   vector< Couple<W,V> > tab; //tableau des données contenues dans le tas
   map<V, int> quick;   //les sommet seront ainsi associés à leur position dans le vector

public:
    Tas_id(){
        this->tab=vector< Couple<W,V> >();
        quick=map<V, int>();
    }
    Tas_id(V s){
        this->tab=vector<Couple<W,V> >();
        //quick=map<int, V>();  Besoin de declarer ?
        this->tab.push_back(Couple<W,V>(NULL, s));
        quick.insert(pair<V, int>(s,0));
    }
    Tas_id(Couple<W,V> c){
        this->tab=vector<Couple<W,V> >();
        //quick=map<int, V>();  Besoin de declarer ?
        this->tab.push_back(c);
        quick.insert(pair<V, int>(c.getSom() ,0));
    }

    vector< Couple<W,V> > getTab() const;
    map<V, int> getQuick() const;
    bool estVide();


    Couple<W,V> extraireMin();
    void add(Couple<W,V> s);
    int recherche(V s);

    bool maj(V s, W newDist);

    ~Tas_id();
};
#include "tas_id.tpp"


#endif

