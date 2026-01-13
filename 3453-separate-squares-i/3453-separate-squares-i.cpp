class Solution {
public:

    double totalArea;
    bool fun(double mid,vector<vector<int>>& squares){
        double area=0.0;
        for(int i=0;i<squares.size();i++){
            double y=squares[i][1];
            double side =squares[i][2];
            if(y>=mid)continue;
           double height=min(mid-y,side);
            area+=((height)*(side));
        }

        return area>=totalArea/2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {


        sort(squares.begin(),squares.end(),[](const vector<int>&v1,const vector<int>&v2){
            return v1[1]<v2[1];
        });


        double low=0.0;
        double high=0.0;
        totalArea=0.0;
        for(int i=0;i<squares.size();i++){
            double side =squares[i][2];
            double y=squares[i][1];
            high=max(high,y+side);
            totalArea+=((side)*(side));
        }

        double ans=0.0;

        while((high-low)>1e-6){
            double mid=(high+low)/2;
            if(fun(mid,squares)){
                high=mid;
            }
            else {
                low=mid;
            }
        }
        return low;
    }
};