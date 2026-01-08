class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;

        for(auto &f:flights){
            int from =f[0];
            int to=f[1];
            int price=f[2];
            adj[from].push_back({to,price});
        }
        
        priority_queue<
    tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>
> pq;
        pq.push({0,0,src});

        int ans=INT_MAX;

        while(!pq.empty()){
            auto [cost,stop,node]=pq.top();
            pq.pop();

            if(node==dst)return cost;
            if(stop>k)continue;


            for(auto &[to,price]:adj[node]){
                if(cost+price<dist[to][stop+1]){
                    dist[to][stop+1]=cost+price;
                pq.push({cost+price,stop+1,to});
                }
            }
        }
        return -1;
    }
};