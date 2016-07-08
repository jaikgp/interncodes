#include <iostream>
#include <algorithm>
#define monty 1000000007
using namespace std;
 
long long mods(long long prod)
	{
		if(prod>0)
			return prod;
		else if(prod<0)
			return monty+(prod%monty);
		else
			return 0;
	}
 
int main()
	{
		//cout << "this is a drill" << endl;
		//cout << (-1%monty) << " drill end" << endl;
		int t;
		cin >> t;
		while(t--)
			{	
				int n,k;
				long long pos[100001],neg[100001],comb[100001];
				int p=0,ne=0,zeroflag=0,zip=0;
				cin >> n >> k;
				for(int i=0;i<n;i++)
					{
						long long temp;
						cin >> temp;
						if(temp > 0)
							pos[p++]=temp;
						else if(temp < 0)
							neg[ne++]=temp;
						else 
							{
								zeroflag=1;
								zip++;
							}
					}
				if(zip==n)
					{
						cout << 0 << endl;
						continue;
					}
				sort(pos,pos+p);
				sort(neg,neg+ne);
				int po=0,nes=ne-1,co=0,zer=0;
				
				while(po<p&&nes>=0)
					{
						if(pos[po]<(neg[nes]*-1))
							comb[co++]=pos[po++];
						else
							{
								comb[co++]=neg[nes--];
								if(co>n-k)
									zer++;
							}
 
					}
				while(po<p)
					comb[co++]=pos[po++];
				while(nes>=0)
					{
						comb[co++]=neg[nes--];
						if(co>n-k)
							zer++;
					}
			/*	cout << "test" << endl;
				for(int i=0;i<n;i++)
					cout << comb[i] << " " ;
				cout << endl << "zer=" << zer << "test ends" << endl;
			*/	long long prod=1;
				if(zer%2==0)
					{
						for(int i=n-k-zip;i<n-zip;i++)
							{
								prod*=comb[i];
								prod=prod%monty;
							}
						if(prod<0&&zeroflag==1)
							cout << 0 << endl;
						else
							cout << mods(prod) << endl;	
					}
				else if(ne==n)
					{
						for(int i=0;i<k-zip;i++)
							{
								prod*=comb[i];
								prod=prod%monty;
							}
						if(prod<0&&zeroflag==1)
							cout << 0 << endl;
						else
							cout << mods(prod) << endl;
					}
				else
					{
						int poscout=0,negcount=0;
						long long posval=1,negval=1;
						for(int i=n-k-zip;i<n-zip;i++)
							{
								if(poscout==0&&comb[i]>0)
									{
										posval=comb[i];
										poscout=1;	
									}
								if(negcount==0&&comb[i]<0)
									{
										negval=-1*comb[i];
										negcount=1;	
									}
								if(negcount==1&&poscout==1)
									break;
							}
						int flag=0;
						if(poscout==0)
							flag=1;
						poscout=0;negcount=0;
						long long bigp=0,bign=0;
						for(int i=n-k-1-zip;i>=0;i--)
							{
								if(poscout==0&&comb[i]>0)
									{
										bigp=comb[i];
										poscout=1;	
									}
								if(negcount==0&&comb[i]<0)
									{
										bign=-1*comb[i];
										negcount=1;	
									}
								if(negcount==1&&poscout==1)
									break;
							}
						if(poscout==0)
							bigp=comb[0];
						if(negcount==0)
							flag=1;
						double r1,r2;
						int check=0;
						r1=((double)bigp)/((double)negval);
						r2=((double)bign)/((double)posval);
			/*			cout << endl << "next test" << endl;
						cout << "r1=" << r1 << "r2=" << r2 << "negval=" << negval << "posval" << posval;
						cout << "bigp" << bigp << "bign" << bign << endl << "test ends huah" << endl << "flag" << flag << endl;
			*/			if(r1>r2||flag==1)
							{
								prod=bigp;
								prod=prod%monty;
								for(int i=n-k-zip;i<n-zip;i++)
									{
										if((comb[i]==(-1*negval))&&check==0)
											{
												continue;
												check=1;
											}
										prod*=comb[i];
										prod=prod%monty;
									}
								if(prod<0&&zeroflag==1)
									cout << 0 << endl;
								else
									cout << mods(prod) << endl;			
							}
						else
							{
								prod=-1*bign;
								prod=prod%monty;
								for(int i=n-k-zip;i<n-zip;i++)
									{
										if(comb[i]==posval&&check==0)
											{
												continue;
												check=1;
											}
										prod*=comb[i];
										prod=prod%monty;
									}
								if(prod<0&&zeroflag==1)
									cout << 0 << endl;
								else
									cout << mods(prod) << endl;
							}
					}
				
 
			}
	}	
