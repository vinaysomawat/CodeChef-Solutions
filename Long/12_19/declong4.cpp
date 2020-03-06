#include<bits/stdc++.h>
using namespace std;
int main()
{
int i,k,count,t;
char A[2000001],B[2000001];
int a,b,u,v;
scanf("%d",&t);
while(t--)
{
    int sum;
    a=0; b=0;
    fflush(stdin);
    cin>>A;
    fflush(stdin);
    cin>>B;
    for(i=0;i<strlen(A);i++)
    {
        a=a*2+A[i]-48;
    }
    //cout<<"a="<<a<<endl;
    for(i=0;i<strlen(B);i++)
    {
        b=b*2+B[i]-48;
    }
    sum=a+b;
    //cout<<"b="<<b<<endl;
    for(k=0;b>0;k++)
    {
        u=a^b;
        a=u;
        b=sum-a;
        //cout<<a<<b<<endl;
    }   
    cout<<k<<endl;    
}
return 0;
}
