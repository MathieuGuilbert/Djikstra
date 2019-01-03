# ifndef __SOMMET_HPP
# define __SOMMET_HPP

#include <iostream>
#include <utility>
#include <vector>

using namespace std ;

template<class T> class Sommet {

private:
    int num;
    T id;

public:
    Sommet(){
        this->num=0;
        this->id=NULL;
    }
    Sommet(int num, T id){
        this->num=num;
        this->id=id;
    }

    int getNum() const;
    T getId() const;

     bool operator == ( Sommet const & v ) const ;

     template <T> friend std :: ostream & operator << (std :: ostream & ost , Sommet<T> const & s);

    ~Sommet();
};
#include "sommet.tpp"


#endif
