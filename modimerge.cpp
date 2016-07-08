#include <iostream>
#include <algorithm>
using namespace std;

int merges(long long a[],int start,int end)
    {
        int inversions=0;
        long long c[end-start+1];
        int mid=(start+end)/2;
        int fp=start,sp=mid;
        int mp=0;
        int bef=0,aft=0;
        while(fp<mid&&sp<end)
            {
                aft=0;
                while(a[fp]>a[sp]&&sp<end&&fp<mid)
                    {
                        c[mp++]=a[sp++];
                        bef++;
			
                    }
                while(a[sp]>a[fp]&&sp<end&&fp<mid)
                    {
                        c[mp++]=a[fp++];
                        aft++;
                    }

		while(a[sp]==a[fp]&&fp<mid&&sp<end)
		    {
			prev=a[sp];
			c[mp++]=a[sp++];
			c[mp++]=a[fp++];
		    }
                inversions+=bef*aft;
            }
	
        while(fp<mid)
            {
                c[mp++]=a[fp++];
                aft++;
            }
        while(sp<end)
            {
		aft=0;
                c[mp++]=a[sp++];
                bef++;
            }
        inversions+=aft*bef;
	mp--;
	for(int i=end-1;i>=start;i--)
		a[i]=c[mp--];
        return inversions;
    }

int modimerge(long long a[],int start,int end)
    {
        int first,second,inversions=0;
        int mid=(start+end)/2;
        if(end-start<=1)
            return inversions;
        first=modimerge(a,start,mid);
        second=modimerge(a,mid,end);
        inversions=first+second;
        inversions+=merges(a,start,end);
        return inversions;
    }

int main() 
{
	int t;
	cin >> t;
	while(t--)
	    {
	        int n;
	        cin >> n;
	        long long a[n];
	        for(int i=0;i<n;i++)
	            cin >> a[i];
	        cout << modimerge(a,0,n) << endl;
	    }
	return 0;
}

