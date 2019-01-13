#include <iostream>
#include <map>
# include "graphe.hpp"
# include "sommet.hpp"
# include "couple.hpp"
# include "tas.hpp"
# include "tas_id.hpp"


using namespace std;


template<typename U,typename T>
map<Sommet<T>, pair<int,Sommet<T> > > Djikstra(Graphe<U,T> const graphe, Sommet<T> start){  //vas retourner un tas id

    vector< pair <Sommet<T> , vector< pair<U,Sommet<T> > > > > g=graphe.getListe();
    Tas_id<U,Sommet<T> > aTraite;  //pas de () sinon bug, (mais peut etre probleme plus tard ?)
    map<Sommet<T>, pair<int,Sommet<T> > > res; //associe sommet avec le poids et le sommet par lequel il passe pour atteindre strat  // ATT devrait etre géné


    Sommet<T> minTmp;
    vector< pair<U,Sommet<T> > > voisinsTmp;

    //Initialisation
    for(int i = 0 ; i < graphe.getSize() ; i++ ){
        if(g[i].first==start){
            res.insert(pair<Sommet<T>, pair<int,Sommet<T> > >(g[i].first ,pair<int,Sommet<T> >(0,start)) );
            minTmp=(g[i].first);
            voisinsTmp=g[i].second; //pour recuperer la liste des voisins de start
        }else{
            aTraite.add(Couple<U,Sommet<T> >(1000,g[i].first) );
            res.insert(pair<Sommet<T>, pair<int,Sommet<T> > >(g[i].first ,pair<int,Sommet<T> >(1000,minTmp)) );  //minTmp au lieu de vNULL car NULL marche pas
        }
    }
    //mise à jour des voisins de start
    for(unsigned int k=0; k<voisinsTmp.size(); k++){
        if( aTraite.maj(voisinsTmp[k].second,voisinsTmp[k].first)){
            //modif res
            res[voisinsTmp[k].second]=pair<int,Sommet<T> >(aTraite.getQuick()[voisinsTmp[k].second],minTmp);
        }
    }

    pair <Sommet<T> , vector< pair<U,Sommet<T> > > > tmp;
    int i;

    while(!aTraite.estVide()){
        //recherche de la liste des voisins de minTmp dans le graphe
        i=0;
        tmp=g[0];
        Couple<U,Sommet<T> > coupleMin(aTraite.extraireMin());  //pour le pas avoir a faire constructeur vide
        minTmp=coupleMin.getSom();
        while( tmp.first!=minTmp){
            tmp=g[i];
            i++;
        }
        voisinsTmp=tmp.second;
        //mise à jour des voisins de minTmp
        for(unsigned int k=0; k<voisinsTmp.size(); k++){
            if( aTraite.maj(voisinsTmp[k].second,res[minTmp].first+voisinsTmp[k].first)){ //poids jusqu'a tmp+poid entre tmp et g[k]
            //modif res
            res[voisinsTmp[k].second]=pair<int,Sommet<T> >(aTraite.getQuick()[voisinsTmp[k].second],minTmp);
        }
        }
    }
    return res;
}




int main()
{
    Graphe<int,int> g; //ça devrait marcher

    //Sommet<float> s(2,5.0);  TODO pourquoi float et string marche pas ?
    Sommet<int> s(1,6);
    Sommet<int> s1(2,3);
    Sommet<int> s2(3,2);

	cout<<"Affichage des sommets : "<<endl;
    cout<<s<<endl;
    cout<<s1<<endl;

	pair<int,Sommet<int> > p;
	p.first=4;
    p.second=s1;

    //s1
    vector< pair<int,Sommet<int> > > v;
    v.push_back(p);
    v.push_back(pair<int,Sommet<int> >(6,s2));
    g.add_sommet(s, v);

    //s1
    vector< pair<int,Sommet<int> > > v1;
    v1.push_back(pair<int,Sommet<int> >(1,s2));
    g.add_sommet(s1,v1);

	cout<<"Affichage de G : "<<endl;
    cout<<g<<endl;

    map<Sommet<int>, pair<int,Sommet<int> > > test=Djikstra(g,s);

    //test tas  int/douche ect
    /*Tas<double> t(3);
    t.add(5);
    t.add(4);
    t.add(1);*/

    /*Tas<Sommet<int> > t(s);
    t.add(s1);
    t.add(s2);

    if(t.recherche(s,0)){
        cout<<"Prem "<<t.extraireMin()<<endl;
    }
    cout<<"deux "<<t.extraireMin()<<endl;

    cout<< "\n Test Tas_id"<<endl;

    Couple<int,Sommet<int> > c(2,s);
    Couple<int,Sommet<int> > c1(3,s1);
    Couple<int,Sommet<int> > c2(4,s2);

    Tas_id<int,Sommet<int> > ti(c);
    ti.add(c1);
    ti.add(c2);


    cout<< "Recherche Tas_id ok "<<ti.recherche(s2)<<endl;*/




    /*if(ti.recherche(s)){
        cout<<"Prem "<<ti.extraireMin()<<endl;
    }
    cout<<"deux "<<ti.extraireMin()<<endl;*/

}
