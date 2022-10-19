#include<bits/stdc++.h>
using namespace std;

int BinSearch(int *p,int n,int key)
{
	int l=1,h=n,mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==p[mid])
		return 1;
		else if(key<p[mid])
		h=mid-1;
		else
		l=mid+1;
	}
	return 0;
}

int main()
{
	int n;
	cout<<"Enter Size ";
	cin>>n;
	int *p=new int[n+1];
	p[0]=0;
	cout<<"Enter elements ";
	for(int i=1;i<n+1;i++)
	{
		cin>>p[i];
	}
	int key;
	cout<<"Enter key ";
	cin>>key;
	int c = BinSearch(p,n+1,key);
	if(c==1)
	cout<<"Search Successfull";
	else
	cout<<"Search Unsuccessfull";
	
	return 0;	
}
