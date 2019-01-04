#include <iostream>
# include "graphe.hpp"
# include "sommet.hpp"


using namespace std;

int main()
{
    Graphe<int> g; //ça devrait marcher

    //Sommet<float> s(2,5.0);
    Sommet<int> s(1,6);
    Sommet<int> s1(1,3);

	cout<<"Affichage des sommets : "<<endl;
    cout<<s<<endl;
    cout<<s1<<endl;

	pair<int,Sommet<int> > p;
	p.first=1; p.second=s1;
    vector< pair<int,Sommet<int> > > v; v.push_back(p);
    g.add_sommet(s, v);

	cout<<"Affichage de G : "<<endl;
    cout<<g<<endl;

	/*
	Graphe g=Graphe();
	vector< pair<int,int> > v1=vector< pair<int,int> >();
	g.add_sommet(1,v1);
	vector< pair<int,int> > v2=vector< pair<int,int> >();

	pair<int,int> p;
	p.first=1;
	p.second=1;
	v2.push_back(p);

	p.first=1;
	p.second=2;
	v2.push_back(p);

	g.add_sommet(2,v2);



	cout<<g<<endl;
	*/
}
