#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	int l;
	cin>>l;
	while(l!=-1)
	{
		v.push_back(l);
		cin>>l;
	}
	for(int i=0;i<v.size();i++)
	cout<<v.at(i)<<" ";
	cout<<endl;
	
	sort(v.begin(),v.end());      // sorts the vector
	for(int i=0;i<v.size();i++)
	cout<<v.at(i)<<" ";
	cout<<endl;
	
	cout << *max_element(v.begin()+1, v.end()-2)<<endl;  // returns max element in vector
	
	cout << *min_element(v.begin()+1, v.end()-2)<<endl;  // returns min element in vector
	
	cout << accumulate(v.begin(), v.end(),0);  // returns sum of all element and initial sum
}
