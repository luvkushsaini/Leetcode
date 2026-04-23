class Solution {

    class  Pair{
        int val ;
        int row;
        int col;

        Pair(int val,int row,int col){
            this.val=val;
            this.col=col;
            this.row=row;
        }
    }


    public int[][] colorGrid(int n, int m, int[][] sources) {
        int [][]vis=new int[n][m];
        int [][]final_ans=new int[n][m];
        int []r={-1,1,0,0};
        int []c={0,0,-1,1};

        Queue<Pair>q=new ArrayDeque<>();
        PriorityQueue<Pair>pq=new PriorityQueue<>((a,b)->Integer.compare(b.val,a.val));

        for(int []cell:sources){
            int row=cell[0];
            int col=cell[1];
            int val=cell[2];
            vis[row][col]=1;
            q.add(new Pair(val,row,col));
            final_ans[row][col]=val;
        }


        while(!q.isEmpty()){

            int size=q.size();
            for(int k=0;k<size;k++){
                Pair p=q.poll();
                pq.add(p);
            }

            for(int k=0;k<size;k++){
            Pair p=pq.poll();
            int val=p.val;
            int row=p.row;
            int col=p.col;

            for(int i=0;i<4;i++){
                int new_row=row+r[i];
                int new_col=col+c[i];

                if(new_row<n && new_row>=0 && new_col<m && new_col>=0 && vis[new_row][new_col]==0){
                    vis[new_row][new_col]=1;
                    final_ans[new_row][new_col]=val;
                    q.add(new Pair(val,new_row,new_col));
                }
            }
            }
        
        }


        return final_ans;
    }
}