class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool check(int i,int j,string&s){
        if(i>j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j] && check(i+1,j-1,s))return true;
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        n=s.size();
        dp.assign(n,vector<int>(n,-1));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s))count++;
            }
        }
        return count;
    }
};