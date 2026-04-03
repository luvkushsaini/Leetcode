class Solution {
public:
    vector<vector<string>>ans;

    bool check(int row,int col,vector<string>&v){
        int n=v.size();

        //upperLeft Diagonal
        int r=row-1;
        int c=col-1;

        while(r>=0 && c>=0){
            if(v[r][c]=='Q')return false;
            r--;
            c--;
        }

        // uperRight Diagonal
        r=row-1;
        c=col+1;

        while(r>=0 && c<n){
            if(v[r][c]=='Q')return false;
            r--;
            c++;
        }

        //upper rows

        r=row-1;
        c=col;

        while(r>=0){
            if(v[r][c]=='Q')return false;
            r--;
        }

        return true;
    }


    void solve(int row,vector<string>&v,int n){

        if(row==n){
            ans.push_back(v);
            return;
        }

        for(int col=0;col<n;col++){
            if(check(row,col,v)){
                v[row][col]='Q';
                solve(row+1,v,n);
                v[row][col]='.';
            }
        }
        return ;
    }


    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>v(n,s);

        solve(0,v,n);
        return ans;
    }
};