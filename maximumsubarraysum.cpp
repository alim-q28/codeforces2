#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>b;i--)
int main()
{
    int best =0,sum = 0,n,a;
    vector<int> arr;
    cin>>n;
    inc(i,0,n){
        cin>>a;
        arr.push_back(a);
    }
    inc(k,0,n){
        sum = max(arr[k],sum+arr[k]);
        best = max(best,sum);
    }
    cout<<best<<"\n";
    return 0;
}