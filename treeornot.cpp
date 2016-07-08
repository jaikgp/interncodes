#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>

using namespace std;

class Vertex
	{
		private:
			int data;
			list<int> nbrs;
			bool visited;

		public:
			Vertex(int a);
			int get_value();
			list<int> get_list();
			void add_nbr(int a);
			bool get_state();
			void set_state(bool states);
	};

void Vertex::set_state(bool states)
	{
		visited=states;
	}

bool Vertex::get_state()
	{
		return visited;
	}

void Vertex::add_nbr(int a)
	{
		nbrs.push_back(a);
	}

int Vertex::get_value()
	{
		return data;
	}

Vertex::Vertex(int a):data(a)
	{
		visited=false;
	}

list<int> Vertex::get_list()
	{
		return nbrs;
	}

class Graph
	{
		private:
			list<Vertex> grf;
			
		public:
			Graph();
			void add_vertex(int a);
			void add_edge(int a,int b);
			Vertex* get_vertex(int a);
			void prints();
			void dfs(int start);
			void bfs(int start);
	};

Graph::Graph()
	{}

void Graph::dfs(int start)
	{
		stack<int> st;
		st.push(start);
		while(!st.empty())
			{
				//cout << "in" << endl;
				int topy=st.top();
				Vertex *tops;
				tops=get_vertex(topy);
				st.pop();
				if(!(tops->get_state()))
					{
						//cout << "risk" << endl;
						cout << tops->get_value() << " --> ";
						tops->set_state(true);
						list<int>::iterator it;
						list<int> temp;
						temp=tops->get_list();
						for(it=temp.begin();it!=temp.end();it++)
							st.push(*it);
					}	
	
			}		
	}


void Graph::add_vertex(int a)
	{
		Vertex v(a);
		grf.push_back(v);
	}

void Graph::add_edge(int a,int b)
	{
		Vertex *temp_a,*temp_b;
		temp_a=get_vertex(a);
		temp_b=get_vertex(b);
		temp_a->add_nbr(b);
		temp_b->add_nbr(a);
	}

Vertex* Graph::get_vertex(int a)
	{
		list<Vertex>::iterator it;

		for(it=grf.begin();it!=grf.end();it++)
			{
				if(it->get_value()==a)
					return &*it;
			}
		add_vertex(a);
		return get_vertex(a);	
	}

void Graph::prints()
	{
		list<Vertex>::iterator it;
		for(it=grf.begin();it!=grf.end();it++)
			{
				list<int>::iterator its;
				list<int> temp;
				temp=it->get_list();
				cout << it->get_value() << " --> ";
				for(its=temp.begin();its!=temp.end();its++)
					cout << *its << " -->  ";
				cout << endl; 
			}
	}

int main()
	{
		Graph g;
		int t;
		cin >> t;
		while(t--)
			{
				int a,b;
				cin >> a >> b;
				g.add_edge(a,b);
			}
		g.prints();
		cout << "prints" << endl;
		g.dfs(5);
		cout << "dfs ends" << endl;
	}
