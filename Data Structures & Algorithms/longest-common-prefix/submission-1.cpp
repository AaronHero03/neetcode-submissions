class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans;
        int n = strs.size();
        int s = min(strs[0].size(), strs[n-1].size());
        for(int i = 0; i < s; i++){
            if(strs[0].at(i) == strs[n-1].at(i)){
                ans += strs[0].at(i);
            } else {
                return ans;
            }  
        }
        return ans;
    }
};