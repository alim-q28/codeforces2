#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inc(i,a,b) for(int i=a;i<=b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
int main()
{
    int c,a,j=1;
    cin>>t;
    int arr[1000];
    vector<int> ks;
    inc(i,0,c)
    {
        cin>>a;
        ks.pb(a);
    }
    int k=0;
    while(k<1000){
        if((j%3 != 0) && (j%10 !=3))
        {
            arr[k]=j;
            k++;
        }
        j++;
    }
    inc(i,0,c){
        cout<<arr[ks[i]-1]<<endl;
    }
    return 0;
}
