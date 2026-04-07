class Solution {

    int n ;
    long [][]dp;
    public long  solve(int i , int k ,int end, int [] nums){
        if(k==0)return 0;
        if(i>end){
            return (long)1e15;
        }

        if(dp[i][k]!=-1)return dp[i][k];

        long ans=solve(i+1,k,end,nums);
        long left  = (i - 1 >= 0) ? nums[i - 1] : nums[n-1];
        long right = (i + 1 <n) ? nums[i + 1] : nums[0];
        long num = Math.max(0, Math.max(left, right) - nums[i] + 1);
        ans=Math.min(ans,num+solve(i+2,k-1,end,nums));
        return dp[i][k]=ans;
    }
    public int minOperations(int[] nums, int k) {
        n=nums.length;
        if(k>n/2)return -1;
        if(n==1 || k==0)return 0;
        if (n == 2) return nums[0] == nums[1] ? 1 : 0;
        dp=new long[n][k+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1L);
        }
        long ans=Integer.MAX_VALUE;
        if(k>=1){
            long num = Math.max(0, Math.max(nums[1], nums[n-1]) - nums[0] + 1);
            ans=Math.min(ans,num+solve(2,k-1,n-2,nums));
        }
        System.out.print(ans);
        dp = new long[n][k+1];
        for(int i = 0; i < n; i++) Arrays.fill(dp[i], -1);
        ans=Math.min(ans,solve(1,k,n-1,nums));
        return (ans>= 1e15)?-1:(int)ans;

    }
}