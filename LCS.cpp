#include<bits/stdc++.h>
using namespace std;

int LCSlen(string s1,string s2)
{
	int n = s1.size(), m = s2.size();
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

string LCS(string s1,string s2)
{
	int n = s1.size(), m = s2.size();
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	int id = dp[n][m], i = n, j = m;
	char lcs[id+1];
	lcs[id] = '\0';
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
			lcs[id-1] = s1[i-1];
			i--; j--; id--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}
	//cout<<lcs<<endl;
	return lcs;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int len = LCSlen(s1,s2);
	cout<<len<<endl;
	string res = LCS(s1,s2);
	cout<<res<<endl;
	return 0;
}
