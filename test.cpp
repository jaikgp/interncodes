#include <iostream>
using namespace std;

void testi(int a[])
	{
		for(int i=0;i<5;i++)
			a[i]=6;
		return;			
	}
void tests(int a[])
	{
		testi(a);
	}

int main()
	{
		int a[5];
		for(int i=0;i<5;i++)
			a[i]=i;
		tests(a);
		for(int i=0;i<5;i++)
			cout << a[i] << " ";

	}
