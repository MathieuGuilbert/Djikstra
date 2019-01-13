# ifndef __GRAPHE_HPP
# define __GRAPHE_HPP

#include <iostream>
#include <utility>
#include <vector>
# include <assert.h>
# include "sommet.hpp"
using namespace std ;

template<class U,class T>
class Graphe;

template<class U,class T>
std::ostream& operator<<(std::ostream&, const Graphe<U,T>&);

template<class U,class T> class Graphe {

private:                                  //poids, sommet
	vector< pair <Sommet<T> , vector< pair<U,Sommet<T> > > > > liste;


public:
	Graphe(){
        this->liste= vector< pair <Sommet<T>, vector< pair<U,Sommet<T> > > > >();
    }

    int getSize() const;
    vector< pair <Sommet<T> , vector< pair<U,Sommet<T> > > > > getListe() const;

	void add_sommet(Sommet<T> i,vector< pair<U,Sommet<T> > > voisins);
	void add_arrete(Sommet<T> source, pair<U,Sommet<T> > arrete);

	void suppr_sommet(Sommet<T> sommet);
	void suppr_arrete(Sommet<T> source, pair<U, Sommet<T> > arrete);

	friend std::ostream & operator<<  <>( std::ostream& ost , Graphe<U, T> const & g );

	~Graphe();
};

#include "graphe.tpp"

#endif
