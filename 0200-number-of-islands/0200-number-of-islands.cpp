class Solution {
public:
   vector<int>rows={-1,1,0,0};
   vector<int>col={0,0,-1,1};
   int n,m;
   vector<vector<int>>vis;

    void dfs(int i ,int j,vector<vector<char>>& grid){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int new_row=i+rows[k];
            int new_col=j+col[k];

            if(new_row>=0 && new_row<n && new_col<m && new_col>=0 && vis[new_row][new_col]==0 && grid[new_row][new_col]=='1'){
                dfs(new_row,new_col,grid);
            }
        }

        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();

         vis.resize(n,vector<int>(m,0));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    dfs(i,j,grid);
                }
                
            }
        }

        return ans;
        
    }
};