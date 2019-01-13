# include <iostream>
#include <string>
#include <fstream>
# include <assert.h>

# undef NDEBUG

using namespace std ;

template<class U,class T>
int Graphe<U,T>::getSize() const{
    return this->liste.size();
}

template<class U,class T>
vector< pair <Sommet<T> , vector< pair<U,Sommet<T> > > > > Graphe<U,T>::getListe() const{
    return liste;
}

template<class U,class T>
void Graphe<U,T>::add_sommet(Sommet<T> i,vector< pair<U,Sommet<T> > > voisins)
{
    pair <Sommet<T>, vector< pair<U,Sommet<T> > > > p;
    p.first=i;
    p.second=voisins;
    this->liste.push_back(p);
}

//on ne peut pas creer une arete sans que la source ne sois creer
template<class U,class T>
void Graphe<U,T>::add_arrete(Sommet<T> source, pair<U,Sommet<T> > arrete)
{
    int i=0;
    while(i<liste.size()){
        if ((liste[i]).first==source)
        {
            (liste[i]).second.push_back(arrete);
            return;
        }
        i++;
    }
    cout<< "ERREUR: la source n'existe pas" << endl;
}

template<class U,class T>
void Graphe<U,T>::suppr_sommet(Sommet<T> sommet)
{
    for(int i=0; i<liste.size(); i++)
    {
        if((liste[i]).first==sommet)
         {
            liste.erase(liste.begin()+i);
        }
        else
        {
            vector< pair<U,Sommet<T> > > v=(liste[i]).second; //on regarde dans la liste associé au sommet i
            for(int j=0; j<v.size(); j++)
            {
                if((v[j]).second==sommet)  //si la destination est sommet
                {
                    v.erase(v.begin()+j);
                }
            }
        }
    }

}

template<class U,class T>
void Graphe<U,T>::suppr_arrete(Sommet<T> source, pair<U,Sommet<T> > arrete)
{
    int i=0;
    while(i<liste.size())
    {
        if ((liste[i]).first==source)
        {
            vector< pair<U,Sommet<T> > > v=(liste[i]).second;
            int j=0;
            while(j<v.size())
            {
                if ( (v[j].first==arrete.first) && (v[j].second==arrete.second) )
                {
                    v.erase(v.begin()+j);
                    return;
                }
                j++;
            }
            cout<< "ERREUR: l'arrete n'existe pas" << endl;
        }
        i++;
    }
    cout<< "ERREUR: la source n'existe pas" << endl;
}

template <class U,class T>
std :: ostream & operator << (std :: ostream & ost , Graphe<U,T> const & g){
    for(unsigned int i=0;i<g.liste.size(); i++){
        vector< pair<U,Sommet<T> > > v=(g.liste[i]).second;
        for(unsigned int j=0;j<v.size(); j++){
            ost << "( Source : " << g.liste[i].first << "-> Poid: " << v[j].first << " -> Destination: " << v[j].second << "\n ";
        }
    }
    return ost;
}

/*std :: ostream & operator << (std :: ostream & ost , Graphe const & g) {  //version TD5
	ofstream fichier("test.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
	if(fichier) {
		fichier << "digraph { " << endl;
		for(int i=0;i<g.liste.size(); i++){
			vector< pair<int,int> > v=(g.liste[i]).second;
			for(int j=0;j<v.size(); j++){
				fichier<< g.liste[i].first << "->" << v[j].second << "[label=\""<< v[j].first <<"\",weight=\"" << v[j].first <<"\"];"<<endl;
			}
		}
		fichier << "}" << endl;
		fichier.close();
	}else{
		 cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}*/

template<class U,class T>
Graphe<U,T>::~Graphe()
{
    //delete(liste);
}
