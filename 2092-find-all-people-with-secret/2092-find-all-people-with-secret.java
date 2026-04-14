class Solution {

    class Pair{
        int x;
        int y;
        Pair(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        List<Integer>result=new ArrayList<>();
        Map<Integer,List<Pair>>adj=new HashMap<>();
        for(int []arr:meetings){
            int x=arr[0];
            int y=arr[1];
            int time=arr[2];
            adj.putIfAbsent(x,new ArrayList<>());
            adj.putIfAbsent(y,new ArrayList<>());
            adj.get(x).add(new Pair(y,time));
            adj.get(y).add(new Pair(x,time));
        }

        PriorityQueue<Pair>pq=new PriorityQueue<>((a,b)->Integer.compare(a.y, b.y));
        int []visited=new int[n];
        Arrays.fill(visited,0);
        pq.add(new Pair(0,0));
        pq.add(new Pair(firstPerson,0));

        while(!pq.isEmpty()){
            Pair p=pq.poll();
            if (visited[p.x] == 1) continue;
            visited[p.x] = 1;

            if(!adj.containsKey(p.x))continue;

            for(Pair p1:adj.get(p.x)){
                if(visited[p1.x]==0 && p1.y>=p.y){
                    pq.add(p1);
                }
            }

        }

        for (int i = 0; i < n; i++) {
            if (visited[i]==1) result.add(i);
        }

        return result;

    }
}