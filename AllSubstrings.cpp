#include<bits/stdc++.h>
using namespace std;

int subsequence(string input,string output[])
{
	if(input.empty())
	{
		output[0]="";
		return 1;
	}
	
	else
	{
		string smallstring= input.substr(1);
		int smalloutput_size =subsequence(smallstring,output);
		for(int i=0;i<smalloutput_size;i++)
		{
			output[i+smalloutput_size]=input[0]+output[i];
		}
		return 2*smalloutput_size;
	}
}

int main()
{
	string input;
	string caps;
	cin>>input;					   // Input is a string
	int n=pow(2,input.size());									 
	string *output=new string[n];  // Output is a string array 
	int count = subsequence(input,output);
	
	for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}
