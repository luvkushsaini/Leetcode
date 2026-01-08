class Solution {
public:
vector<int>rows={-1,1,0,0};
vector<int>col={0,0,-1,1};
vector<vector<int>>vis;
int n,m;

    void fill(int i,int j,vector<vector<char>>& board){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int newr=i+rows[k];
            int newc=j+col[k];

            if(newr<n && newr>=0 && newc<m && newc>=0 && vis[newr][newc]!=1 && board[newr][newc]=='O'){
                fill(newr,newc,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
           n=board.size();
           m=board[0].size();
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O')fill(i,0,board);
            if(vis[i][m-1]==0 && board[i][m-1]=='O')fill(i,m-1,board);
        }
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && board[0][i]=='O')fill(0,i,board);
            if(vis[n-1][i]==0 && board[n-1][i]=='O')fill(n-1,i,board);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0)board[i][j]='X';
            }
        }
    }
};