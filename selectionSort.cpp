#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *A,int n)
{
	for(int i=0;i<n;i++)
	{
		int min=INT_MAX,min_index;
		for(int j=i;j<n;j++)
		{
			if(min>A[j])
			{
				min=A[j];
				min_index=j;
			}
		}
		
		int temp=A[i];
		A[i]=min;
		A[min_index]=temp;
	}	
}

int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	selection_sort(A,n);	
	
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
		
	return 0;
}
