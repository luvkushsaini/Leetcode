class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<int>r={0,0,-1,1};
        vector<int>c={1,-1,0,0};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});

        vector<vector<int>>efforts(n,vector<int>(m,INT_MAX));
        efforts[0][0]=0;

        while(!pq.empty()){
            auto [effort,i,j]=pq.top();
            pq.pop();

            for(int k=0;k<4;k++){
                int newr=i+r[k];
                int newc=j+c[k];
                

                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int newEffort=max(effort,abs(heights[newr][newc]-heights[i][j]));
                    if(newEffort<efforts[newr][newc]){
                        efforts[newr][newc]=newEffort;
                        pq.push({newEffort,newr,newc});
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }
};