#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector < pair < char, vector < int >> > vt;
        for (int i = 0; i < n; i++) {
            char ch = str[i];
            int q = 0;
            int ind;
            if(vt.size())
            {
                for (int j = 0; j < vt.size(); j++) {
                    if (vt[j].first == ch) {
                        q = 1;
                        ind = j;
                        break;
                    }
                }
            }
            if (q) {
                vt[ind].second.push_back(i);
            } else {
                pair < char, vector < int >> p;
                p.first = ch;
                vector < int > temp;
                temp.push_back(i);
                p.second = temp;
                vt.push_back(p);
            }
        }
        // vector < int > finalvector;
        // for (int i = 0; i < vt.size(); i++) {
        //     vector <int> tempvt;
        //     if (vt[i].second.size() > 1) {
        //         for (int j = 1; j < vt[i].second.size(); j++) {
        //             int diff = vt[i].second[j] - vt[i].second[j - 1];
        //             tempvt.push_back(diff);
        //         }
        //         int min = *min_element(tempvt.begin(), tempvt.end());
        //         finalvector.push_back(min);
        //     }
        // }

        // int ans = *min_element(finalvector.begin(), finalvector.end());

        int minn=INT_MAX;
        for(int i=0;i<vt.size();i++)
        {
            if(vt[i].second.size()>1)
            {
                for(int j=1;j<vt[i].second.size();j++)
                {
                    minn=min(minn,(vt[i].second[j]-vt[i].second[j-1]));
                }
            }
        }
        if(minn==INT_MAX)
            cout<<0<<endl;
        else
            cout << n - minn << endl;
    }
    return 0;
}