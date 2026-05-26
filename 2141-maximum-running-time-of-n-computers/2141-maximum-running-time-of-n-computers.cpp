class Solution {
public:
    int size;

    bool fun(long long mid,int n, vector<int>& batteries){
        int compLeft=n;
        long long capacity=0LL;
        for(int i=0;i<size;i++){
            if(batteries[i]<mid){
                capacity+=batteries[i];
            }
            else compLeft--;
        }

        if(compLeft<=0)return true;
         long long totalCapacityNeed=compLeft*mid;
         if(totalCapacityNeed<=capacity)return true;
         return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        size=batteries.size();
        long long low=0;
        long long sum=0LL;
        for(int i=0;i<size;i++){
            sum+=batteries[i];
        }
        long long high=sum/n;
        long long ans;
       // cout<<high<<endl;

        while(low<=high){
            long long mid=low+(high-low)/2;

            if(fun(mid,n,batteries)){
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