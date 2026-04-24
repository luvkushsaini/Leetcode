class Solution {

    static int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }

    List<Integer>list;
    int []dp;
    int n;

    int solve(int num,int []nums){
        if(dp[num]!=-1)return dp[num];
        int score=0;
        int i=(Integer.bitCount(num)/2)+1;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((1&(num>>j))==1 || (1&(num>>k))==1)continue;
                int num1=nums[j];
                int num2=nums[k];
                num|=(1<<j);
                num|=(1<<k);
                score=Math.max(score,(i*gcd(num1,num2)+solve(num,nums)));
                num^=(1<<j);
                num^=(1<<k);
            }

        }

        return   dp[num]=score;
    }
    public int maxScore(int[] nums) {
        n=nums.length;
        int x=(1<<(n));
        dp=new int[x];
        Arrays.fill(dp,-1);
        int ans=solve(0,nums);
        return ans;
    }
}