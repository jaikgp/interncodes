#include <iostream>
#include <algorithm>
#define monty 1000000007

using namespace std;

int main()
    {
        int t;
        cin >> t;
        while(t--)
            {
                int n,k;
                cin >> n >> k;
                long long pos[100001],neg[100001],comb[100001];
                int p_pointer=0,n_pointer=0,z_count=0;
                for(int i=0;i<n;i++)
                    {
                        long long temp;
                        cin >> temp;
                        if(temp > 0)
                            pos[p_pointer++]=temp;
                        else if(temp < 0)
                            neg[n_pointer++]=temp;
                        else
                            z_count++;
                    }
                sort(pos,pos+p_pointer);
                sort(neg,neg+n_pointer);
                int sec_p_pointer=0,sec_n_pointer=n_pointer-1,co_pointer=0,zer_count=0;
                while(sec_p_pointer<p_pointer&&sec_n_pointer>=0)
                    {
                        if(pos[sec_p_pointer]<(-1*neg[sec_n_pointer]))
                            comb[co_pointer++]=pos[sec_p_pointer++];
                        else
                            {
                                comb[co_pointer++]=neg[sec_n_pointer--];
                                if(co_pointer>n-k-z_count)
                                    zer_count++;
                            }
                    }
                while(sec_n_pointer>=0)
                    {
			comb[co_pointer++]=neg[sec_n_pointer--];
			if(co_pointer>n-k-z_count)
				zer_count++;
		    }
                while(sec_p_pointer<p_pointer)
                    comb[co_pointer++]=pos[sec_p_pointer++];
                
                if(n-z_count<k)
                    cout << "test1=" << 0 << endl;
                
                else if(zer_count%2==0)
                    {
                        long long prod=1;
                        for(int i=n-k-z_count;i<n-z_count;i++)
                            {
                                prod*=comb[i];
                                prod=prod%monty;
                            }
                        cout << "test2="  << prod << endl;
                    }
                else
                    {
                        int poscount=0,posval=0,negcount=0,negval=0;
                        for(int i=n-k-z_count;i<n-z_count;i++)
                            {
                                if(comb[i]>0)
                                    {
                                        poscount=1;
                                        posval=comb[i];
                                    }
                                else
                                    {
                                        negcount=1;
                                        negval=comb[i];
                                    }
                                if(poscount==1&&negcount==1)
                                    break;
                            }
                        if(poscount==0)
                            {
                                int j;
                                for(j=n-k-1-z_count;j>=0;j--)
                                    {
                                        if(comb[j]>0)
                                            break;
                                    }
                                if(j<0)
                                    {
                                        long long prod=1;
                                        for(int i=0;i<k;i++)
                                            {
                                                prod*=comb[i];
                                                prod=prod%monty;
                                            }
                                        if(prod>0)
                                            cout << "test3=" << prod << endl;
                                        else if(z_count==0)
                                            cout << "test4="  << monty+(prod%monty) << endl;
					else
					    cout << 0 << endl;
                                    }
                                else
                                    {
                                        long long prod=comb[j];
                                        int flag=0;
					for(int i=n-k-z_count;i<n-z_count;i++)
                                            {
                                                if(comb[i]==negval&&flag==0)
                                                    {
							continue;
							flag=1;
						    }	
                                                prod*=comb[i];
                                                prod=prod%monty;
                                            }
                                        if(prod>0)
                                            cout << "test5="  << prod << endl;
                                        else if(z_count==0)
                                            cout << "test6="  << monty+(prod%monty) << endl;
                                        else
					    cout << 0 << endl;
                                    }
                            }
                        else
                            {
                                poscount=0;negcount=0;
                                int bigp=1,bign=1;
                                for(int i=n-k-1-z_count;i>=0;i--)
                                    {
                                        if(comb[i]<0)
                                            {
                                                bign=comb[i];
                                                negcount=1;
                                            }
                                        else
                                            {
                                                bigp=comb[i];
                                                poscount=1;
                                            }
                                        if(poscount==1&&negcount==1)
                                            break;
                                    }
                                if(negcount==0)
                                    {
					int flag=0;
                                        long long prod=bigp;
                                        for(int i=n-k-z_count;i<n-z_count;i++)
                                            {
                                                if(comb[i]==negval&&flag==0)
                                                    {
							continue;
							flag=1;
						    }
                                                prod*=comb[i];
                                                prod=prod%monty;
                                            }
                                        if(prod>0)
                                            cout << "test7="  << prod << endl;
                                        else if(z_count==0)
                                            cout << "test8="  << monty+(prod%monty) << endl;
                                        else
					    cout << 0 << endl;
                                    }
                                else if(poscount==0)
                                    {
					bool flag=true;
					int count=0;
                                        long long prod=bign;
                                        for(int i=n-k-z_count;i<n-z_count;i++)
                                            {
                                                if(comb[i]==posval&&(flag))
                                                   {
							 count++;
							 continue;
							 flag=false;
						   }	
                                                prod*=comb[i];
                                                prod=prod%monty;
                                            }
                                        if(prod>0)
                                            cout << "test9="  << prod << endl << "count=" << count << endl;
                                        else if(z_count==0)
                                            cout <<  "test10="  << monty+(prod%monty) << endl;
					else
					    cout << 0 << endl;
                                    }
                                else
                                    {
                                        double r1,r2;
						                r1=-1.0*((double)bigp)/((double)negval);
						                r2=-1.0*((double)bign)/((double)posval);
						                if(r2>r1)
						                    {int flag=0;
						                        long long prod=bign;
                                                for(int i=n-k-z_count;i<n-z_count;i++)
                                                    {
                                                        if(comb[i]==posval&&flag==0)
                                                            {continue;flag=1;}
                                                        prod*=comb[i];
                                                        prod=prod%monty;
                                                     }
                                                if(prod>0)
                                                    cout << "test11="  << prod << endl;
                                                else if(z_count==0)
                                                    cout << "test12="   << monty+(prod%monty) << endl;
						else
						    cout << 0 << endl;
						                    }
						                else
						                    {	int flag=0;
						                        long long prod=bigp;
                                                for(int i=n-k-z_count;i<n-z_count;i++)
                                                    {
                                                        if(comb[i]==negval&&flag==0)
                                                            {continue;flag=1;}
                                                        prod*=comb[i];
                                                        prod=prod%monty;
                                                    }
                                                if(prod>0)
                                                    cout << "test13="  << prod << endl;
                                                else if(z_count==0)
                                                    cout << "test14="  << monty+(prod%monty) << endl;
						else
						    cout << 0 << endl;
						                    }
						              
                                    }
                            }
                        
                    }
                
            }
    }

