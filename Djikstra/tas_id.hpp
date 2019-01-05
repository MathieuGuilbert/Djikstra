# ifndef __TASID_HPP
# define __TASID_HPP

#include <iostream>
#include <utility>
#include <vector>

using namespace std ;

template<class V> class Tas_id {

private:
   vector< pair<int,V> > tab; //tableau des données contenues dans le tas

public:
    Tas_id(){
        this->tab=vector< pair<int,V> >();
    }
    Tas_id(V s){
        this->tab=vector< pair<int,V> >();
        pair<int,V> p;
        p.first=0;
        p.second=s;
        this->tab.push_back(p);
    }

    pair<int,V> extraireMin();
    void add(V s);
    bool recherche(V s,int index); //int pour donner la pos dans le vector

    ~Tas_id();
};
#include "tas_id.tpp"


#endif

