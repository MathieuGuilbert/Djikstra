# undef NDEBUG

# include <assert.h>

using namespace std ;

template<class V>
bool Tas<V>::estVide(){
    return tab.empty() ;
}

template<class V>
V Tas<V>::extraireMin(){
    /*V res=this->tab.front();    //version simpliste
    tab.erase(tab.begin());
    cout<<"tb 1: "<<tab[1]<<endl;*/

    if(tab.empty()){                //peut enlever le if
        assert(!tab.empty());
    }else{
        V res=this->tab[0];

        if(tab.size()>2){ //si il restera plus d'un élément dans le tas

            tab[0]=tab[tab.size()-1];
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
                    tab[i]=tmp;
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
}

template<class V>
void Tas<V>::add(V s){
    unsigned int i=this->tab.size();
    while( i>0 && s<tab[(i-1)/2]){
        if(i==tab.size()){
            V z=tab[(i-1)/2];
            tab.push_back(z); //car tab[i] existe pas encore
        }else{
            tab[i]=tab[(i-1)/2];
        }
        i=((i-1)/2);
    }
    if(i==tab.size()){      //car tab[i] existe pas encore
        tab.push_back(s);
    }else{
        tab[i]=s;
    }
    //cout<<"taille tab"<<tab.size()<<"  "<<tab[0]<<"  "<<tab[1]<<endl;
}


template<class V>
bool Tas<V>::recherche(V s,int index){   //O(n)
    if(index>(tab.size()+1)){
        return false;
    }else{
        if(s==tab[index]){
            return true;
        }else{
            int gauche=2*index+1;
            int droit=2*index+2;
            if(recherche(s,gauche)){
                return true;
            }else{
                if(recherche(s,droit)){
                    return true;
                }
            }
        }
    }
    return false;
}

template<class V>
Tas<V>::~Tas(){
    //delete[] tab;   ??
}
