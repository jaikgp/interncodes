#include<iostream>
using namespace std;

int main()
	{
		long long n;
		cin >> n;
		while(n>1)
			{
				if(n%2!=0)
					break;
				n/=2;	
			}
		if(n==1)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;






	}
