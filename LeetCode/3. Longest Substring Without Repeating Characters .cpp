class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,bool>mp;
        int l = 0, r = 0,cnt = 0, mx = 0;
        while(l<=r){
            while(r<s.size() && mp[s[r]] == false){
                mp[s[r++]] = true;
            }
            mx = max(mx,r-l);
            mp[s[l++]] = false;
        }
        return mx;
    }
};