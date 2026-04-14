class Solution {
    Boolean [][][]dp;
    boolean solve(int i,int j,int len,String s1,String s2){
        if(s1.substring(i,i+len).equals(s2.substring(j,j+len)))return true;
        int n=len;
        if(dp[i][j][len]!=null)return dp[i][j][len];
        boolean ans=false;

        for(int k=0;k<n-1;k++){
            if((solve(i,j,k+1,s1,s2) && solve(i+k+1,j+k+1,n-(k+1),s1,s2))){
                ans=true;
                break;
            }
            ans|=(solve(i,j+n-(k+1),k+1,s1,s2) && solve(i+k+1,j,n-(k+1),s1,s2));

        }

        return  dp[i][j][len]=ans;
    }

    public boolean isScramble(String s1, String s2) {
        int n=s1.length();
        dp=new Boolean[n][n][n+1];
        boolean ans=solve(0,0,n,s1,s2);
        return ans;
    }
}