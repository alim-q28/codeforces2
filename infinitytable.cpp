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
    int q,t,k;
    vector<int> x;
    cin>>q;
    inc(i,0,q){
        cin>>k;
        x.push_back(k);
    }
    for(int i=0;i<q;i++){
        if(sqrt(x[i]) == int(sqrt(x[i]))){
            cout<<int(sqrt(x[i]))<<" "<<1<<endl;
        }
        else{
            t=int(sqrt(x[i]));
            int j=x[i]-t*t;
            if(j<=t+1){
                cout<<j<<" "<<t+1<<endl;
            }
            else{
                cout<<t+1<<" "<<2*t+2-j<<endl;
            }
        }
    }
    return 0;
}
