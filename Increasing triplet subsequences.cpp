class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), mn = 0;
        vector<int> v(n);
        for(int i=1;i<n;i++){
            if(nums[i] > nums[mn]) v[i] = mn;
            else mn = i;
        }
        int mx = n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[mx] > nums[i] and nums[i] > nums[v[i]]) return true;
            if(nums[mx] <= nums[i]) mx = i;
        }
        return false;
    }
};
