#include <iostream>
#include<algorithm>
#include <utility>

using namespace std;

int main()
	{
		int t;
		cin >> t;
		while(t--)
			{
				int n;
				cin >> n;
				long long a[n][2];
				for(int i=0;i<n;i++)
					{
						cin >> a[i][0];
						a[i][1]=i;
					}
				pair<long,long> *ptr = (pair<long,long>*) a;
				sort(ptr,ptr+n);
				for(int i=0;i<n;i++)
					cout << a[i][0] << " " << a[i][1]<< endl;		
			}
	}
