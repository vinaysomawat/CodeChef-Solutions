//Vinay Somawat
//vinaysomawat40@gmail.com

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int t;
    cin >> t;
    while(t--)
    {
        unsigned long long L;
        unsigned long long R;
        unsigned long long ans=0;
        cin >> L >> R;
        if(log2(L) == log2(R))
        {
            unsigned long long x = R;
            unsigned long long y=L;
            unsigned long long two = 0;
            while(y<=x)
            {
                ans+=L;
                two+=1;
                L=L&~two;
                y++;
            }
        }
        else
        {
            unsigned long long x = pow(2,(int)(log2(L)+1));
            unsigned long long y=L;
            unsigned long long two = 0;
            int i=0;
            
            while(y<x)
            {
                ans+=L;
                two+=1;
                L=L&~two;
                i++;
                y++;
            }
        }
        cout << ans << endl;
    }
	return 0; 
} 
