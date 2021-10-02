#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p;
    cin>>n;
    vector<int> inputs(n,0),left_arr(n,0),outputs(n,0);
    for(int i =0;i<n;i++)
    {
        cin>>inputs[i];
    }
    p=1;
    left_arr[0]=1;
    for(int i=1;i<n;i++){
        p=p*inputs[i-1];
        left_arr[i]=p;
    }
    vector<int> right_arr(n,0);
    p=1;
    right_arr[n-1]=1;
    for(int i=n-2;i>=0;i--){
        p=p*inputs[i+1];
        right_arr[i]=p;
    }
    for(int i=0;i<n;i++){
        outputs[i]=left_arr[i]*right_arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<outputs[i]<<" ";
    }
    return 0;
}
