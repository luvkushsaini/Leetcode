class Solution {
public:
    vector<long long>prefix;
    int n;

    bool fun(string s, string t, int maxCost,int mid){
        int i=0;
        int j=mid-1;

       while(j<n){
        long long sum=prefix[j]-((i>0)?prefix[i-1]:0);
        if(sum<=1LL*maxCost)return true;
        i++;
        j++;
       }
       return false;
    }
    int equalSubstring(string s, string t, int maxCost) {
        n=s.size();
        prefix.assign(n,0LL);
        for(int i=0;i<n;i++){
            prefix[i]=1LL*abs(s[i]-t[i]);
            if(i>0)prefix[i]+=prefix[i-1];
        }

        int low=1;
        int high=n;
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(s,t,maxCost,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};