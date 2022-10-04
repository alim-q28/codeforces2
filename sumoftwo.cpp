#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>b;i--)
using namespace std;
int main()
{
    unordered_set<int> alternate;
    int m,n,value;
    cin>>m>>n;
    vector<int> a(m,0),b(n,0);
    inc(i,0,m)
        cin>>a[i];
    inc(i,0,n)
        cin>>b[i];
    cin>>value;
    inc(i,0,m){
        alternate.insert(value-a[i]);
    }
    for(int i;i<n;i++){
        if(alternate.count(b[i])){
            cout<<"Found!!!"<<endl;
            return 0;
        }
    }
    cout<<"Not Found!!!"<<endl;
    return 0;
}
