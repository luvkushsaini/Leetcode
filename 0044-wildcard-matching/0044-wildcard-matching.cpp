class Solution {
public:
    int n,m;
    vector<vector<int>>dp;

    bool fun(int i,int j,string &s,string &p){
        if(i==n && j==m)return true;
        if(i==n){  //  case when i have left 0 char in s but some in p , if the left in  p are all * then they can match empty string and i can return true,else i will return false 
            for(int k=j;k<m;k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(p[j]!='*' && p[j]!='?' && p[j]!=s[i])return false;

        if(dp[i][j]!=-1)return dp[i][j];

        bool ans=fun(i+1,j+1,s,p);
        if(p[j]=='*'){
            ans|=fun(i+1,j,s,p);
            ans|=fun(i,j+1,s,p);
        }

        return dp[i][j]=ans;

        
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        dp.resize(n,vector<int>(m,-1));

        return fun(0,0,s,p);
    }
};