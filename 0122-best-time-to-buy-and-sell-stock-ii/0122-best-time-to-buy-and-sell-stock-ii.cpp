class Solution {
public:
     int n;
     vector<vector<int>>dp;

    int fun(int i,int hasShare,vector<int>& prices){
        if(i==n)return 0;

        if(dp[i][hasShare]!=-1)return dp[i][hasShare];

        int ans=0;
        if(hasShare){
            ans=max(ans,fun(i,0,prices)+prices[i]);
            ans=max(ans,fun(i+1,0,prices)+prices[i]);
            if(i!=n-1)ans=max(ans,fun(i+1,1,prices));
        }
        else{
           if(i!=n-1)ans=fun(i+1,1,prices)-prices[i];
           ans=max(ans,fun(i+1,0,prices));
        }

        return dp[i][hasShare]=ans;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return fun(0,0,prices);
    }
};