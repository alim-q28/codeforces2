class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int x = 0;
        for(auto i : pref){
            ans.push_back(i^x);
            x = i;
        }
        return ans;
    }
};
