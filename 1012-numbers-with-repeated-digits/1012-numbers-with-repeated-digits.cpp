class Solution {
public:
    string s;
    int size;
    int dp[11][2][1024][2][2];
    int solve(int i,int tight,int bitmask,int repeated,int lz){
        if(i==size)return (repeated?1:0);
        if(dp[i][tight][bitmask][repeated][lz]!=-1)return dp[i][tight][bitmask][repeated][lz];
        int ans=0;
        int num=s[i]-'0';
        int limit=(tight?num:9);

        for(int j=0;j<=limit;j++){
            int tg=(tight && j==num)?1:0;
            if(j==0 && lz){
                ans+=solve(i+1,tg,0,0,1);
                continue;
            }
            int rp=repeated;
            int bt=bitmask;
            if(rp!=1 && ((bt>>j)&1))rp=1;
            bt=(bt|(1<<j));
            ans+=solve(i+1,tg,bt,rp,0);
        }

        return dp[i][tight][bitmask][repeated][lz]=ans;
    }
    int numDupDigitsAtMostN(int n) {
        s=to_string(n);
        size=s.size();
        memset(dp,-1,sizeof(dp));

        return solve(0,1,0,0,1);

    }
};