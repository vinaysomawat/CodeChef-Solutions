/* Problem link: https://www.codechef.com/AUG19B/problems/DSTAPLS
    Author: Vinay Somawat
    Webpage: http://vinaysomawat.github.io/
    Contest: CodeChef Auguest Long challange
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n>>k;
        if(k>n/k)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            if(n%(k*k)==0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }   
    }
    return 0;
}