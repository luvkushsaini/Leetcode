class Solution {

     long MOD=1000000007;
     int []dp;

    long solve(int i,String s,int k){
        if(i==s.length())return 1;
        if(s.charAt(i)=='0')return 0;

        if(dp[i]!=-1)return (long)dp[i];

        int j=i;
        long ans=0;
        while(j<s.length()){
            long num=Long.parseLong(s.substring(i,j+1));
            if(num>(long)k)break;
            j++;
            ans=(ans+solve(j,s,k)%MOD)%MOD;
        }
        dp[i]=(int)ans;
        return ans;
    }


    public int numberOfArrays(String s, int k) {
        int n=s.length();
        dp=new int[n+1];
        Arrays.fill(dp,-1);
        
        long ans=solve(0,s,k);
        return (int)ans;
    }
}