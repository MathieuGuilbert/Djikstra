# undef NDEBUG

using namespace std ;



template<class V>
void Tas_id<V>::add(V s){
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

    /*tab.push_back(s);
    cout<<"taille tab"<<tab.size()<<endl;*/
}




template<class V>
Tas_id<V>::~Tas_id(){

}
