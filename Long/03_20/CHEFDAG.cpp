/* 
    Contest: CodeChef March 2020 Long challange
    Problem link: https://www.codechef.com/MARCH20B/problems/CHEFDAG
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/


#include<bits/stdc++.h>
#define ll long
#define bl bool
using namespace std;

//function1 calling

bl function1(vector < bl > * matrix, int u, bl watched[], int related[], int n) {
   for (int v = 0; v < n; v++) {
      if (matrix[u][v] && !watched[v]) {
         watched[v] = true;
         if ((related[v] < 0) || function1(matrix, related[v], watched, related, n)) {
            related[v] = u;
            return true;
         }
      }
   }
   return false;
}

// int stupidfuntion(const long long& m) { return m >= 0 ? m ? 1 : 0 : -1; }

// bool function2(long long a, long long b, long long c, long long d) {
//     if (a > b)
//         swap(a, b);
//     if (c > d)
//         swap(c, d);
//     return max(a, c) <= min(b, d);
// }

// bool stupidfunctionverify(const point& a, const point& b, const point& c, const point& d) {
//     if (c.xboxcheck(a, d) == 0 && c.xboxcheck(b, d) == 0)
//         return function2(a.m, b.m, c.m, d.m) && function2(a.z, b.z, c.z, d.z);
//     return stupidfuntion(a.xboxcheck(b, c)) != stupidfuntion(a.xboxcheck(b, d)) &&
//            stupidfuntion(c.xboxcheck(d, a)) != stupidfuntion(c.xboxcheck(d, b));
// }


//maxfunction1 calling
void maxfunction1(vector < bl > * matrix, int n) {
   int related[n];
   memset(related, -1, sizeof(related));
   for (int u = 0; u < n; u++) {
      bl watched[n];
      memset(watched, 0, sizeof(watched));
      function1(matrix, u, watched, related, n);
   }
//    for (int i = 0; i < n; i++)
//       outgoing[i] = 0;
//    for (int i = 0; i < n; i++) {
//       if (related[i] == -1)
//          continue;
//       outgoing[related[i]] = i + 1;
//    }
   int outgoing[n];
   for (int i = 0; i < n; i++)
      outgoing[i] = 0;
   for (int i = 0; i < n; i++) {
      if (related[i] == -1)
         continue;
      outgoing[related[i]] = i + 1;
   }
   //counting
   int count1 = 0;
   for (int i = 0; i < n; i++) {
      if (outgoing[i] == 0)
         count1++;
   }
   cout << count1 << "\n";
   for (int i = 0; i < n; i++)
      cout << outgoing[i] << " ";
   cout << "\n";
}

//main function here
//write your code here...
int main() {
   int t;
   cin >> t;
   while (t--) {
      int n, k;
      cin >> n >> k;
      int first[n];
      bl second[n][n], check[n][n];
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            second[i][j] = false;
            check[i][j] = false;
         }
      }
      for (int i = 0; i < k; i++) {
         for (int j = 0; j < n; j++)
            cin >> first[j];
         for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
               if (second[first[k] - 1][first[j] - 1] == true) {
                  second[first[k] - 1][first[j] - 1] = false;
                  check[first[j] - 1][first[k] - 1] = true;
                  check[first[k] - 1][first[j] - 1] = true;
               } else if (check[first[k] - 1][first[j] - 1] == false)
                  second[first[j] - 1][first[k] - 1] = true;
            }
         }
      }
    //   for (int i = 0; i < k; i++) {
    //      for (int j = 0; j < n; j++)
    //         cin >> first[j];
    //      for (int j = 0; j < n; j++) {
    //         for (int k = j + 1; k < n; k++) {
    //            if (second[first[k] - 1][first[j] - 1] == true) {
    //               second[first[k] - 1][first[j] - 1] = false;
    //               check[first[j] - 1][first[k] - 1] = true;
    //               check[first[k] - 1][first[j] - 1] = true;
    //            } else if (check[first[k] - 1][first[j] - 1] == false)
    //               second[first[j] - 1][first[k] - 1] = true;
    //         }
    //      }
    //   }
      vector < bl > matrix[n];
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (second[i][j] == true)
               matrix[i].push_back(true);
            else
               matrix[i].push_back(false);
         }
      }
      maxfunction1(matrix, n);
   }
   return 0;
}