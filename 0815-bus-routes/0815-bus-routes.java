class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        Map<Integer,List<Integer>>mp=new HashMap<>();
        int n=routes.length;

        if(source==target)return 0;


        for(int i=0;i<n;i++){
            for(int route:routes[i]){
                mp.putIfAbsent(route,new ArrayList<>());
                mp.get(route).add(i);
            }
        }
        if(!mp.containsKey(source))return -1;


        int ans=0;

        Queue<Integer>q=new ArrayDeque<>();
        int []visited=new int[n];
        Arrays.fill(visited,0);
        for(int route:mp.get(source)){
            visited[route]=1;
            q.add(route);
        }


        while(!q.isEmpty()){
            int size=q.size();
            while(size>0){
                int currStop=q.poll();
                for(int x:routes[currStop]){
                    if(x==target){
                        return ans+1;
                    }
                    for(int stop:mp.get(x)){
                        if(visited[stop]==1)continue;
                        visited[stop]=1;
                        q.add(stop);
                    }
                }
                size--;
            }
            ans++;
        }

        return -1;
    }
}