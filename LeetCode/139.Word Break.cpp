

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(string s: wordDict){
            trie.insert(&s[0]);
        }
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int len = 1; len <= s.size(); len++){
            for(int i = 0; i < len; i++){
                if(dp[i] && trie.wordExist(&s.substr(i, len-i)[0])){
                    dp[len] = true;
                }
            }
        }
        return dp[s.size()];
    }
private:
    struct Trie{
        Trie* child[26];
        bool isLeaf;

        Trie(){
            memset(child, 0, sizeof(child));
            isLeaf = 0;
        }

        void insert(char *str){
            if(*str == '\0'){
                isLeaf = 1;
            }
            else{
                int cur = *str - 'a';
                if(child[cur] == 0)
                    child[cur] = new Trie();
                child[cur]->insert(str+1);
            }
        }
        bool wordExist(char *str){
            if(*str == '\0'){
                return isLeaf;
            }
            int cur = *str - 'a';
            if(child[cur] == 0)
                return false;
            return child[cur]->wordExist(str+1);
        }
    };
};