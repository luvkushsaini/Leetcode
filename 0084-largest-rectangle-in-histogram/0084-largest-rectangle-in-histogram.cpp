class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prevSmaller(n,0),nextSmaller(n,n);

        stack<int>st;

        int i=0;
        while(i<n){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())prevSmaller[i]=-1;
            else prevSmaller[i]=st.top();
            st.push(i);
            i++;
        }

        i=n-1;
        while(!st.empty())st.pop();
        while(i>=0){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())nextSmaller[i]=n;
            else nextSmaller[i]=st.top();
            st.push(i);
            i--;
        }

        int ans=0;
        // for(int i=0;i<n;i++){
        //     cout<<prevSmaller[i]<<" ";
        // }
        // cout<<endl;
        //         for(int i=0;i<n;i++){
        //     cout<<nextSmaller[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0;i<n;i++){
            int index1=prevSmaller[i];
            int index2=nextSmaller[i];

            ans=max(ans,(index2-index1-1)*heights[i]);
        }
        return ans;

    }
};