#include<bits/stdc++.h>
using namespace std;

int BinSearch(int *p,int l,int h,int key)
{
	int mid=(l+h)/2;
	if(l==h)
	{
		if(p[l]==key)
		return 1;
		else
		return 0;
	}
	
	else
	{
		if(key==p[mid])
		return 1;
		if(key<p[mid])
		return BinSearch(p,l,mid-1,key);
		else
		return BinSearch(p,mid+1,h,key);
	}
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
	
	int c = BinSearch(p,1,n+1,key);
	
	if(c==1){
	cout<<"Search Successfull";
	else
	cout<<"Search Unsuccessfull";
	}
	
	return 0;	
}
