struct TrieNode
{
    TrieNode *child[26] = {};
    int curIndex = -1;
    vector<int> wordIndex;
};
class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index)
    {
        TrieNode *cur = root;
        for (int i = int(s.size())-1; i>=0; i--) {
            int ch = s[i] - 'a';
            if(cur->child[ch] == nullptr)
                cur->child[ch] = new TrieNode();
            if(isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[ch];
        }
        cur->curIndex = index;
        cur->wordIndex.push_back(index);
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i<int(words.size()); i++) {
            TrieNode *cur = root;
            for (int j = 0; j<int(words[i].size()); j++) {
                if(cur->curIndex != -1 && cur->curIndex != i &&
                   isPalindrome(words[i], j,int(words[i].size())-1)){
                    ans.push_back({i,cur->curIndex});
                }
                cur = cur->child[words[i][j] - 'a'];
                if(cur == nullptr)
                    break;
            }
            if(cur == nullptr)
                continue;
            for(auto j: cur->wordIndex){
                if(i != j)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};