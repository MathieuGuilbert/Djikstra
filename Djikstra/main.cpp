#include <iostream>
# include "graphe.hpp"
# include "sommet.hpp"
# include "tas.hpp"
# include "tas_id.hpp"


using namespace std;


/*template<typename U,typename T>
void Djikstra(Graphe<U,T> const graphe, Sommet<T> start){  //vas retourner un tas id

    vector< pair <Sommet<T> , vector< pair<U,Sommet<T> > > > > g=graphe.getListe();
    Tas_id<Sommet<T> > aTraite(start);
    Tas_id<Sommet<T> > dejaTraite;
    vector<U> dist(graphe.getSize() );

    //Initialisation
    for(unsigned int i = 0 ; i < graphe.getSize() ; i++ ){
        if(g[i]==start){
            dist[i]==0;

        }

        dist[i]=NULL;

    }
    dist[start.getNum()]=0;



    while(!aTraite.estVide()){

    }

}*/



int main()
{
    Graphe<char,int> g; //ça devrait marcher

    //Sommet<float> s(2,5.0);  TODO pourquoi float et string marche pas ?
    Sommet<int> s(1,6);
    Sommet<int> s1(2,3);
    Sommet<int> s2(3,2);

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

    //test tas  int/douche ect
    /*Tas<double> t(3);
    t.add(5);
    t.add(4);
    t.add(1);*/

    Tas<Sommet<int> > t(s);
    t.add(s1);
    t.add(s2);

    if(t.recherche(s,0)){
        cout<<"Prem "<<t.extraireMin()<<endl;
    }
    cout<<"deux "<<t.extraireMin()<<endl;

    cout<< "\n Test Tas_id"<<endl;

    Tas_id< Sommet<int> > ti(s);
    ti.add(s1);
    ti.add(s2);

    if(ti.recherche(s)){
        cout<<"Prem "<<ti.extraireMin()<<endl;
    }
    cout<<"deux "<<ti.extraireMin()<<endl;

}
