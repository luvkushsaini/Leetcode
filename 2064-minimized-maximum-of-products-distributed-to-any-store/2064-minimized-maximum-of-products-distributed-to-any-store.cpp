class Solution {
public:
    int size;

    bool fun(int n, vector<int>& quantities,int mid){
        if(mid==0)return false;
        long long count=0LL;
        for(int i=0;i<size;i++){
            count+=ceil((double)quantities[i]/mid);
        }

        return count<=(long)n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        size=quantities.size();
        int low=0;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(n,quantities,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};