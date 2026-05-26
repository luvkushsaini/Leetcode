class Solution {
public:
    int n;
    bool fun(vector<int>& candies, long long k,int mid){
        if(mid==0)return true;
        long long count=0LL;

        for(int i=0;i<n;i++){
            count+=(candies[i]/mid);
        }
        return count>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        n=candies.size();
        int low=0;
        int high=*max_element(candies.begin(),candies.end());

        int ans;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(candies,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};