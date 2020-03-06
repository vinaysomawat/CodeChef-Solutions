#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
  
// Returns the Most Significant Bit 
// Position (MSB) 
int MSBPosition(long long int N) 
{ 
    int msb_p = -1; 
    while (N) { 
        N = N >> 1; 
        msb_p++; 
    } 
    return msb_p; 
} 
  
// Returns the Bitwise OR of all 
// integers between L and R 
long long int findBitwiseOR(long long int L, 
                            long long int R) 
{ 
    long long int res = 0; 
  
    // Find the MSB position in L 
    int msb_p1 = MSBPosition(L); 
  
    // Find the MSB position in R 
    int msb_p2 = MSBPosition(R); 
  
    while (msb_p1 == msb_p2) { 
        long long int res_val = (1 << msb_p1); 
  
        // Add this value until msb_p1 and 
        // msb_p2 are same; 
        res += res_val; 
  
        L -= res_val; 
        R -= res_val; 
  
        // Calculate msb_p1 and msb_p2 
        msb_p1 = MSBPosition(L); 
        msb_p2 = MSBPosition(R); 
    } 
    // Find the max of msb_p1 and msb_p2 
    msb_p1 = max(msb_p1, msb_p2); 
  
    // Set all the bits from msb_p1 upto 
    // 0th bit in the result 
    for (int i = msb_p1; i >= 0; i--) { 
        long long int res_val = (1 << i); 
        res += res_val; 
    } 
    return res; 
} 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        ll L, R;
        cin>>L>>R;
        cout << findBitwiseOR(L, R) << endl; 
    }
    return 0; 
} 