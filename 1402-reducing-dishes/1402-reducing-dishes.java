class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        int n=satisfaction.length;
        int [][]dp=new int[n+1][n+1];
        Arrays.sort(satisfaction);

        for(int ct=0;ct<=n;ct++)dp[n][ct]=0;

        for(int i=n-1;i>=0;i--){
            for(int ct=i;ct>=0;ct--){
                dp[i][ct]=(ct+1)*satisfaction[i]+dp[i+1][ct+1];
                dp[i][ct]=Math.max(dp[i][ct],dp[i+1][ct]);
            }
        }

        return dp[0][0];
    }
}