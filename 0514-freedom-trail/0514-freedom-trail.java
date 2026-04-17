class Solution {
    //can be solved using both graph and dp
    class Pair{
        int first;
        int second;
        int third;

        Pair(int first,int second,int third){
            this.first=first;
            this.second=second;
            this.third=third;
        }
    }

    public int findRotateSteps(String ring, String key) {
        int n=ring.length();
        int m=key.length();

        Map<Character,List<Integer>>mp=new HashMap<>();

        for(char c='a';c<='z';c++){
            mp.put(c, new ArrayList<>());
        }
        for (int i=0;i<n;i++) {
            mp.get(ring.charAt(i)).add(i);
        }
         int[][]dist=new int[m+1][n];
        for (int[]row:dist) Arrays.fill(row,Integer.MAX_VALUE);
        dist[0][0]=0;

        PriorityQueue<Pair>pq=new PriorityQueue<>((a,b)->Integer.compare(a.third,b.third));
        pq.add(new Pair(0,0,0));
        int ans=Integer.MAX_VALUE;
        while(!pq.isEmpty()){

            Pair p=pq.poll();
            int currInd=p.first;
            int currCentre=p.second;
            int totalSteps=p.third;

            int j=currCentre;

            if(currInd==m){
                 ans=totalSteps;;
                 break;
            }
            if(totalSteps>dist[currInd][currCentre])continue;

            for(int pos:mp.get(key.charAt(currInd))){
                int diff=Math.abs(pos-j);
                int step=Math.min(diff,n-diff);

                int newCost=totalSteps+step+1;

            if( dist[currInd+1][pos]>newCost){
                dist[currInd+1][pos]=newCost;
            pq.add(new Pair(currInd+1,pos,newCost));
            }

            }

        }

        return ans;
    }
}