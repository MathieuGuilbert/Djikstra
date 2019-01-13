# include <iostream>
#include <string>
#include <fstream>

# undef NDEBUG

using namespace std ;

template<class U,class T>
U Couple<U,T>::getDist() const{
    return this->dist;
}

template<class U,class T>
T Couple<U,T>::getSom() const{
    return this->som;
}

template<class U,class T>
void Couple<U,T>::setDist(U newDist){
    dist=newDist;
}


template<class U,class T>
bool Couple<U,T> :: operator == ( Couple<U,T> const & c ) const {
	return (this->getDist() == c.getDist() );
}

template<class U,class T>
bool Couple<U,T> :: operator < ( Couple<U,T> const & c ) const {
	return (this->getDist() < c.getDist() );
}

template<class U,class T>
bool Couple<U,T> :: operator > ( Couple<U,T> const & c ) const {
	return (this->getDist() > c.getDist() );
}

template<class U,class T>
bool Couple<U,T> :: operator <= ( Couple<U,T> const & c ) const {
	return (this->getDist() <= c.getDist() );
}

template<class U,class T>
bool Couple<U,T> :: operator >= ( Couple<U,T> const & c ) const {
	return (this->getDist() >= c.getDist() );
}




template<class U,class T>
Couple<U,T>::~Couple(){

}
