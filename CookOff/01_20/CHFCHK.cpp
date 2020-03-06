/* Problem link: https://www.codechef.com/COOK114B/problems/CHFCHK
    Author: Vinay Somawat
    Webpage: http://vinaysomawat.github.io/
    Contest: CodeChef January Cook Off Challange
*/


#include<bits/stdc++.h>
#define ll long long int
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
        sort(a,a+n);
        int ans = a[0];
        cout<<ans<<endl;
    }
    return 0;
}