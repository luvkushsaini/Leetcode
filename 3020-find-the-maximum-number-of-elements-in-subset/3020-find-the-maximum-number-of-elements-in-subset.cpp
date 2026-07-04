class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int MX=sqrt(mx);

        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans=1;
        if(freq[1]!=0)ans=(freq[1]%2)?freq[1]:(freq[1]-1);


        for(int i=2;i<=MX;i++){
            if(freq[i]==0)continue;
            int len=0;
            long long n=i;
            while(n<=mx){
                if(freq[n]==0)break;
                len+=2;
                if(freq[n]==1)break;
                n*=n;
            }
            len--;
            ans=max(ans,len);
        }

        return ans;

    }
};