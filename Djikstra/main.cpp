#include <iostream>
#include <map>
#include <limits>
# include "graphe.hpp"
# include "sommet.hpp"
# include "couple.hpp"
# include "tas.hpp"
# include "tas_id.hpp"


using namespace std;


template<typename U,typename T>
map<Sommet<T>, pair<U,Sommet<T> > > Djikstra(Graphe<U,T> const graphe, Sommet<T> start){  //vas retourner un tas id

    vector< pair <Sommet<T> , vector< pair<U,Sommet<T> > > > > g=graphe.getListe();
    Tas_id<U,Sommet<T> > aTraite;  //pas de () sinon bug, (mais peut etre probleme plus tard ?)
    map<Sommet<T>, pair<U,Sommet<T> > > res; //associe sommet avec le poids et le sommet par lequel il passe pour atteindre strat  // ATT devrait etre géné


    Sommet<T> minTmp;
    vector< pair<U,Sommet<T> > > voisinsTmp;

    //Initialisation
    for(int i = 0 ; i < graphe.getSize() ; i++ ){
        if(g[i].first==start){
            res.insert(pair<Sommet<T>, pair<U,Sommet<T> > >(g[i].first ,pair<U,Sommet<T> >(0,start)) );
            minTmp=(g[i].first);
            voisinsTmp=g[i].second; //pour recuperer la liste des voisins de start
        }else{
            aTraite.add(Couple<U,Sommet<T> >(numeric_limits<T>::max() ,g[i].first) );  //max remplace le infini du sujet
            res.insert(pair<Sommet<T>, pair<U,Sommet<T> > >(g[i].first ,pair<U,Sommet<T> >(numeric_limits<T>::max() ,minTmp)) );  //minTmp au lieu de vNULL car NULL marche pas
        }
    }
    //mise à jour des voisins de start
    for(unsigned int k=0; k<voisinsTmp.size(); k++){
        if( aTraite.maj(voisinsTmp[k].second,voisinsTmp[k].first)){
            //modif res
            res[voisinsTmp[k].second]=pair<U,Sommet<T> >( aTraite.getTab()[aTraite.getQuick()[voisinsTmp[k].second] ].getDist() ,minTmp); //gros truc pour recu la dist dans le couple du voisins dans k
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
            if( aTraite.maj(voisinsTmp[k].second,res[minTmp].first+voisinsTmp[k].first) ){ //poids jusqu'a tmp+poid entre tmp et g[k]
                //modif res
                res[voisinsTmp[k].second]=pair<U,Sommet<T> >(aTraite.getTab()[aTraite.getQuick()[voisinsTmp[k].second] ].getDist(),minTmp);
            }
        }

    }
    return res;
}




int main()
{
    /*
    Graphe<int,int> g;

    //Sommet<float> s(2,5.0);  TODO pourquoi float et string marche pas ?
    Sommet<int> s(1,6);
    Sommet<int> s1(2,3);
    Sommet<int> s2(3,2);

	cout<<"Affichage des sommets : "<<endl;
    cout<<s<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;

	pair<int,Sommet<int> > p;
	p.first=4;
    p.second=s1;

    //s
    vector< pair<int,Sommet<int> > > v;
    v.push_back(p);
    v.push_back(pair<int,Sommet<int> >(6,s2));
    g.add_sommet(s, v);

    //s1
    vector< pair<int,Sommet<int> > > v1;
    v1.push_back(pair<int,Sommet<int> >(1,s2));
    g.add_sommet(s1,v1);

    //s2
    g.add_sommet(s2,vector< pair<int,Sommet<int> > >());

	cout<<"Affichage de G : "<<endl;
    cout<<g<<endl;

    map<Sommet<int>, pair<int,Sommet<int> > > test=Djikstra(g,s);

    cout<<"Djikstra sur G, a partir de S (1,6) :"<<endl;
    for(map<Sommet<int>, pair<int,Sommet<int> > >::const_iterator it = test.begin(); it != test.end(); ++it){
        std::cout <<" Sommet :"<< it->first << ", Poids : " << it->second.first << ", Sommet precedent :" << it->second.second << endl;
    }
    */

    //EXEMPLE SUJET
    Graphe<long,char> g;

    Sommet<char> s1(1,'A');
    Sommet<char> s2(2,'B');
    Sommet<char> s3(3,'C');
    Sommet<char> s4(4,'D');
    Sommet<char> s5(5,'E');
    Sommet<char> s6(6,'F');
    Sommet<char> s7(7,'G');

    g.add_sommet(s1,vector< pair<long,Sommet<char> > >()); //A lié à rien

    vector< pair<long,Sommet<char> > > v2;
    v2.push_back(pair<long,Sommet<char> >(2,s7));  //B--G
    v2.push_back(pair<long,Sommet<char> >(5,s1));  //B--A
    g.add_sommet(s2,v2);

    vector< pair<long,Sommet<char> > > v7;
    v7.push_back(pair<long,Sommet<char> >(1,s1));  //G--A
    v7.push_back(pair<long,Sommet<char> >(32,s4));  //G--D
    v7.push_back(pair<long,Sommet<char> >(3,s5));  //G--E
    g.add_sommet(s7,v7);

    vector< pair<long,Sommet<char> > > v5;
    v5.push_back(pair<long,Sommet<char> >(7,s3));  //E--C
    g.add_sommet(s5,v5);

    vector< pair<long,Sommet<char> > > v3;
    v3.push_back(pair<long,Sommet<char> >(8,s6));  //C--F
    g.add_sommet(s3,v3);

    vector< pair<long,Sommet<char> > > v6;
    v6.push_back(pair<long,Sommet<char> >(5,s4));  //F--D
    g.add_sommet(s6,v6);

    g.add_sommet(s4,vector< pair<long,Sommet<char> > >()); //D lie a rien


    map<Sommet<char>, pair<long,Sommet<char> > > exSuj=Djikstra(g,s2);

    cout<<"Djikstra sur G, a partir de S (2,B) :"<<endl;
    for(map<Sommet<char>, pair<long,Sommet<char> > >::const_iterator it = exSuj.begin(); it != exSuj.end(); ++it){
        std::cout <<" Sommet :"<< it->first << ", Poids : " << it->second.first << ", Sommet precedent :" << it->second.second << endl;
    }

}
