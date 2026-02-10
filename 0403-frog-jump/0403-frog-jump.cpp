class Solution {
public:
    vector<vector<int>>dp;
    int fun(int i ,int lastJump,vector<int>&stones){
        if(i==stones.size()-1)return 1;
        if(dp[i][lastJump]!=-1)return dp[i][lastJump];
        int index1=lower_bound(stones.begin(),stones.end(),stones[i]+lastJump)-stones.begin();
        int index2=lower_bound(stones.begin(),stones.end(),stones[i]+lastJump+1)-stones.begin();
        int index3=lower_bound(stones.begin(),stones.end(),stones[i]+lastJump-1)-stones.begin();

        int ans=0;

        if(index1!=stones.size() && stones[index1]==stones[i]+lastJump)ans|=fun(index1,lastJump,stones);
        if(index2!=stones.size() && stones[index2]==stones[i]+lastJump+1)ans|=fun(index2,lastJump+1,stones);
        if(index3!=stones.size() && stones[index3]==stones[i]+lastJump-1 && lastJump>1)ans|=fun(index3,lastJump-1,stones);

          return  dp[i][lastJump]=ans;

    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(n==1)return true;
        if(stones[1]-stones[0]!=1)return false;
        dp.resize(n,vector<int>(n+1,-1));
        

        return fun(1,1,stones);
    }
};