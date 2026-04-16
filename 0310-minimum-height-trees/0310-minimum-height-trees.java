class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer>result=new ArrayList<>();
        if(n==1){
            result.add(0);
            return result;
        }
        int []indegree=new int[n];
        Map<Integer,List<Integer>>adj=new HashMap<>();
        for(int []edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj.putIfAbsent(u,new ArrayList<>());
            adj.putIfAbsent(v,new ArrayList<>());
            adj.get(u).add(v);
            adj.get(v).add(u);
            indegree[u]++;
            indegree[v]++;
        }

        Queue<Integer>q=new LinkedList<>();

        for(int i=0;i<n;i++){
            if(indegree[i]==1)q.add(i);
        }
        result=new ArrayList<>(q);

        

        while(!q.isEmpty()){

            int size=q.size();
            while(size>0){
                int curr=q.poll();

                for(int node:adj.get(curr)){
                    indegree[node]--;
                    if(indegree[node]==1)q.add(node);
                }
                size--;
            }
            if(!q.isEmpty()){
                result=new ArrayList<>(q);
            }
            

        }

        return result;
    }
}