#include <iostream>
#include <stdlib>
#include <map>
#include <queue>
#include <list>
#include <map>

using namespace std;

class graph
	{
		public:
			graph();
			void add_vertex(int a);
			void add_edge(int a,int b);
			void pri(void);
			void increment_glob(void);
			bool finds(int a);
		private:
			list<list<int>> grf;
			map<int,int> mymap; //maps vertex value to list index
			int glob_count; //keeps track of list index
	}
void graph::pri()
	{
		list<int>::iterator it;
		for(list<list<int>>::iterator i=grf.begin();i!=grf.end();i++)
			{
				cout << mymap[grf[i]];
				for(list<int> iterator it=grf[i].begin;it!=grf[i].end();it++)
					cout << "->" << mymap[it];
					cout << endl;
			}
	}

graph::graph():glob_count(0)
	{}
bool graph::finds(int a)
	{
		map<int,int>::iterator it;
		it=mymap.find(a);
		return (it==mymap.end())?false:true;
	}
void graph::add_vertex(int a)
	{
		mymap[a]=glob_count;
		increment_glob();
	}
void graph::increment_glob()
	{
		glob_count++;
	}
void graph::add_edge(int a,int b)
	{
		bool found1=finds(a),found2=finds(b);
		if(!found1)
			add_vertex(a);
		if(!found2)
			add_vertex(b);
		grf[mymap[a]].push_back(mymap[b]);
		grf[mymap[b]].push_back(mymap[a]);
	}

int main()
	{
		int n;
		cin >> n;
		graph grif;
		while(n--)
			{
				int a,b;
				cin >> a >> b;
				grif.add_edge(a,b);
				grif.pri();
			}
		
	}
