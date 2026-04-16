class Solution {
    int n,m;
    int [][]dp;
    int [][]freq;
    long MOD=1000000007;

    int solve(int i,int j,String target){
        if(i>=m)return 1;
        if(j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long ans=(int)(solve(i,j+1,target)%MOD);
        int charPos=target.charAt(i)-'a';
        int freqOfChar=freq[j][charPos];
        if(freqOfChar>0){
            ans=(ans+(long)freqOfChar*solve(i+1,j+1,target))%MOD;
        }
        return dp[i][j]=(int)ans;

    }

    public int numWays(String[] words, String target) {
        n=words[0].length();
        m=target.length();
        dp=new int[m+1][n+1];
        freq=new int[n][26];

        for(int i=0;i<=m;i++){
            Arrays.fill(dp[i],-1);
        }

        for(int i=0;i<words.length;i++){
            for(int j=0;j<n;j++){
                int pos=words[i].charAt(j)-'a';
                freq[j][pos]++;
            }

        }

        int ans=solve(0,0,target);
        return ans;
        
    }
}