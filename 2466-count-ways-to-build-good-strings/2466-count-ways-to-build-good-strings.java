class Solution {

    long MOD= 1000000007;
    int []dp;
    long  solve(int currLeng,int zero,int one,int high,int low){

        if(dp[currLeng]!=-1)return (long)dp[currLeng];

        long ans=0;
        if((currLeng+zero)<=high){
           ans=(((currLeng+zero>=low)?1L:0L)+solve(currLeng+zero,zero,one,high,low)%MOD)%MOD;
        }
        if((currLeng+one)<=high){
            ans=(ans+((currLeng+one>=low)?1L:0L)+solve(currLeng+one,zero,one,high,low)%MOD)%MOD;
        }
        dp[currLeng]=(int)ans;
        return ans;
    }
    public int countGoodStrings(int low, int high, int zero, int one) {
        dp=new int [high+1];
        Arrays.fill(dp,-1);
        long ans=solve(0,zero,one,high,low);
        return (int)ans;
    }
}