class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int count=0;
        for(int len=1;len<=n;len++){
            for(int i=0;i<n;i++){
                int j=i+len-1;
                if(j>=n)break;
                if(s[i]!=s[j])continue;
                if(len==1){
                    count++;
                    dp[i][j]=1;
                }
                else if(len==2 && s[i]==s[j]){
                    count++;
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i+1][j-1];
                    if(dp[i][j]==1)count++;
                }
            }
        }

        return count;
    }
};