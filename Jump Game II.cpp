#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0 , limit = 0 , next_limit = 0;
        for(int i = 0;i < nums.size()-1;i++){
            next_limit = max(next_limit,i+nums[i]);
            if(i == limit){
                jumps++;
                limit = next_limit;
            }
        }
        return jumps;
    }
};
