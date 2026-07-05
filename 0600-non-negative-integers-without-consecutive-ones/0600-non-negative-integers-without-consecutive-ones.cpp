class Solution {
public:
    int num;
    int size;
    int dp[32][2][2][2];
    int solve(int i,int tight,int prev,int isRepeated){
        if(i==-1)return (isRepeated?0:1);
        if(dp[i][tight][prev][isRepeated]!=-1)return dp[i][tight][prev][isRepeated];
        int ans=0;
        int bit=((num>>i)&1);
        if(tight==0){
            ans+=solve(i-1,0,0,isRepeated);
            ans+=solve(i-1,0,1,(isRepeated | (prev==1)));
        }
        else{
            if(bit){
                ans+=solve(i-1,0,0,isRepeated);
                ans+=solve(i-1,1,1,(isRepeated | (prev==1)));
            }
            else{
                ans+=solve(i-1,1,0,isRepeated);
            }
        }

        return dp[i][tight][prev][isRepeated]=ans;
       
    }
    int findIntegers(int n) {
        num=n;
        size=log2(n)+1;
        memset(dp,-1,sizeof(dp));

        return solve(size-1,1,0,0);

    }
};