class Solution {
    public int fun(int i,int j,int mismatch,String s){
        if(i<0 && j==s.length()){
            if(mismatch==1)return s.length();
            else return 0;
        }
        if(i<0 || j>=s.length()){
            if(mismatch==0)return j-i;
            else return j-i-1;
        }
        if(s.charAt(i)!=s.charAt(j) && mismatch>0)return j-i-1;
        if(s.charAt(i)==s.charAt(j) && mismatch>0){
            return Math.max(j-i+1,fun(i-1,j+1,mismatch,s));
        }
        if(s.charAt(i)==s.charAt(j) && mismatch==0){
            return fun(i-1,j+1,0,s);
        }
        if(s.charAt(i)!=s.charAt(j) && mismatch==0){
            return Math.max(fun(i,j+1,mismatch+1,s),fun(i-1,j,mismatch+1,s));
        }
        return 0;
    }

    public int almostPalindromic(String s) {

        int ans=0;

        for(int i=0;i<s.length();i++){
            ans=Math.max(ans,fun(i-1,i+1,0,s));
            ans=Math.max(ans,fun(i,i+1,0,s));
        }

        return ans;
        
    }
}