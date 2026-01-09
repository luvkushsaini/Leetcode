class Solution {
public:
    vector<int>r={1,1,1};
    vector<int>c={-1,0,1};
    int n;
    vector<vector<int>>dp;

    int fun(int i,int j,vector<vector<int>>& matrix){
        if(i==n-1)return matrix[i][j];

        if(dp[i][j]!=-1e5)return dp[i][j];

        int sum=1e5;
        for(int k=0;k<3;k++){
            int newr=i+r[k];
            int newc=j+c[k];
            if(newr>=0 && newr<n && newc>=0 && newc<n){
                sum=min(sum,fun(newr,newc,matrix));
            }
        }
        return dp[i][j]=(sum+matrix[i][j]);
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();

        dp.resize(n,vector<int>(n,-1e5));


        int ans=INT_MAX;

        for(int j=0;j<n;j++){
            ans=min(ans,fun(0,j,matrix));
        }
        return ans;


        
    }
};