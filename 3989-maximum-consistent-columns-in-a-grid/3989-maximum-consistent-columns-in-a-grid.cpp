class Solution {
public:
    int n,m;
    int dp[251][252];

    bool check(int prev,int i,vector<vector<int>>& grid, int limit){
       for(int r=0;r<n;r++){
        if(abs(grid[r][prev]-grid[r][i])>limit)return false;
       } 
       return true;
    }

    int solve(int i,int prev,vector<vector<int>>& grid, int limit){
        if(i==m)return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int ans=solve(i+1,prev,grid,limit);
        if(prev==251)ans=max(ans,1+solve(i+1,i,grid,limit));
        else if(check(prev,i,grid,limit))ans=max(ans,1+solve(i+1,i,grid,limit));

        return dp[i][prev]=ans;
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(0,251,grid,limit);
    }
};