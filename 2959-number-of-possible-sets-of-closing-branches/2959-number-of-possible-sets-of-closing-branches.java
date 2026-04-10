class Solution {
    int count;
 boolean isDistanceLess(Set<Integer> closed, int maxDistance, int[][] roads, int n) {

    int[][] dist = new int[n][n];

    for (int i = 0; i < n; i++) {
        Arrays.fill(dist[i], Integer.MAX_VALUE);
        dist[i][i] = 0;
    }
    for (int[] road : roads) {
        int u = road[0];
        int v = road[1];
        int w = road[2];

        if (closed.contains(u) || closed.contains(v)) continue;

        dist[u][v] = Math.min(dist[u][v], w);
        dist[v][u] = Math.min(dist[v][u], w); 
    }

    for (int k = 0; k < n; k++) {
        if (closed.contains(k)) continue;

        for (int i = 0; i < n; i++) {
            if (closed.contains(i)) continue;

            for (int j = 0; j < n; j++) {
                if (closed.contains(j)) continue;

                if (dist[i][k] == Integer.MAX_VALUE || 
                    dist[k][j] == Integer.MAX_VALUE) continue;

                dist[i][j] = Math.min(dist[i][j],
                                      dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (closed.contains(i)) continue;

        for (int j = 0; j < n; j++) {
            if (closed.contains(j)) continue;

            if (dist[i][j] > maxDistance) return false;
        }
    }

    return true;
}



    int solve(int i, Set<Integer>closed,int maxDistance,int[][]roads,int n){
        if(i==n){
            if(isDistanceLess(closed,maxDistance,roads,n))return 1;
            else return 0;
        }
        int ans=solve(i+1,closed,maxDistance,roads,n);
        closed.add(i);
        ans+=solve(i+1,closed,maxDistance,roads,n);
        closed.remove(i);
        return ans;
    }



    public int numberOfSets(int n, int maxDistance, int[][] roads) {

        Set<Integer>closed=new HashSet<>();

        return solve(0,closed,maxDistance,roads,n);
    }
}