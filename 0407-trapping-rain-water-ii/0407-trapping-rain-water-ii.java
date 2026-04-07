class Solution {

    public class PP{
        int i,j,h;
        PP(int i,int j,int h){
            this.i=i;
            this.j=j;
            this.h=h;
        }
    }

    public int trapRainWater(int[][] heightMap) {
        int n=heightMap.length;
        int m=heightMap[0].length;

        int []row={-1,1,0,0};
        int []col={0,0,-1,1};

        PriorityQueue<PP>pq=new PriorityQueue<>((a,b)-> a.h-b.h);
        int [][]visited=new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(visited[i],0);
        }

        for(int i=0;i<n;i++){
            visited[i][0]=1;
            pq.add(new PP(i,0,heightMap[i][0]));
        }
        for(int i=0;i<n;i++){
            visited[i][m-1]=1;
            pq.add(new PP(i,m-1,heightMap[i][m-1]));
        }
        for(int i=1;i<m-1;i++){
            visited[0][i]=1;
            pq.add(new PP(0,i,heightMap[0][i]));
        }
        for(int i=1;i<m-1;i++){
            visited[n-1][i]=1;
            pq.add(new PP(n-1,i,heightMap[n-1][i]));
        }

        int water=0;


        while(!pq.isEmpty()){
            PP p=pq.poll();
            int x=p.i;
            int y=p.j;
            int height=p.h;

            for(int k=0;k<4;k++){
                int new_x=x+row[k];
                int new_y=y+col[k];

                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && visited[new_x][new_y]==0){
                    water+=Math.max(0,(height-heightMap[new_x][new_y]));
                    visited[new_x][new_y]=1;
                    pq.add(new PP(new_x,new_y,Math.max(height,heightMap[new_x][new_y])));
                }
            }

        }

        return water;

    }
}