class Solution {
    public List<Integer> findGoodIntegers(int n) {
        List<Integer>ans=new ArrayList<>();
        Map<Long,Integer>mp=new HashMap<>();

        int limit=(int)(Math.cbrt(n));

        for(int a=1;a<=limit;a++){
            long aCube=(long)a*a*a;
            int b=a;
            while(aCube+(long)b*b*b<=n){
                long sum=aCube+(long)b*b*b;
                mp.put(sum,mp.getOrDefault(sum,0)+1);
                b++;
            }
        }

        for(long key:mp.keySet()){
            if(mp.get(key)>=2)ans.add((int)key);
        }

        Collections.sort(ans);

        return ans;
    }
}