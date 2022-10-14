class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp;
    long long solve(int i,int j,int sum,vector<vector<int>> &grid,int k){
        if(i >= grid.size() or j >= grid[0].size()) return 0;
        if(i == grid.size()-1 and j == grid[0].size()-1){
            int s = sum+grid[i][j];
            return s % k == 0;
        }
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        long long op1 = solve(i+1,j,(sum+grid[i][j]) % k,grid,k);
        long long op2 = solve(i,j+1,(sum+grid[i][j]) % k,grid,k);
        
        return dp[i][j][sum] = (op1 + op2) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        dp.resize(m+1, vector<vector<long long>> (n+1, vector<long long> (k+1,-1)));
        return solve(0,0,0,grid,k);
    }
};
