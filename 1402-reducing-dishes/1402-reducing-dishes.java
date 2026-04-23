class Solution {
    int n;
    int [][]dp;
    int solve(int i,int ct,int[] satisfaction){
        if(i==n)return 0;

        if(dp[i][ct]!=-1)return dp[i][ct];

        int ans=satisfaction[i]*(ct+1)+solve(i+1,ct+1,satisfaction);

        ans=Math.max(ans,solve(i+1,ct,satisfaction));

        return dp[i][ct]=ans;
    }
    public int maxSatisfaction(int[] satisfaction) {
        n=satisfaction.length;
        dp=new int[n][n+1];
        for(int i=0;i<n;i++)Arrays.fill(dp[i],-1);
        Arrays.sort(satisfaction);

        return solve(0,0,satisfaction);
    }
}