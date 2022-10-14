class Solution {
public:
    string robotWithString(string s) {
        string ans, temp;
        
        vector<vector<int>> v(26);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a'].push_back(i);
        }
        
        int j = 0;
        for(int i=0;i<26;i++){
            if(v[i].empty()) continue;
            while(temp.size() and temp.back() <= char(i+'a')){
                ans += temp.back(); temp.pop_back();
            }
            while(j <= v[i].back()){
                auto lb = lower_bound(v[i].begin(),v[i].end(),j);
                if(*lb == j) ans += s[j++];
                else temp += s[j++];
            }
            
        }
        
        
        for(int i=temp.size()-1;i>=0;i--) ans += temp[i];
        return ans;
    }
};
