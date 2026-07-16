class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }

        int i=n-1;
        vector<int>nextGreater(n);
        while(i>=0){
            int num=nums[i];
            while(!st.empty() && st.top()<=num)st.pop();
            if(!st.empty())nextGreater[i]=st.top();
            else nextGreater[i]=-1;
            st.push(num);
            i--;
        }
        return nextGreater;
    }
};