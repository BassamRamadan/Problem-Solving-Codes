
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *root = new Trie();
        for(string s: words)
            root->insert(&s[0]);
        
        vector<string> res;
        
        bool dp[31];
        for(string s: words){
            memset(dp,0,sizeof(dp));
            dp[0] = 1;
            
            for(int len = 1; len <= s.size(); len++){
                for(int i = 0; i < len; i++){
                    if(i == 0 && len == s.size()) continue;
                    if(dp[i] && root->wordExist(&s.substr(i,len-i)[0])){
                        dp[len] = 1;
                    }
                }
            }
            if(dp[s.size()]){
                res.push_back(s);
            }
        }
        return res;
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