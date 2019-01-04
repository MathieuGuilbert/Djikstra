#include <iostream>
# include "graphe.hpp"
# include "sommet.hpp"


using namespace std;

int main()
{
    Graphe<int> g; //ça devrait marcher

    //Sommet<float> s(2,5.0);  MARCHE PAS urement à cause de c++11  (same avec stirng
    Sommet<int> s(1,6);

    cout<<s<<endl;

    vector< pair<int,Sommet<int> > > v=vector< pair<int,Sommet<int> > >();
    g.add_sommet(s, v);

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
