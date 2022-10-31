struct Trie{
    Trie *child[26];
    bool isleaf;
    Trie(){
        memset(child,0,sizeof(child));
        isleaf = 0;
    }
    void insert(char *ch){
        if(*ch == '\0')
            isleaf = 1;
        else{
            char c = *ch - 'a';
            if(child[c] == 0)
                child[c] = new Trie();
            child[c]->insert(ch+1);
        }
    }
    
    bool wordExist(char *ch){
        if(*ch == '\0')
            return isleaf;
        else{
            char c = *ch - 'a';
            if(child[c] == 0)
                return 0;
            return child[c]->wordExist(ch+1);
        }
    }
};
class Solution {
    vector<string> res;
public:
    vector<string> wordBreak(string word, vector<string>& wordDict) {
        Trie *root = new Trie();
        
        for(string s: wordDict)
            root->insert(&s[0]);
        vector<bool> dp(word.size()+1,0);
        dp[0] = 1;
        
        vector<pair<pair<int,int>,string>> intervals;
        for(int len = 1; len <= word.size(); len++){
            for(int i = 0; i < len; i++){
                string s = word.substr(i, len-i);
                if(dp[i] && root->wordExist(&s[0])){
                    intervals.push_back({{i,len},s});
                    dp[len] = true;
                }
            }
        }
        sort(intervals.begin(),intervals.end());
        dfs(0,intervals,"",word.size());
        return res;
    }
private:
    void dfs(int val,vector<pair<pair<int,int>,string>> &intervals,string s,int wordsize){
        if(val == wordsize){
            s.erase(0,1);
            res.push_back(s);
            return ;
        }
        for(int i = 0; i<intervals.size(); i++){
            if(intervals[i].first.first == val){
                dfs(intervals[i].first.second,intervals,s + ' ' + intervals[i].second, wordsize);
            }
        }
    }
};