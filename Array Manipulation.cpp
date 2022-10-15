#include <bits/stdc++.h>
#define ld long double 
using namespace std;

int main(){
   long int n,m;
    cin>>n>>m;
    long int *arr=new long int[n+1]();
while (m--)
{
    int a,b,k;
    cin>>a>>b>>k;
        arr[a] += k;
        if(b <n ){
            arr[b+1] -= k;
        }
}
long int max = 0; m = 0;
for(long int i = 0 ; i<= n ; i++){
    m += arr[i];
    if(m > max) max = m;
}
cout<<max<<endl;

return 0;
}
