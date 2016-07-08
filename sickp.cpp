#include <iostream>
#include <math.h>
#define dim 105
    using namespace std;
     
    long long monty=1000000007;
    int funt[dim][dim];
     
    void init()
    	{
    		for(int i=0;i<dim;i++)
    			{
    				funt[i][0]=1;
    				funt[i][1]=i;
    			}
    		for(int i=0;i<dim;i++)
    			{
    				funt[0][i]=1;
    				funt[1][i]=1;
    			}
    		for(int i=2;i<dim;i++)
    			{
    				for(int j=2;j<dim;j++)
    					{
    						funt[i][j]=funt[i-1][j-1]+funt[i-1][j];
    						funt[i][j]=funt[i][j]%monty;
    					}
    			}
    		return;
    	}
     
    void countn(int n,int k,int z)
    	{
    	    if(n==z)
    	        {
    	            cout << 1 << endl;
    	            return;
    	        }
    	    if(z==0)
    	        {
    	            cout << funt[n][k] << endl;
    		        return;
    	        }
    		int sum=0;
            int x=z-1;
    		for(int i=0;k>=i&&x>=0&&i<2;i++)
    			{
    				sum+=funt[n-z][k-i];
    				sum=sum%(monty);
    			}
    		cout << sum << endl;
    		return;
    	}
     
    int main() 
    {
    	init();
    	int t;
    	cin >> t;
    	while(t--)
    		{
    			int n,k,z=0;
    			cin >> n >> k;
    			long long temp;
    			for(int i=0;i<n;i++)
    				{
    					cin >> temp;
    					if(temp==0)
    						z++;
    				}
    			countn(n,k,z);
    		}
    	return 0;
    } 
