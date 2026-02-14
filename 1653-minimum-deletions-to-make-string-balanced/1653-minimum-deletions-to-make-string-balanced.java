class Pair{
    int a,b;
    Pair(int a, int b){
        this.a=a;
        this.b=b;
    }
}

class Solution {
    public int minimumDeletions(String s) {

        Map<Integer,Pair>map=new HashMap<>();
        
        int ct1=0,ct2=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='a')ct1++;
            else ct2++;
            map.put(i,new Pair(ct1,ct2));
        }

        int ans=Integer.MAX_VALUE;

        for(int i=0;i<s.length();i++){
                Pair p1=map.get(i);
                Pair p2=map.get(s.length()-1);    

            if(s.charAt(i)=='a'){
                ans=Math.min(ans,p1.b+p2.a-p1.a);
            }
            else{
                ans=Math.min(ans,p1.b-1+p2.a-p1.a);
                
            }
        }

        return ans;


    }
}