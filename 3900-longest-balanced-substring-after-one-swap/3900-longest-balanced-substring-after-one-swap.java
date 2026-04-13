class Solution {
    public int longestBalanced(String s) {
          int n=s.length();
        int[] o=new int[n];
        int[] z=new int[n];

        Map<Integer,Integer>ind=new HashMap<>();
        Map<Integer,Integer>ind0=new HashMap<>();
        Map<Integer,Integer>ind1=new HashMap<>();

        ind.put(0,-1);
        int sum=0;
        int ct0=0;
        int ct1=0;

        for(int i=0;i<n;i++){
            sum+=(s.charAt(i)=='1')?1:-1;
            ind.putIfAbsent(sum,i);
            if(s.charAt(i)=='1'){ct1++;}
            else {ct0++;}

            o[i]=ct1;
            z[i]=ct0;

            if(o[i]>0)ind1.putIfAbsent(sum,i);
            if(z[i]>0)ind0.putIfAbsent(sum,i);

        }

        int mx=0;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=(s.charAt(i)=='1')?1:-1;

            if(ind.containsKey(sum)){
                int j=ind.get(sum);
                mx=Math.max(mx,i-j);
            }

            if(ind.containsKey(sum+2)){
                int j=ind.get(sum+2);
                int subs1=o[i]-(j>=0?o[j]:0);
                if(ct1>subs1)mx=Math.max(mx,i-j);
                else if(ind1.containsKey(sum+2))mx=Math.max(mx,i-ind1.get(sum+2));
            }

            if(ind.containsKey(sum-2)){
                int j=ind.get(sum-2);
                int subs0=z[i]-(j>=0?z[j]:0);
                if(ct0>subs0)mx=Math.max(mx,i-j);
                else if(ind0.containsKey(sum-2))mx=Math.max(mx,i-ind0.get(sum-2));
            }


        }

        return mx;
    }
}