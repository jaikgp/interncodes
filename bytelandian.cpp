#include <iostream>
#include <string.h>
#include <stdlib.h> 
using namespace std;

long long a[1000000001]={0};

long long maxs(long long a,long long b)
	{
		return (a>b)?a:b;
	}
long long find_max(long long n)
	{
		return maxs(n,find_max(n/2)+find_max(n/3)+find_max(n/4));
	}

int main()
	{
		
		long long t[11];
		string s,u="\n";
		cin >> s;
		int x=0;
		while(s.compare(u)!=0)
			{
				string::iterator it;
				long long num=0;
				for(it=s.begin();it!=s.end();it++)
					{
						char c=*it;
						int temp=(int)(c-'0');
						num=num*10+temp;	
					}
				t[x++]=num;
				cin >> s;		
			}
		for(int i=0;i<x;i++)
			cout << find_max(t[x]) << endl;
	}
