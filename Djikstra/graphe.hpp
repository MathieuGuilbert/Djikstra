
# ifndef __GRAPHE_HPP
# define __GRAPHE_HPP

#include <iostream>
#include <utility>
#include <vector>
# include <assert.h>
# include "sommet.hpp"


using namespace std ;

template<class T> class Graphe {

private:                                  //poids, sommet
	vector< pair <Sommet<T> , vector< pair<int,Sommet<T> > > > > liste;


public:
	Graphe();

	void add_sommet(Sommet<T>,vector< pair<int,Sommet<T> > > voisins);
	void add_arrete(Sommet<T> source, pair<int,Sommet<T> > arrete);

	void suppr_sommet(Sommet<T> sommet);
	void suppr_arrete(Sommet<T> source, pair<int, Sommet<T> > arrete);


	//friend std::ostream & operator << ( std::ostream& ost , Graphe const & g );


	~Graphe();
};

#include "graphe.tpp"

#endif

