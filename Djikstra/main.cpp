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
        //cout<<"for voisin start; voisin numero "<<k<<"; mintmp "<<minTmp<<" ;sommet voisin: "<<voisinsTmp[k].second <<" atteint avec le poid "<<voisinsTmp[k].first <<endl;
        if( aTraite.maj(voisinsTmp[k].second,voisinsTmp[k].first)){
            //modif res
            //cout<<"Dans maj du "<<k<<" "<<aTraite.getQuick()[voisinsTmp[k].second]<<endl;
            res[voisinsTmp[k].second]=pair<int,Sommet<T> >( aTraite.getTab()[aTraite.getQuick()[voisinsTmp[k].second] ].getDist() ,minTmp); //gros truc pour recu la dist dans le couple du voisins dans k
        }
    }
    for(map< Sommet<char>, pair<int,Sommet<char> > >::const_iterator it = res.begin(); it != res.end(); ++it){
        std::cout <<" Sommet :"<< it->first << ", Poids : " << it->second.first << ", Sommet precedent :" << it->second.second<< endl;
    }
    cout<<"avec le som"<<minTmp<<"\n"<< endl;

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
        cout<<"nb voisins "<<voisinsTmp.size()<<endl;
        //mise à jour des voisins de minTmp
        for(unsigned int k=0; k<voisinsTmp.size(); k++){
            cout<<k<<" ieme boucle deb "<<res[voisinsTmp[k].second].first<<endl;
            if( aTraite.maj(voisinsTmp[k].second,res[minTmp].first+voisinsTmp[k].first) ){ //poids jusqu'a tmp+poid entre tmp et g[k]
                cout<<k<<" ieme boucle valide pour "<<voisinsTmp[k].second<<endl;
                //modif res
                res[voisinsTmp[k].second]=pair<int,Sommet<T> >(aTraite.getTab()[aTraite.getQuick()[voisinsTmp[k].second] ].getDist(),minTmp);
            }
        }
        for(map< Sommet<char>, pair<int,Sommet<char> > >::const_iterator it = res.begin(); it != res.end(); ++it){
            std::cout <<" Sommet :"<< it->first << ", Poids : " << it->second.first << ", Sommet precedent :" << it->second.second<< endl;
        }
        cout<<"avec le som"<<minTmp<<"\n"<< endl;

    }
    return res;
}




int main()
{

    /*
    //cout<<" 5 div 2"<<5/2<<endl;
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
    Graphe<int,char> g;

    Sommet<char> s1(1,'A');
    Sommet<char> s2(2,'B');
    Sommet<char> s3(3,'C');
    Sommet<char> s4(4,'D');
    Sommet<char> s5(5,'E');
    Sommet<char> s6(6,'F');
    Sommet<char> s7(7,'G');

    g.add_sommet(s1,vector< pair<int,Sommet<char> > >()); //A lié à rien

    vector< pair<int,Sommet<char> > > v2;
    v2.push_back(pair<int,Sommet<char> >(2,s7));  //B--G
    v2.push_back(pair<int,Sommet<char> >(5,s1));  //B--A
    g.add_sommet(s2,v2);

    vector< pair<int,Sommet<char> > > v7;
    v7.push_back(pair<int,Sommet<char> >(1,s1));  //G--A
    v7.push_back(pair<int,Sommet<char> >(32,s4));  //G--D
    v7.push_back(pair<int,Sommet<char> >(3,s5));  //G--E
    g.add_sommet(s7,v7);

    vector< pair<int,Sommet<char> > > v5;
    v5.push_back(pair<int,Sommet<char> >(7,s3));  //E--C
    g.add_sommet(s5,v5);

    vector< pair<int,Sommet<char> > > v3;
    v3.push_back(pair<int,Sommet<char> >(8,s6));  //C--F
    g.add_sommet(s3,v3);

    vector< pair<int,Sommet<char> > > v6;
    v6.push_back(pair<int,Sommet<char> >(5,s4));  //F--D
    g.add_sommet(s6,v6);

    g.add_sommet(s4,vector< pair<int,Sommet<char> > >()); //D lie a rien


    map<Sommet<char>, pair<int,Sommet<char> > > exSuj=Djikstra(g,s2);

    cout<<"Djikstra sur G, a partir de S (2,B) :"<<endl;
    for(map<Sommet<char>, pair<int,Sommet<char> > >::const_iterator it = exSuj.begin(); it != exSuj.end(); ++it){
        std::cout <<" Sommet :"<< it->first << ", Poids : " << it->second.first << ", Sommet precedent :" << it->second.second << endl;
    }



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
