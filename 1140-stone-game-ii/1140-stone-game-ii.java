class Solution {
    int n;
    int []prefixSum;
    int [][][]dp;
    int solve(int i,int turn,int M){
        if(i>=n)return 0;
        int X=2*M;
        if(X>=n-i){
            if(turn==0){
                return prefixSum[n-1]-((i-1>=0)?prefixSum[i-1]:0);
            }
            else{
                return 0;
            }
        }

        if(dp[i][turn][M]!=-1)return dp[i][turn][M];
        int ans=(turn==0)?-1:Integer.MAX_VALUE;
        if(turn==0){
            for(int j=0;j<X;j++){
                ans=Math.max(ans,prefixSum[i+j]-((i-1>=0)?prefixSum[i-1]:0)+solve(i+j+1,1,Math.max(M,j+1)));
            }
        }
        else{
            for(int j=0;j<X;j++){
                ans=Math.min(ans,solve(i+j+1,0,Math.max(M,j+1)));
            }
        }
        return dp[i][turn][M]=ans;
    }


    public int stoneGameII(int[] piles) {
        n=piles.length;
        prefixSum=new int[n];
        prefixSum[0]=piles[0];
        dp=new int[n+1][2][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
        for(int i=1;i<n;i++)prefixSum[i]=prefixSum[i-1]+piles[i];

        int ans=solve(0,0,1);
        return ans;
        
    }
}