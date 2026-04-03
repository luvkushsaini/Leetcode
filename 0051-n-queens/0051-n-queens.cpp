class Solution {
public:
    // optimized solution with time complexity of O(n!) , previously we were using the check() function which was taking itself O(n) and time complexity was O(!n*n);
    
    vector<int>leftRow,lowerDiagonal,upperDiagonal;
    vector<vector<string>>ans;
    void solve(int row,vector<string>&v,int n){

        if(row==n){
            ans.push_back(v);
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


    vector<vector<string>> solveNQueens(int n) {
        leftRow.resize(n,0);
        lowerDiagonal.resize(2*n-1,0);
        upperDiagonal.resize(2*n-1,0);

        string s(n,'.');
        vector<string>v(n,s);

        solve(0,v,n);
        return ans;
    }
};