# ifndef __COUPLE_HPP
# define __COUPLE_HPP

#include <iostream>
#include <utility>
#include <vector>

using namespace std ;

//Cette classe a pour but d'associer un élement T à une distance (utile dans l'utilisation du tas_id )

/*template<class U,class T>
class Couple;

template<class U,class T>
std::ostream& operator<<(std::ostream&, const Graphe<U,T>&);*/

template<class U,class T> class Couple {

private:
	U dist;
	T som;

public:
    /*Couple(){
        dist=NULL;
        som=NULL;
    }*/
    Couple(U d, T s){
        dist=d;
        som=s;
    }

    U getDist() const;
    T getSom() const;

    void setDist(U newDist);

    bool operator == (Couple<U,T> const & s ) const;
    bool operator < (Couple<U,T> const & s ) const;
    bool operator > (Couple<U,T> const & s ) const;
    bool operator <= (Couple<U,T> const & s ) const;
    bool operator >= (Couple<U,T> const & s ) const;

    ~Couple();

};

#include "couple.tpp"

#endif
