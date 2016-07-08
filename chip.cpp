#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
	{
		int t;
		cin >> t;
		int orgt=t;

		while(t--)
			{
				double resu,n;
				cin >> n;
				resu=4.0*((double)pow(n,2))+(1.0/4.0);
				cout << "Case "  <<  orgt-t << ": "    << setprecision(50)  << resu << endl;
			}
	}
