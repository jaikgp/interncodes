#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
	{
		int n;
		cin >> n;
		while(n!=0)
			{	
				int index=0;
				bool flag=true;
				stack<int> st;
				while(n--)
					{
						int temp;
						cin >> temp;
						if(temp==index+1)
							index++;
						else
							{
								while(!st.empty()&&st.top()==index+1)
									{
										st.pop();
										index++;
									}
								st.push(temp);
							}
					}
				while(!st.empty()&&st.top()==index+1)
					{
						st.pop();
						index++;
					}
				if(!st.empty())
					cout << "no" << endl;
				else
					cout << "yes" << endl;
				cin >> n;
			}
	}
