int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
struct Trie{
    Trie *child[100];
    bool isleaf;
    Trie(){
        memset(child,0,sizeof(child));
        isleaf = 0;
    }
    
    void insert(char *s){
        if(*s == '\0')
            isleaf = 1;
        else{
            char ch = *s - 'A';
            if(child[ch] == 0)
                child[ch] = new Trie();
            child[ch]->insert(s+1);
        }
    }
};
class Solution {
public:
    bool check(int i,int j,int n,int m,Trie * cur,vector<vector<char>>& board,vector<vector<bool>>& visit){
        if(cur->isleaf)
            return 1;
        if(i == n && j == m){
            return 0;
        }
        visit[i][j] = 1;
        for(int k = 0; k<4; k++){
            int r = dx[k] + i;
            int c = dy[k] + j;
            
            if(r>= 0 && r<n && c>=0 && c<m &&  cur->child[board[r][c] - 'A'] && !visit[r][c]){
                if(check(r,c,n,m,cur->child[board[r][c] - 'A'],board,visit))
                    return 1;
            }
        }
        visit[i][j] = 0;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        Trie *root = new Trie();
        root->insert(&word[0]);
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> visit(n,vector<bool>(m,0));
        for(int i =0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(root->child[board[i][j]-'A']){
                    if(check(i,j,n,m,root->child[board[i][j]-'A'],board,visit))
                        return 1;
                }
            }
        }
        return 0;
    }
};