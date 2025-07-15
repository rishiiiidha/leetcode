class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxi = 0;
        unordered_map<char,int>mp;
        while (r < n) {
            if (mp.find(s[r]) == mp.end()) {
                mp[s[r]] = r;
            } else {
                int k = mp[s[r]];
                if (k >= l)
                    l = k + 1;
                mp[s[r]] = r;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};