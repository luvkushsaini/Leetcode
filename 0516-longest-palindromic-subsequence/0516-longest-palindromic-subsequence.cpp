class Solution {
public:
    int n;
    vector<vector<int>>dp;

    int fun(int i,int j,string &s,string &a){
        if(i==n || j==n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans=fun(i+1,j,s,a);
        ans=max(ans,fun(i,j+1,s,a));
        ans=max(ans,fun(i+1,j+1,s,a)+((s[i]==a[j])?1:0));

        return dp[i][j]=ans;
    }


    int longestPalindromeSubseq(string s) {
        n=s.size();
        dp.resize(n,vector<int>(n,-1));
        string a=s;
        reverse(a.begin(),a.end());

        return fun(0,0,s,a);
    }
};