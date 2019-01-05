#include <iostream>
# include "graphe.hpp"
# include "sommet.hpp"
# include "tas.hpp"
# include "tas_id.hpp"


using namespace std;

int main()
{
    Graphe<char,int> g; //ça devrait marcher

    //Sommet<float> s(2,5.0);  TODO pourquoi float et string marche pas ?
    Sommet<int> s(1,6);
    Sommet<int> s1(1,3);

	cout<<"Affichage des sommets : "<<endl;
    cout<<s<<endl;
    cout<<s1<<endl;

	pair<char,Sommet<int> > p;
	p.first='e'; p.second=s1;
    vector< pair<char,Sommet<int> > > v;
    v.push_back(p);
    g.add_sommet(s, v);

	cout<<"Affichage de G : "<<endl;
    cout<<g<<endl;

    //test tas
    Tas<char> t('a');
    t.add('c');
    t.add('b');
    //t.add(1);

    if(t.recherche('c',0)){
        cout<<"Prem "<<t.extraireMin()<<endl;
    }
    cout<<"deux "<<t.extraireMin()<<endl;


}
