class Solution {
public:
    //reduced to 3d dp as i+j=k+l always 
    int n;
    int dp[50][50][50];
    int solve(int i,int j,int k,vector<vector<int>>& grid){
        int l=i+j-k;
        if(i>=n || j>=n || k>=n || l>=n ||grid[i][j]==-1 || grid[k][l]==-1)return INT_MIN;
        if(i==n-1 && j==n-1 && k==n-1 && l==n-1)return grid[i][j];
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int cheeries=0;
        cheeries+=(i==k && j==l)?(grid[i][j]):(grid[i][j]+grid[k][l]);
        int p1=solve(i,j+1,k,grid);
        int p2=solve(i+1,j,k,grid);
        int p3=solve(i+1,j,k+1,grid);
        int p4=solve(i,j+1,k+1,grid);
        cheeries+=max({p1,p2,p3,p4});

        return dp[i][j][k]=cheeries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,grid);
        return (ans>0?ans:0);
    }
};