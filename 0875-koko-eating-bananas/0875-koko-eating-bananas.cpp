class Solution {
public:

    bool isFun(vector<int>&piles,int h,long long mid){
        long long hoursTook=0LL;

        for(int i=0;i<piles.size();i++){
            hoursTook+=ceil((double)piles[i]/mid);
        }
        return hoursTook<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long low=1LL;
        long long high=1e13+1LL;
        int ans=0;

        while(low<=high){
            long long mid=low+(high-low)/2;

            if(isFun(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
        
    }
};