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
			list<int> nbrs;
			int data;
		
		public:
			Vertex(int a);
			void add_nbr(int b);
			list<int> get_list();
			int get_value();
	};

list<int> Vertex::get_list()
	{
		return nbrs;
	}

void Vertex::add_nbr(int b)
	{
		nbrs.push_back(b);
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
			void add_vertex_nbr(int a,int b);
			void prints();
		
		private:
			list<Vertex> grf;
	};

Graph::Graph()
	{}

void Graph::prints()
	{
		list<Vertex>::iterator it;
		list<int>::iterator its;
		for(it=grf.begin();it!=grf.end();it++)
			{
				cout << (*it).get_value() << " --> " ;
				list<int> temp=(*it).get_list();
				for(its=temp.begin();its!=temp.end();its++)
					cout << *its <<  " --> ";
				cout << endl;
			}
	}

void Graph::add_edge(int a,int b)
	{
		
		list<Vertex>::iterator it;
		bool flag_a=false,flag_b=false;
		for(it=grf.begin();it!=grf.end();it++)
			{
				if((*it).get_value()==a&&(!flag_a))
					{
						flag_a=true;
						(*it).add_nbr(b);
					}
				else if((*it).get_value()==b&&(!flag_b))
					{
						flag_b=true;
						(*it).add_nbr(a);
					}	
				if(flag_a&&flag_b)
					break;

			}
		if(!flag_a)
			add_vertex_nbr(a,b);
				
		if(!flag_b)
			add_vertex_nbr(b,a);

		
		
	}

void Graph::add_vertex_nbr(int a,int b)
	{
		Vertex v(a);
		v.add_nbr(b);
		grf.push_back(v);
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
