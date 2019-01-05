# undef NDEBUG

using namespace std ;

template<class V>
V Tas<V>::extraireMin(){
    V res=this->tab.front();
    this->tab.erase(this->tab.begin());
    return res;
}

template<class V>
void Tas<V>::add(V s){
    this->tab.push_back(s);
}

template<class V>
int Tas<V>::recherche(V s){
    return 0;
}

template<class V>
Tas<V>::~Tas(){

}
