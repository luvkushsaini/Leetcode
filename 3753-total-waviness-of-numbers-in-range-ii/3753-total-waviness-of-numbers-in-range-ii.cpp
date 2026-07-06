class Solution {
public:
   long long dp[16][2][11][11][2][20];
   long long solve(string &s,int i,int tight,int prev1,int prev2,int lz,int ct){
    if(i==s.size())return ct;
    if(dp[i][tight][prev1][prev2][lz][ct]!=-1)return dp[i][tight][prev1][prev2][lz][ct];
    int digit=s[i]-'0';
    int limit=(tight)?digit:9;
    long long count=0;

    for(int j=0;j<=limit;j++){
        int tg=(tight && j==digit)?1:0;
        if(prev2==10){
            if(lz && j==0)count+=solve(s,i+1,tg,prev1,prev2,1,0);
            else count+=solve(s,i+1,tg,j,prev1,0,0);
        }
        else{
            int add=((prev1>prev2 && prev1>j)||(prev1<j && prev1<prev2))?1:0;
            count+=(solve(s,i+1,tg,j,prev1,0,ct+add));
        }
    }

    return dp[i][tight][prev1][prev2][lz][ct]=count;
   }


    long long totalWaviness(long long num1, long long num2) {
        string s1=to_string(num1-1);
        string s2=to_string(num2);
        memset(dp,-1,sizeof(dp));
        long long a2=solve(s2,0,1,10,10,1,0);
        memset(dp,-1,sizeof(dp));
        long long a1=solve(s1,0,1,10,10,1,0);

        long long ans=a2-a1;
        return ans;
    }
};
