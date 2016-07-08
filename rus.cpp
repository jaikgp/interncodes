#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stdlib.h>
#include <list>
using namespace std;

class Vertex
	{
		private:
			list<Vertex*> nbrs;
			int data;
		
		public:
			Vertex(int a);
			void add_nbr(Vertex *b);
			list<Vertex*> get_list();
			int get_value();
	};

list<Vertex*> Vertex::get_list()
	{
		return nbrs;
	}

void Vertex::add_nbr(Vertex *b)
	{
		//cout << "enter" << endl;
		nbrs.push_back(b);
		//cout << "exits" << endl;
	}

Vertex::Vertex(int a):data(a)
	{}

int Vertex::get_value()
	{
		return data;
	}

class Graph
	{
		public:
			Graph();
			void add_edge(int a,int b);
			Vertex* add_vertex(int a);
			void prints();
		
		private:
			list<Vertex> grf;
	};

Graph::Graph()
	{}

void Graph::prints()
	{
		list<Vertex>::iterator it;
		list<Vertex*>::iterator its;
		for(it=grf.begin();it!=grf.end();it++)
			{
				cout << (*it).get_value() << " --> " ;
				list<Vertex*> temp=(*it).get_list();
				for(its=temp.begin();its!=temp.end();its++)
					cout << (*its)->get_value() <<  " --> ";
				cout << endl;
			}
	}

void Graph::add_edge(int a,int b)
	{
		
		list<Vertex>::iterator it;
		Vertex *temp_a,*temp_b;
		bool flag_a=false,flag_b=false;
		for(it=grf.begin();it!=grf.end();it++)
			{
				if((*it).get_value()==a&&(!flag_a))
					{
						flag_a=true;
						temp_a=&(*it);
					}
				else if((*it).get_value()==b&&(!flag_b))
					{
						flag_b=true;
						temp_b=&(*it);
					}	
				if(flag_a&&flag_b)
					break;

			}
		if(!flag_a)
			temp_a=add_vertex(a);
				
		if(!flag_b)
			temp_b=add_vertex(b);
		
		//if(temp_a==NULL)
		//	cout << "probs" << endl;
		//cout << "ping" << endl;
		temp_a->add_nbr(temp_b);
		//cout << "pit" << endl;
		temp_b->add_nbr(temp_a);
		//cout << "pong" << endl;
		
	}

Vertex* Graph::add_vertex(int a)
	{
		Vertex v(a);
		grf.push_back(v);
		Vertex *cis;
		cis=&v;
		//cout << "exit" << endl;
		return cis;
	}


int main()
	{
		Graph g;
		int n;
		cin >> n;
		while(n--)
			{
				int a,b;
				cin >> a >> b;
				g.add_edge(a,b);
			}
		g.prints();
	}

