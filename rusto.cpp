#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stdlib.h>
#include <list>
#include <stack>

using namespace std;

class Vertex
	{
		private:
			list<Vertex*> nbrs;
			int data;
			bool visited;
		
		public:
			bool get_state();
			void set_state(bool val);
			Vertex(int a);
			void add_nbr(Vertex* b);
			list<Vertex*> get_list();
			int get_value();
	};

list<Vertex*> Vertex::get_list()
	{
		return nbrs;
	}

void Vertex::add_nbr(Vertex* b)
	{
		nbrs.push_back(b);
	}

Vertex::Vertex(int a):data(a)
	{
		visited=false;
	}

bool Vertex::get_state()
	{
		return visited;
	}

void Vertex::set_state(bool val)
	{
		visited=val;
	}

int Vertex::get_value()
	{
		return data;
	}

class Graph
	{
		public:
			Graph();
			void add_edge(int a,int b);
			void add_vertex(int a);
			void prints();
			void dfso(Vertex start);
			void dfs(int starts);
			void test(Vertex* start);
		private:
			list<Vertex> grf;
			queue<Vertex> q;
			stack<Vertex> st;
	};

Graph::Graph()
	{}


void Graph::dfs(int starts)
	{
		list<Vertex>::iterator it;
		for(it=grf.begin();it!=grf.end();it++)
			{
				if(it->get_value()==starts)
					{
						dfso(*it);
						cout << endl;
						test(&*it);
						return;
					}
			}
	}

void Graph::dfso(Vertex start)
	{
		cout << start.get_value() << " --> ";
		start.set_state(true);
		list<Vertex*> temp;
		list<Vertex*>::iterator it;
		temp=start.get_list();
		for(it=temp.begin();it!=temp.end();it++)
			{
				if(!((*it)->get_state()))
					{
						st.push(**it);
						(*it)->set_state(true);
					}		
			}
		if(st.empty())
			return;
			
		Vertex next=st.top();
		st.pop();
		dfso(next);
	}


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
		
		if(!flag_a&&!flag_b)
			{
				add_vertex(a);
				add_vertex(b);
				add_edge(a,b);
				return;

			}
		if(!flag_a)
			{
				add_vertex(a);
				add_edge(a,b);
				return;
			}		
		if(!flag_b)
			{
				add_vertex(b);
				add_edge(a,b);
				return;
			}
		
		
		
		temp_a->add_nbr(temp_b);
		temp_b->add_nbr(temp_a);
	}

void Graph::test(Vertex* start)
	{
		list<Vertex*> temp;
		temp=start->get_list();
		list<Vertex>::iterator it;
		list<Vertex*>::iterator its;
		for(it=grf.begin();it!=grf.end();it++)
			{
				for(its=(it->get_list()).begin();its!=(it->get_list()).end();its++)
					{
						cout << "risf" << endl;								
						cout << (*its)->get_value() << " --> " ;
					}
					cout << endl;
					return;
			}
	}

void Graph::add_vertex(int a)
	{
		Vertex v(a);
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
		g.dfs(5);
		//cout << endl;
	}

