class Solution {

    boolean isEqual(int []a){
        int val=0;
        for(int k=0;k<26;k++){
            if(a[k]!=0){
                val=a[k];
                break;
            }
        }
        
        for(int k=1;k<26;k++){
            if(a[k]!=val && a[k]!=0)return false;
        }
        return true;
    }

    public int longestBalanced(String s) {
        int n=s.length();

       int ans=0;


        for(int i=0;i<n;i++){
                   int [] a=new int [26];
            for(int j=i;j<n;j++){
               int index=s.charAt(j)-'a';
               a[index]++;
               if(isEqual(a)){
                ans=Math.max(ans,j-i+1);
               }
            }
        }

        return ans;
    }
}