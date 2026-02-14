class Solution {

    double initiallyPoured;
    double [][]dp;
    int row, col;
    double ans;

    public double fun(int i ,int  j){
        if(i==0){
            if(initiallyPoured>1.0)return (initiallyPoured-1.0);
            else return 0;
        }
        if(dp[i][j]!=-1.0)return dp[i][j];
        int index1=j;
        int index2=j-1;

        double total=0;

        if(index1<=i-1 && index1>=0)total+=fun(i-1,index1)/2;
        if(index2<=i-1 && index2>=0)total+=fun(i-1,index2)/2;

        if(i==row && j==col){
            ans=total>1.0?1.0:total;
        }
        return dp[i][j]=total>1.0?(total-1.0):0.0;
    }
    public double champagneTower(int poured, int query_row, int query_glass) {
        initiallyPoured=1.0*poured;
        dp=new double[101][101];
        row=query_row;
        col=query_glass;

        if(row==0 && col==0) return initiallyPoured>=1.0?1.0:0.0;

        for(int i=0;i<101;i++){
            Arrays.fill(dp[i],-1.0);
        }

        double num=fun(query_row,query_glass);

        return  ans;
        
    }
}