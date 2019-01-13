# undef NDEBUG

using namespace std ;

//constr dans .hpp

template<class T>
int Sommet<T>::getNum() const{
    return num;
}

template<class T>
T Sommet<T>::getId() const{
    return id;
}

template<class T>
bool Sommet<T> :: operator == ( Sommet<T> const & v ) const {
	if(this->num == v.getNum() && this->id==v.getId() ){
		return true;
	}
  	return false ;
}

template<class T>
bool Sommet<T> :: operator != ( Sommet<T> const & v ) const {
	return (this->getId() != v.getId());
}

template<class T>
std :: ostream & operator << (std :: ostream & ost , Sommet<T> const & s) {
    ost << "( Numero : " << s.getNum() << " , ";
	ost <<" Id : " << s.getId() << " )";
	return ost;
}

template<class T>
bool Sommet<T> :: operator < ( Sommet<T> const & s ) const {
	return (this->getId() < s.getId());
}

template<class T>
bool Sommet<T> :: operator > ( Sommet<T> const & s ) const {
	return (this->getId() > s.getId());
}

template<class T>
bool Sommet<T> :: operator <= ( Sommet<T> const & s ) const {
	return (this->getId() <= s.getId());
}

template<class T>
bool Sommet<T> :: operator >= ( Sommet<T> const & s ) const {
	return (this->getId() >= s.getId());
}

template<class T>
Sommet<T>::~Sommet(){

}

