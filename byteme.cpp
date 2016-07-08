#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
using namespace std;

map<long long,long long> m;

long long maxs(long long a,long long b)
        {
                return (a>b)?a:b;
        }
long long find_max(long long n)
        {
                if(m.find(n/2)==m.end())
                	m[n/2]=find_max(n/2);
                if(m.find(n/3)==m.end())
                	m[n/3]=find_max(n/3);
                if(m.find(n/4)==m.end())
                	m[n/4]=find_max(n/4);
                return maxs(n,m[n/2]+m[n/3]+m[n/4]);
        }

int main()
        {

                long long t[11];
                int x=0,v;
		cin >> v;
               // while(!(cin.eof()))
                //	cin >> t[x++];
                while(v--)
			{
				cin >> t[x++];
			}
                for(int i=0;i<x;i++)
                        cout << find_max(t[i]) << endl;
        }

