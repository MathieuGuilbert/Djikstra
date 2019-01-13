# undef NDEBUG

# include <assert.h>

using namespace std ;

template<class W, class V>
vector< Couple<W,V> > Tas_id<W,V>::getTab() const{
    return this->tab;
}

template<class W, class V>
map<V, int> Tas_id<W,V>::getQuick() const{
    return quick;
}

template<class W, class V>
bool Tas_id<W,V>::estVide(){
    return tab.empty() ;
}


template<class W, class V>
Couple<W,V> Tas_id<W,V>::extraireMin(){

    assert(!tab.empty());

    Couple<W,V> res=this->tab[0];
    quick.erase(res.getSom());

    if(tab.size()>1){ //si il restera quelque chose dans le tas apres extraction
        tab[0]=tab[tab.size()-1];
        quick[tab[0].getSom()]=0;  //MAJ de position
        tab.erase(tab.begin()+(tab.size()-1)); //ne pas oublier d'enlever un element

        int i=0;
        unsigned int gauche, droit, mini;
        Couple<W,V> tmp;

        while(i!=(-1)){  //peut etre aussi fais avec une nouvelle méthode Tas<V>::Tri
            gauche=2*i+1;
            droit=2*i+2;
            //trouver l'indice du plus petit des fils
            if (droit>=tab.size()){
                if (gauche>=tab.size()){
                    return res;
                }else{
                    mini=gauche;
                }
            }else{
                if( tab[gauche]<=tab[droit]){
                    mini=gauche;
                }else{
                    mini=droit;
                }
            }
            //voir si la val min est plus petite que celle à l'indice i (si oui, on doit continuer le tri)
            if(tab[i]>tab[mini]){
                tmp=tab[mini];
                tab[mini]=tab[i];
                quick[tab[i].getSom()]=mini;
                tab[i]=tmp;
                quick[tab[mini].getSom()]=i;
                i=mini;
            }else{
                i=-1;
            }
        }
    }else{
        tab.erase(tab.begin());  //juste cela car pas besoin de trier si il n'y a pas plus d'un element
    }
    return res;
}



template<class W, class V>
void Tas_id<W,V>::add(Couple<W,V> s){
    unsigned int i=this->tab.size();
    while( i>0 && s<tab[(i-1)/2]){    //> OU >= ?
        if(i==tab.size()){
            Couple<W,V> z=tab[(i-1)/2];
            tab.push_back(z); //car tab[i] n'existe pas encore
        }else{
            tab[i]=tab[(i-1)/2];
        }
        quick[tab[(i-1)/2].getSom()]=i; //changer dans la map la positon du sommet déplacé
        i=((i-1)/2);
    }
    if(i==tab.size()){      //car tab[i] n'existe pas encore
        tab.push_back(s);
    }else{
        tab[i]=s;
    }
    quick.insert(pair<V, int>(s.getSom() ,i));

    /*tab.push_back(s);
    cout<<"taille tab"<<tab.size()<<endl;*/
}


template<class W, class V>
int Tas_id<W,V>::recherche(V s){   //O(1)
    return quick[s];
}

template<class W, class V>
bool Tas_id<W,V>::maj(V s, W newDist){
    int posS=recherche(s);
    if(tab[posS].getDist() > newDist){  //la val stocké doit changer
        tab[posS].setDist(newDist);

        Couple<W,V> c=tab[posS];
        Couple<W,V> tmp;
        unsigned int i=posS;
        while( i>0 && c<tab[(i-1)/2] ){
            tmp=tab[(i-1)/2];
            tab[(i-1)/2]=tab[i];
            quick[tab[i].getSom()]=(i-1)/2;
            tab[i]=tmp;
            quick[tab[(i-1)/2].getSom()]=i;
            i=(i-1)/2;
        }

        return true;
    }
    return false;
}



template<class W, class V>
Tas_id<W,V>::~Tas_id(){

}
