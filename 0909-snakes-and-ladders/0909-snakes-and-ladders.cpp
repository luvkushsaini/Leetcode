class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        int count=0;
        bool leftToRight=true;
        for(int i=n-1;i>=0;i--){
            if(leftToRight){
                for(int j=0;j<n;j++){
                    count++;
                    if(board[i][j]!=-1)mp[count]=board[i][j];
                }
            }
            else {
                for(int j=n-1;j>=0;j--){
                    count++;
                    if(board[i][j]!=-1)mp[count]=board[i][j];
                }
            }
            leftToRight=!leftToRight;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        vector<int>vis(n*n+1,0);

        while(!pq.empty()){
            auto [ct,pos]=pq.top();
            pq.pop();
            if(vis[pos])continue;
            vis[pos]=1;
            if(pos==n*n)return ct;
            int low=pos+1;
            int high=min(pos+6,n*n);
            for(int k=low;k<=high;k++){
                int next=k;
                if(mp.count(k))next=mp[k];
                if(vis[next]==0)pq.push({ct+1,next});
            }

        }

        return -1;
    }
};