#include<bits/stdc++.h>
using namespace std;

struct Interval  
{  
    int s, e;  
}; 

bool mycomp(Interval a, Interval b)  
{ return a.s < b.s; } 

void mergeIntervals(Interval arr[], int n)  
{  
    sort(arr, arr+n, mycomp);  
  
    int index = 0; 
    int cnt=0;
    vector<int> v;
  
    for (int i=1; i<n; i++)  
    {   
        if (arr[index].e >=  arr[i].s)  
        {   
           // cout<<arr[index].e<<" "<<arr[i].s<<endl;
            int diff =arr[index].e - arr[i].s;
            arr[index].e = max(arr[index].e, arr[i].e);  
            arr[index].s = min(arr[index].s, arr[i].s); 
            //cout<<"diff_s: "<<arr[i].s - arr[index].s<<endl;
            v.push_back(diff);
            //cout<<"diff: "<<diff<<endl;
        }  
        else { 
            arr[index] = arr[i];  
            index++; 
        }     
    }  
    //cout<<"count: "<<cnt<<endl;
   //  int minn=INT_MAX;
   //  for(int i=0;i<v.size(); i++)
   //  {
   //  	if(minn>v[i])
   //  	{
   //  		minn=v[i];
   //  	}
   //  }
  	// if(index>0)
  	// {
  	// 	cout<<"0"<<endl;
  	// }
  	// else 
  	// {
  	// 	//cout<<"minnn: "<<minn<<" n: "<<n<<endl;
  	// 	if(minn<n-1 && minn>0)
  	// 	{
  	// 		cout<<minn<<endl;
  	// 	}
  	// 	else
  	// 	{
  	// 		cout<<"-1"<<endl;
  	// 	}
  	// }
  	
    cout << "\n The Merged Intervals are: ";  
    for (int i = 0; i <= index; i++)  
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";  
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Interval a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i].s>>a[i].e;
		}
		mergeIntervals(a,n);
	}
}