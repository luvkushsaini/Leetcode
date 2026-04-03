class Solution {
public:

    vector<int>leftRow,lowerDiagonal,upperDiagonal;
    int answer=0;

    void solve(int row,vector<string>&v,int n){

        if(row==n){
            answer++;
            return;
        }

        for(int col=0;col<n;col++){
            if(leftRow[col]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){

                v[row][col]='Q';
                leftRow[col]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;

                solve(row+1,v,n);

                v[row][col]='.';
                leftRow[col]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
        return ;
    }


    int totalNQueens(int n) {
        leftRow.resize(n,0);
        lowerDiagonal.resize(2*n-1,0);
        upperDiagonal.resize(2*n-1,0);

        string s(n,'.');
        vector<string>v(n,s);

        solve(0,v,n);
        return answer;
    }
};