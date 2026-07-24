class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m=values.size();
        int n=values[0].size();

        long long ans=0L;

        priority_queue<vector<int>>pq;
        for(int i=0;i<m;i++){
            pq.push({values[i][0],i,0});
        }
        int day=m*n;
        while(!pq.empty()){
            auto v=pq.top();
            int val=v[0];
            int i=v[1];
            int j=v[2];
            pq.pop();
            ans+=(1LL*day*val);
            if((j+1)<n)pq.push({values[i][j+1],i,j+1});
            day--;
        }

        return ans;
    }
};