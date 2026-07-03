class Solution {
public:
    // bottom-up solution with prefixSum optimization with time complexity of O(n*m), must see the oldest previosly submitted TLE submition of memorization and bottom-up without prefixSum optimization 
     const long MOD=1000000007;
    int zigZagArrays(int n, int l, int r) {
        int result=0;
        r=r-l+1;
        l=1; // e.g we will get same number of results whether l=0,r=9 or l=11 ,r=20 so we convert in the first form to every question's l and r
         int dp[2001][2001][2];

        for(int num=l;num<=r;num++){
            dp[n][num][0]=1;
            dp[n][num][1]=1;
        }

        for(int i=n-1;i>=0;i--){
            vector<int>prefixSum1(r+1,0);
            vector<int>prefixSum0(r+1,0);

            for(int num=l;num<=r;num++){
                 prefixSum1[num]=(prefixSum1[num-1]+dp[i+1][num][1]%MOD)%MOD;
                 prefixSum0[num]=(prefixSum0[num-1]+dp[i+1][num][0]%MOD)%MOD;
            }

            for(int prev=l;prev<=r;prev++){

                dp[i][prev][1]=(prefixSum0[r]-prefixSum0[prev]+MOD)%MOD;
                dp[i][prev][0]=prefixSum1[prev-1];
            }
        }

        for(int num=l;num<=r;num++){
            result=(result+dp[1][num][0]%MOD)%MOD;
            result=(result+dp[1][num][1]%MOD)%MOD;
        }
        return result;
    }
};