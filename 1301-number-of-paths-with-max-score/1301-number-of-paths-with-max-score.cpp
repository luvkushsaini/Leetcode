class Solution {
public:
    int n;
    const long M=1000000007;
    vector<vector<pair<int,int>>>dp;
    pair<int,int>solve(int i,int j,vector<string>& board){
        if(i==0 && j==0)return {0,1};
        if(dp[i][j]!=make_pair(-1,-1))return dp[i][j];
        if(board[i][j]=='X')return {0,0};
        int bestScore=0;
        int bestPaths=0;
        vector<pair<int,int>>v;
         pair<int,int>p;
        if(i-1>=0){
           p=solve(i-1,j,board);
            if(p.second!=0){
                v.push_back(p);
                if(p.first>=bestScore){
                    bestScore=p.first;
                    bestPaths=p.second;
                }
            }
        }
        if(j-1>=0){
            p=solve(i,j-1,board);
            if(p.second!=0){
                v.push_back(p);
                if(p.first>=bestScore){
                    bestScore=p.first;
                    bestPaths=p.second;
                }
            }
        }
        if(j-1>=0 && i-1>=0){
            p=solve(i-1,j-1,board);
            if(p.second!=0){
                v.push_back(p);
                if(p.first>=bestScore){
                    bestScore=p.first;
                    bestPaths=p.second;
                }
            }
        }

        if(v.size()==3 && v[0].first==v[1].first && v[1].first==v[2].first){
            bestScore=v[0].first;
            bestPaths=((v[0].second+v[1].second)%M+v[2].second)%M;
        }
        else{
         for(int j=0;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                if(v[j].first==v[k].first && v[j].first==bestScore){
                bestPaths=(v[j].second+v[k].second)%M;
               }
            }  
        }
        }

        int num=0;
        if(board[i][j]!='S')num=board[i][j]-'0';
        return dp[i][j]={bestScore+num,bestPaths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        dp.assign(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int>p=solve(n-1,n-1,board);

        return {p.first,p.second};
    }
};