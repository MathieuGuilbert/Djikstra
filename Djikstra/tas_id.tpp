# undef NDEBUG

# include <assert.h>

using namespace std ;

template<class V>
vector<V> Tas_id<V>::getTab() const{
    return quick;
}

template<class V>
map<V, int> Tas_id<V>::getQuick() const{
    return quick;
}

template<class V>
bool Tas_id<V>::estVide(){
    return tab.empty() ;
}


template<class V>
V Tas_id<V>::extraireMin(){

    assert(!tab.empty());

    V res=this->tab[0];
    quick.erase(res);

    if(tab.size()>1){ //si il restera quelque chose dans le tas apres extraction
        tab[0]=tab[tab.size()-1];
        quick[tab[0]]=0;  //MAJ de position
        tab.erase(tab.begin()+(tab.size()-1)); //ne pas oublier d'enlever un element

        int i=0;
        unsigned int gauche, droit, mini;
        V tmp;

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
                quick[tab[i]]=mini;
                tab[i]=tmp;
                quick[tab[mini]]=i;
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



template<class V>
void Tas_id<V>::add(V s){
    unsigned int i=this->tab.size();
    while( i>0 && s<tab[(i-1)/2]){    //> OU >= ?
        if(i==tab.size()){
            V z=tab[(i-1)/2];
            tab.push_back(z); //car tab[i] n'existe pas encore
        }else{
            tab[i]=tab[(i-1)/2];
        }
        quick[tab[(i-1)/2]]=i; //changer dans la map la positon du sommet déplacé
        i=((i-1)/2);
    }
    if(i==tab.size()){      //car tab[i] n'existe pas encore
        tab.push_back(s);
    }else{
        tab[i]=s;
    }
    quick.insert(pair<V, int>(s,i));

    /*tab.push_back(s);
    cout<<"taille tab"<<tab.size()<<endl;*/
}


template<class V>
bool Tas_id<V>::recherche(V s){   //O(n)
    if(quick.find(s) != quick.end()){
        return true;
    }
    return false;
}


template<class V>
Tas_id<V>::~Tas_id(){

}
