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
    int t;
    cin>>t;

    while(t--) {
        int k;
        cin>>k;

        int i = 1;

        while(true) {
            if(i%3==0 || (i%10==3)) {
                i++;
                continue;
            }

            else {
                --k;

                if(k==0)
                {
                    cout<<i<<"\n";
                    break;
                }
                i++;
            }
        }
    }
    return 0;
}
