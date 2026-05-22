class Solution {
public:

    int n;

    bool isFun(vector<int>& dist, double hour,int mid){

        double hoursTook=0.0;

        for(int  i=0;i<n;i++){
            if(i==n-1){
                hoursTook+=((double)dist[i]/mid);
            }
            else{
                hoursTook+=ceil((double)dist[i]/mid);
            }
        }

        return hoursTook<=hour;
    }

    
    int minSpeedOnTime(vector<int>& dist, double hour) {
         n=dist.size();

         int low=1;
         int high=1e7;
         int ans=-1;


         while(low<=high){
            int mid=low+(high-low)/2;

            if(isFun(dist,hour,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
         }

         return ans;
    }
};