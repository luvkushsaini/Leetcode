class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int mxLen=1;
        string ans;
        

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]!=s[j]){
                    dp[i][j]=0;;
                    continue;
                }
                if(i==j){
                    dp[i][j]=1;
                }
                else if(i==j-1){
                    dp[i][j]=1;
                    mxLen=max(mxLen,2);
                }
                else{
                    dp[i][j]=dp[i+1][j-1];
                    if(dp[i][j])mxLen=max(mxLen,j-i+1);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            int j=i+mxLen-1;
            if(j<n && dp[i][j]){
                ans=s.substr(i,mxLen);
                break;
            }
        }

        return ans;
        
    }
};