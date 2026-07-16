class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int,greater<int>>ms;
        for(int i=0;i<k-1;i++){
            ms.insert(nums[i]);
        }
        vector<int>ans(n-k+1);

        int i=0;
        int j=k-1;
        while(j<n){
            ms.insert(nums[j]);
            ans[i]=*ms.begin();
            auto it=ms.find(nums[i]);
            ms.erase(it);
            i++;
            j++;
        }

        return ans;
    }
};