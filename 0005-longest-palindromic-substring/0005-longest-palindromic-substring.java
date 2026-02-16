class Pair{
    int x;
    int y;
    Pair(int x,int y){
        this.x=x;
        this.y=y;
    }
}

class Solution {

    Pair fun(int i,int j,String s){
        while(i>=0 && j<s.length() && s.charAt(i)==s.charAt(j)){
            i--;
            j++;
        }
        return new Pair(i+1,j-1);
    }
    public String longestPalindrome(String s) {
        int len=s.length();
        int ans=0;

        Pair p=new Pair(0,0);

        for(int i=0;i<len;i++){
             Pair p1=fun(i,i+1,s);
             Pair p2=fun(i,i,s);

           int len1 = p1.y - p1.x + 1;
           int len2 = p2.y - p2.x + 1;


             if(ans<len1){
                ans=len1;
                p=p1;
             }
             if(ans<len2){
                ans=len2;
                p=p2;
             }
        }

        String sub = s.substring(p.x, p.y+1);

        return sub;

    }
}