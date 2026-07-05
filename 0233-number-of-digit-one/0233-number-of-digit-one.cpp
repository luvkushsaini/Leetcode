class Solution {
public:
    vector<vector<vector<int>>>dp;
    string s;
    int size;
    int solve(int tight,int i,int ct){
        if(i==s.size()){
            return ct;
        }
        if(dp[tight][i][ct]!=-1)return dp[tight][i][ct];
        int count=0;
        int num=s[i]-'0';
        int limit=(tight?num:9);

        for(int j=0;j<=limit;j++){
            int tg=(tight && j==num)?1:0;
            count+=(solve(tg,i+1,ct+(j==1?1:0)));
           }

        return dp[tight][i][ct]=count;
    }
    int countDigitOne(int n) {
        s=to_string(n);
        size=s.size();
        dp.resize(2,vector<vector<int>>(size+1,vector<int>(size+1,-1)));

        int count=solve(1,0,0);
        return count;
    }
};