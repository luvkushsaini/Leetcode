class Solution {
public:

    bool isfun(vector<int>&time,long long  mid,int totalTrips){
        long long tripsInCurrTime=0LL;

        for(int i=0;i<time.size();i++){
            if(time[i]>mid)break;
            tripsInCurrTime+=(mid/time[i]);
        }
        return tripsInCurrTime>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        sort(time.begin(),time.end());
        int minInTime=*min_element(time.begin(),time.end());

        long long  low=minInTime*1LL;
        long long high=1e14;
        long long  ans=0;

        while(low<=high){
            long long  mid=low+(high-low)/2;

            if(isfun(time,mid,totalTrips)){
                ans=mid;
                high=mid-1LL;
            }
            else{
                low=mid+1LL;
            }
        }

        return ans;

    }
};