
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct Trie{
    Trie* child[26];
    bool isLeaf;
    string word;
    Trie(){
        memset(child, 0, sizeof(child));
        isLeaf = 0;
    }
    
    void insert(char *str,string s){
        if(*str == '\0'){
            isLeaf = 1;
            word = s;
        }
        else{
            int cur = *str - 'a';
            if(child[cur] == 0)
                child[cur] = new Trie();
            child[cur]->insert(str+1,s);
        }
    }
};
class Solution {
public:
    vector<vector<char>>Board;
    bool visited[13][13];
    set<string> ans;
    int n,m;
    
    bool valid(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    void dfs(int i,int j,Trie *cur){
        if(cur->isLeaf){
            ans.insert(cur->word);
        }
        
        visited[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int r = dx[k] + i;
            int c = dy[k] + j;
            if(valid(r, c) && !visited[r][c] && cur->child[Board[r][c]-'a']){
                dfs(r, c, cur->child[Board[r][c]-'a']);
            }
        }
        visited[i][j] = 0;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        n = int(board.size());
        m = int(board[0].size());
        Board = board;
        
        for(string s: words){
            root->insert(&s[0],s);
        }
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(root->child[Board[i][j] - 'a']){
                    dfs(i, j, root->child[Board[i][j] - 'a']);
                }
            }
        }
        vector<string> ret = {ans.begin(), ans.end()};
        return ret;
    }
};