# ifndef __TASID_HPP
# define __TASID_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <map>

using namespace std ;

template<class V> class Tas_id {

private:
   vector< V > tab; //tableau des données contenues dans le tas
   map<V, int> quick;   //les sommet seront ainsi associés à leur position dans le vector

public:
    Tas_id(){
        this->tab=vector<V>();
        quick=map<V, int>();
    }
    Tas_id(V s){
        this->tab=vector<V>();
        //quick=map<int, V>();  Besoin de declarer ?
        this->tab.push_back(s);
        quick.insert(pair<V, int>(s,0));
    }

    vector< V > getTab() const;
    map<V, int> getQuick() const;
    bool estVide();


    V extraireMin();
    void add(V s);
    bool recherche(V s);

    ~Tas_id();
};
#include "tas_id.tpp"


#endif

