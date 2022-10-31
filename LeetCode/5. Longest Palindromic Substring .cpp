class Solution {
public:
    string longestPalindrome(string s) {
       
        pair<int,int> mx = {0,0};
        for(int i = 0; i<s.size(); i++){
            int l = i, r = i;
             while(l>=0 && r<s.size() && s[l] == s[r]){
                if(r-l > mx.second - mx.first){
                    mx = {l,r};
                }
                l--;r++;
            }
            l = i, r = i+1;
            while(l>=0 && r<s.size() && s[l] == s[r]){
                if(r-l > mx.second - mx.first){
                    mx = {l,r};
                }
                l--,r++;
            }
        }
        string ans = "";
        for(int i = mx.first; i<=mx.second; i++)
            ans += s[i];
        return ans;
    }
};