class Solution {
    class Pair{
        int first,second;
        Pair(int first, int second){
            this.first=first;
            this.second=second;
        }
    }


    class DSU{
        int [] parent,size,parity;

        DSU(int n){
            parent=new int[n];
            parity=new int[n];
            size=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
                parity[i]=0;
            }
        }

        Pair find(int x){
            if(parent[x]==x){
                return new Pair(x,0);
            }

            Pair p=find(parent[x]);
            parent[x]=p.first;
            parity[x]^=p.second;

            return new Pair(parent[x],parity[x]);
        }

        boolean unionBySize(int u,int v,int w){
            Pair p1=find(u);
            Pair p2=find(v);
            int parent1=p1.first;
            int parent2=p2.first;
            int xu=p1.second;
            int xv=p2.second;


            if(parent1==parent2){
                return ((xu^xv^w)==0);
            }

            if(size[parent1]<size[parent2]){
                parent[parent1]=parent2;
                size[parent2]+=size[parent1];
                parity[parent1] = xu ^ xv ^ w;
            }
            else{
                parent[parent2]=parent1;
                size[parent1]+=size[parent2];
                parity[parent2] = xu ^ xv ^ w;
            }
            return true ;
        }
    };

    public int numberOfEdgesAdded(int n, int[][] edges) {
        DSU dsu=new DSU(n);
        int count=0;
        for(int[]edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            if(dsu.unionBySize(u,v,w)){
                count++;
            }

        }
        return count;
    }
}