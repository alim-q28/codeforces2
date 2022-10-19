#include<bits/stdc++.h>
using namespace std;

int BinSearch(int*A,int n,int x)
{
	int l=0,h=n,m;
	while(l<=h)
	{
		m=(l+h)/2;
		if(A[m]==x)
		return 1;
		else
		{
			if(A[m]>x)
			{
				h=m-1;
			}
			else if(A[m]<x)
			{
				l=m+1;
			}
		}
	}
	return -1;
	
}

int main()
{
	int n;
	int m;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
	cin>>A[i];
	int x;
	cin>>x;
	cout<<BinSearch(A,n,x);
	
	return 0;
}
