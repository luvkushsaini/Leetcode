class Solution {
public:
    int n,m,s;
    const int M=1000000007;
    int dp[101][101][101][2][2];
    int solve(int i,int j,int k ,string& word1, string& word2, string& target,int c1,int c2){
        if(i==n)return (c1==1 && c2==1)?1:0;
        if(dp[i][j][k][c1][c2]!=-1)return dp[i][j][k][c1][c2];
        int count=0;
        for(int l=j;l<m;l++){
            if(word1[l]==target[i])count=(count+solve(i+1,l+1,k,word1,word2,target,1,c2)%M)%M;
        }
        for(int l=k;l<s;l++){
            if(word2[l]==target[i])count=(count+solve(i+1,j,l+1,word1,word2,target,c1,1)%M)%M;
        }

        return dp[i][j][k][c1][c2]=count;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        n=target.size();
        m=word1.size();
        s=word2.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,word1,word2,target,0,0);
        return ans;
    }
};