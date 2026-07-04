class DSU{
    public:
    vector<int>par,size;

    DSU(int n){
        par.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++)par[i]=i;
    }

    int findPar(int i){
        if(par[i]==i)return i;
        return par[i]=findPar(par[i]);
    }

    void unionBySize(int u,int v){
        int p1=findPar(u);
        int p2=findPar(v);

        if(p1==p2)return ;

        if(size[p1]<size[p2])swap(p1,p2);
        par[p2]=p1;
        size[p1]+=size[p2];
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int dis=roads[i][2];
            dsu.unionBySize(u,v);
        }

        int parent=dsu.findPar(1);
        int ans=1e5;

        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int dis=roads[i][2];
            int p1=dsu.findPar(u);
            if(p1!=parent)continue;
            int p2=dsu.findPar(v);
            if(p2!=parent)continue;

            ans=min(ans,dis);
        }

        return ans;

    }
};