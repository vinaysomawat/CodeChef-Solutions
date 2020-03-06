#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int count=0;
		int p = a[0];
		count++;

		for(int i=1;i<6;i++)
		{
			if(p>a[i])
			{
				count++;
				p = a[i];
			}
		}
		int start=1;
		int end=6;
		while(end!=n)
		{
			int* i1; 
    		i1 = std::min_element(a + start, a + end); 
    		int q = end;
    		if(a[q]<*i1)
    		{
    			count++;
    		}
    		start++;
    		end++;
		}

		cout<<count<<endl;
	}
	return 0;
}