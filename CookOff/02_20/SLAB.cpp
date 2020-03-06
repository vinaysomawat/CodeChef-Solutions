/* Problem link: https://www.codechef.com/COOK115B/problems/SLAB
    Author: Vinay Somawat
    Webpage: http://vinaysomawat.github.io/
    Contest: CodeChef February Cook Off Challange
*/

#include<iostream>
using namespace std;


int main()
{
    int n,t,c,i;
    cin>>t;
    while(t--)
    {
       cin>>n;
       n/=100;
        c=i=0;
        while(n>0 && i<6)
        {
            if(n>2500)
                c+=2500*(100-i*5);
            else
                c+=n*(100-i*5);
            n -= 2500;i++;
        }
        if(n>0) c+=n*70;
        cout<<c<<endl; 
    }
    return 0;
}