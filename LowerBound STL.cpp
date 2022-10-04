#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() 
{
    vector<int> v;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int input;
        cin>>input;
        v.push_back(input);
    }  
    int q;
    cin>>q;
    for(int j=0; j<q; j++)
    {
      int query;
      cin>>query;
  auto it1=lower_bound(v.begin(), v.end(), query);
 int index1=it1-v.begin();
    // If element was found
    if (*it1==query)
    {
        cout << "Yes "<<index1+1 << endl;
    }
    else {
             cout<<"No "<<index1+1<<endl;
        
         }  
        }
    return 0;
}
