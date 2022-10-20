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
    int t,a,b,c,n;
    cin>>t;
    vector<vector<int>> arr(10000,vector<int> (2,0));
    inc(i,0,t)
    {
        cin>>a>>b>>c;
        n=2*abs(a-b);
        if(n>=a && n>=b)
        {arr[i][0]=n;
        arr[i][1]=c;}
        else
        {
            arr[i][0]=0;
            arr[i][1]=c;
        }
    }
    inc(i,0,t){
        if(arr[i][0]>=arr[i][1]){
            if(arr[i][0]>=2*arr[i][1])
            cout<<arr[i][0]/2 + arr[i][1]<<endl;
            else
            cout<<arr[i][1]-arr[i][0]/2<<endl;
        }
        else
        cout<<"Cant be done"<<endl;
    }
    return 0;
}
