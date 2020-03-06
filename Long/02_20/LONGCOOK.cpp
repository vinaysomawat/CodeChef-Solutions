/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com

*/

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	    ll t1,t2,temp;
        ll p=1,cnt=0,f=0;
        ll k1,k2,c,temp2;
        cin>>t1>>k1;
        cin>>t2>>k2;
        if(t1 > 2)
            k1 = k1 + 1;

        if(t2 == 1)
            k2 = k2 - 1;

        int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
        int exe,exe1,exe2,ptr,ptr1,ptr2;
        exe1 = k1;ptr2=k2;
        if(k1 % 400 == 0){
            ptr1 = k1;
            ptr = k1;
        }
        else{
            ptr = ((k1/400)+1)*400;
            ptr1 = k2;
            if(k2-k1 >=400){
                f = 1;
                if(k1 % 400 <= 100){
                    cnt = cnt + 76;
                    ptr1 = (k1/400)*400 + 100;
                } 
                else if(k1 % 400 <= 200){
                    cnt = cnt + 52;
                    ptr1 = (k1/400)*400 + 200;
                }
                else if(k1 % 400 <= 300){
                    cnt = cnt + 26;
                    ptr1 = (k1/400)*400 + 300;
                }
            }
        }

        if(k2 % 400 == 0){
            exe2 = k2;
            exe = k2;
        }
        else {
            exe = ((k2/400)*400);
            exe2 = k2;
            if(k2-k1 >=400){
                if(k2 % 400 >= 300){
                    exe2 = (k2/400)*400 ;
                }
                else if(k2 % 400 >= 200){
                    exe2 = (k2/400)*400 ;
                }
                else if(k2 % 400 >= 100){
                    exe2 = (k2/400)*400 ;
                }
            }
        }

        temp2 = exe1;
        while(temp2 < ptr1){
            c = temp2;
            c -= 2 < 3;
            temp = ( c + (c/4) - (c/100) +  (c/400) + t[1] + p) % 7;
            
            if(temp == 0 && ((temp2%4 == 0 && temp2%100 != 0) || (temp2%400 == 0)) == false)
                cnt++;
 
            else if(temp == 6)
                cnt++;
            temp2++;           
        }

        temp2 = exe2;
        while(temp2 <= ptr2){
            c = temp2;
            c -= 2 < 3;
            temp = ( c + (c/4) - (c/100) +  (c/400) + t[1] + p) % 7;
            
            if(temp == 0 && ((temp2%4 == 0 && temp2%100 != 0) || (temp2%400 == 0)) == false)
                cnt++;
 
            else if(temp == 6)
                cnt++;
            temp2++;           
        }
        if(f == 1)
            cnt = cnt + ((exe-ptr)/400)*101;

        cout<<cnt<<"\n";
}

int main() {
	long int T;
	cin>>T;
	while(T--){
        solve();
	}
	return 0;
}