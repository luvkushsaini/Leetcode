class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        int ct1=0;
        int ct2=0;
        int n=nums.size();
        unordered_set<int>st;

        for(int i=0;i<n;i++){

            st.clear();
            ct1=0;
            ct2=0;

            for(int j=i;j<n;j++){
                if(st.find(nums[j])==st.end()){
                st.insert(nums[j]);
                if(nums[j]%2)ct1++;
                else ct2++;
                }
                
                if(ct1==ct2){
                    ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
        
    }
};