class Solution {
public:
    vector<int>prev_greater(vector<int>&nums){
        int n = nums.size();
        vector<int>res(n,-1);
        stack<int>st;
        for (int i = 0; i < n; i++){
                while (!st.empty() && ((nums[i]|nums[st.top()])==nums[i]) && nums[st.top()]!=nums[i]) st.pop();
                if (st.empty()) st.push(i);
                else {
                    res[i] = st.top();
                    st.push(i);
                }
        }
        return res;
    }

    vector<int>next_greater(vector<int>&nums){
        int n = nums.size();
        vector<int>res(n,n);
        stack<int>st;
        for (int i = n-1; i >= 0; i--){
                while (!st.empty() && ((nums[i]|nums[st.top()])==nums[i])) st.pop();
                if (st.empty()) st.push(i);
                else {
                    res[i] = st.top();
                    st.push(i);
                }
        }
        return res;
    }


    long long countGoodSubarrays(vector<int>& nums) {
        vector<int>prev = prev_greater(nums);
        vector<int>next = next_greater(nums);
        long long res = 0;
        for (int i = 0; i < nums.size(); i++){
            long long temp1 = i - prev[i];
            long long temp2 = next[i] - i;
            long long temp3 = temp1 * temp2; 
            res += temp3;
        }
        return res;
    }
};