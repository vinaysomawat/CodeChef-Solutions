/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    int xxp=0;


    while(t--)
    {
        int n,t,totalsum=0;
        cin>>n;
        char c;
        int array[4][4];
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                array[i][j]=0;
        for(int i=0;i<n;i++){
            cin>>c>>t;
            array[(t/3)%4][c-'A']++;
        }
        int vector[4];
        int x,max1=-10000000;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i!=j)
                    for(int k=0;k<4;k++)
                        if(j!=k&&k!=i)
                            for(int l=0;l<4;l++)
                                if(l!=k&&l!=j&&l!=i)
                                {
                                    totalsum=0;
                                    vector[0]=array[0][i];
                                    vector[1]=array[1][j];
                                    vector[2]=array[2][k];
                                    vector[3]=array[3][l];
                                    sort(vector,vector+4,greater<int>());
                                    totalsum=100*vector[0]+75*vector[1]+50*vector[2]+25*vector[3];
                                    if(vector[0]==0)
                                        totalsum-=100;
                                    if(vector[1]==0)
                                        totalsum-=100;
                                    if(vector[2]==0)
                                        totalsum-=100;
                                    if(vector[3]==0)
                                        totalsum-=100;
                                    max1=max(max1,totalsum);
                                }
            }
        }
        xxp+=max1;
        cout<<max1<<endl;
    }
    cout<<xxp<<endl;
    return 0;
}