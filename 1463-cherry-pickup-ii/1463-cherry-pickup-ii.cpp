class Solution {
public:
   //reduced to the 3d dp as i and k will always be same as we are always moving one row down for both the robots
    vector<int>row={1,1,1};
    vector<int>col={-1,0,1};
    int dp[70][70][70];
    int n,m;
    int solve(int i,int j,int l,vector<vector<int>>&grid){
        int k=i;
        if(dp[i][j][l]!=-1)return dp[i][j][l];
        int cherries=(i==k && j==l)?(grid[i][j]):(grid[i][j]+grid[k][l]);
        int path=0;
        for(int d1=0;d1<3;d1++){
            for(int d2=0;d2<3;d2++){
                int i1=i+row[d1];
                int j1=j+col[d1];
                int k1=k+row[d2];
                int l1=l+col[d2];

                if(i1>=0 && i1<n && j1>=0 && j1<m && k1>=0 && k1<n && l1>=0 && l1<m){
                     path=max(path,solve(i1,j1,l1,grid));
                }
            }
        }
        return dp[i][j][l]=(cherries+path); 
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));

        int ans=solve(0,0,m-1,grid);
        return ans;
    }
};