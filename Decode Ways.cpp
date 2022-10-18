class Solution {
public:
    
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || (s[0] == '0')) { return 0; } 
        int dp[n+1] = {0};
        // For 0 size string (helper)
        dp[0] = 1;
        // For 1 size string if s[0] != '0'
        dp[1] = 1;
        for(int i = 1;i<n;i++) {
            if(s[i] != '0') {
                dp[i+1] += dp[i];
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                    dp[i+1] += dp[i-1];
            }
            else {
                if(s[i-1] == '1' || s[i-1] == '2')
                    dp[i+1] += dp[i-1];
                else
                    break;
            }
        }
        return dp[n];
    }
};
