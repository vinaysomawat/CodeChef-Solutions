/* 
    Contest: CodeChef APRIL 2020 LONG Challange DIV 1
    Problem link:https://www.codechef.com/APRIL20A/problems/REBIT
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long 
#define MOD 998244353
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

  
/* This fuction is taken from geeksforgeeks */

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    else
        return gcd(b, a%b);
}  

/* This fuction is taken from geeksforgeeks */

ll gcdExtended(ll a, ll b, ll *x, ll *y)  
{  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}  



vector<vector< ll> > Calc_postfix(string s)
{
    vector<ll > vectnum;
    ll number;
    number = 748683265;
    for(ll i = 0; i < 4; i++)vectnum.push_back(number);
    vector<vector<ll > > answer;
    vector<ll> R, andvect, xorvect;
    R.push_back(1);andvect.push_back(2);xorvect.push_back(3);
    stack<char> buffer;
    for(ll n  = 0 ; n < s.size(); n++)
    {
        if(s[n] == '#')
        {
            answer.push_back(vectnum);
            continue;
        }
        if(s[n] == ')')
        {
            while(buffer.top() != '(')
            {
                if(buffer.top() == '|')
                {
                    answer.push_back(R);
                }
                else if(buffer.top() == '&')
                {
                    answer.push_back(andvect);
                }
                else if(buffer.top() == '^')
                {
                    answer.push_back(xorvect);
                }
                buffer.pop();
            }
            buffer.pop();
        }
        else if(s[n] == '(' || buffer.empty() || buffer.top() == '(')
        {
            buffer.push(s[n]);
        }
        else 
        {
            if(buffer.top() == '|')
            {
                answer.push_back(R);
            }
            else if(buffer.top() == '&')
            {
                answer.push_back(andvect);
            }
            else if(buffer.top() == '^')
            {
                answer.push_back(xorvect);
            }
            buffer.pop();
            buffer.push(s[n]);
        }
    }
    while(!buffer.empty())
    {
        if(buffer.top() == '|')
            answer.push_back(R);
        else if(buffer.top() == '&')
            answer.push_back(andvect);
        else if(buffer.top() == '^')
            answer.push_back(xorvect);
        buffer.pop();
    }
    return answer;
}

ll additionbit(ll a, ll  b)
{
   return (a+b)%MOD;
}

ll multiplybit(ll a, ll b)
{
   return (a*b)%MOD;
}

vector<ll> oroperation(vector<ll > a, vector<ll > b)
{
    vector<ll > answer(4);
    ll buffer;
    ll count1;
    answer[0] = (a[0]* b[0]) %MOD;
    count1 = b[0];
    for(ll n = 1; n < 4; n++)
    {
        count1 = additionbit(count1, b[n]);
    }
    count1 = multiplybit(count1, a[1]);

    ll count2 = a[0];
    count2 = additionbit(count2, a[2]);
    count2 = additionbit(count2, a[3]);
    count2 = multiplybit(count2, b[1]);

    ll count3 = multiplybit(a[2], b[3]);

    ll count4 = multiplybit(a[3], b[2]);

    buffer = count1;
    buffer = additionbit(count1, count2);
    buffer = additionbit(buffer, count3);
    buffer = additionbit(buffer, count4);

    answer[1] = buffer;

    count1 = multiplybit(a[0], b[2]);
    count2 = multiplybit(a[2], b[0]);
    count3 = multiplybit(a[2], b[2]);

    buffer = count1;
    buffer = additionbit(count1, count2);
    buffer = additionbit(buffer, count3);

    answer[2] =buffer;

    count1 = multiplybit(a[0], b[3]);
    count2 = multiplybit(a[3], b[0]);
    count3 = multiplybit(a[3], b[3]);

    buffer = count1;
    buffer = additionbit(count1, count2);
    buffer = additionbit(buffer, count3);

    answer[3] = buffer;

    return answer;
}


vector<ll > andoperation(vector<ll > a, vector<ll > b)
{
    vector<ll > answer(4);
    ll buffer;
    ll count1;
    answer[1] = multiplybit(a[1], b[1]);

    count1 = b[0];
    for(ll n = 1; n < 4; n++)
    {
        count1 = additionbit(count1, b[n]);
    }
    count1 = multiplybit(count1, a[0]);

    ll count2;
    count2 = a[1];
    count2 = additionbit(count2, a[2]);
    count2 = additionbit(count2, a[3]);
    count2 = multiplybit(count2, b[0]);

    ll count3;
    count3 = multiplybit(a[2], b[3]);

    ll count4;
    count4 = multiplybit(a[3], b[2]);

    buffer = count1;
    buffer = additionbit(count1, count2);
    buffer = additionbit(buffer, count3);
    buffer = additionbit(buffer, count4);

    answer[0] = buffer;

    count1 = multiplybit(a[1], b[2]);
    count2 = multiplybit(a[2], b[1]);
    count3 = multiplybit(a[2], b[2]);

    buffer = count1;
    buffer = additionbit(count1, count2);
    buffer = additionbit(buffer, count3);

    answer[2] = buffer;

    count1 = multiplybit(a[1], b[3]);
    count2 = multiplybit(a[3], b[1]);
    count3 = multiplybit(a[3], b[3]);

    buffer = count1;
    buffer = additionbit(count1, count2);
    buffer = additionbit(buffer, count3);

    answer[3] = buffer;

    return answer;
}

vector<ll > xoroperation(vector<ll > a, vector<ll > b)
{
    ll buffer;
    ll count1, count2, count3, count4;
    vector<ll > answer(4);
    
    count1 = multiplybit(a[0], b[0]);
    count2 = multiplybit(a[1], b[1]);
    count3 = multiplybit(a[2], b[2]);
    count4 = multiplybit(a[3], b[3]);
    buffer = count1;
    buffer = additionbit(buffer, count2);
    buffer = additionbit(buffer, count3);
    buffer = additionbit(buffer, count4);

    answer[0] = buffer;

    count1 = multiplybit(a[0], b[1]);
    count2 = multiplybit(a[1], b[0]);
    count3 = multiplybit(a[2], b[3]);
    count4 = multiplybit(a[3], b[2]);
    buffer = count1;
    buffer = additionbit(buffer, count2);
    buffer = additionbit(buffer, count3);
    buffer = additionbit(buffer, count4);

    answer[1] = buffer;


    count1 = multiplybit(a[0], b[2]);
    count2 = multiplybit(a[1], b[3]);
    count3 = multiplybit(a[2], b[0]);
    count4 = multiplybit(a[3], b[1]);
    buffer = count1;
    buffer = additionbit(buffer, count2);
    buffer = additionbit(buffer, count3);
    buffer = additionbit(buffer, count4);

    answer[2] = buffer;

    count1 = multiplybit(a[0], b[3]);
    count2 = multiplybit(a[1], b[2]);
    count3 = multiplybit(a[2], b[1]);
    count4 = multiplybit(a[3], b[0]);
    buffer = count1;
    buffer = additionbit(buffer, count2);
    buffer = additionbit(buffer, count3);
    buffer = additionbit(buffer, count4);
    
    answer[3] = buffer;

    return answer;
}

void solve()
{

    string str;
    cin>>str;
    vector<vector<ll > >  prefix = Calc_postfix(str);
    stack<vector<ll > > stk;
    vector<ll > element;
    for(ll n = 0; n < prefix.size(); n++)
    {
        element = prefix[n];
        if(element.size() == 4)
        {
            stk.push(element);
        }
        else if(element.size() == 1)
        {
            vector<ll > a, b, c;
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            if(element[0] == 1)
                c = oroperation(a, b);
            if(element[0] == 2)
                c = andoperation(a, b);
            if(element[0] == 3)
                c = xoroperation(a, b);
            stk.push(c);
        }
    }
    element = stk.top();
    vector<ll> answer(4);
    for(ll i = 0; i < 4; i++)
    {
        answer[i] = ((element[i]))%MOD;
        cout<<answer[i]<<" ";
    }
    cout<<"\n";
}

int main()  
{  
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}  