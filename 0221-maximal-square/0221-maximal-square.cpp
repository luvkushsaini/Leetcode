class Solution {
public:

    vector<int>nextSmaller(vector<int>&arr){
        int n=arr.size();
        vector<int>v(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int num=arr[i];
            while(!st.empty() && arr[st.top()]>=num)st.pop();
            if(!st.empty())v[i]=st.top();
            else v[i]=n;
            st.push(i);
        }

        return v;
    }

    vector<int>prevSmaller(vector<int>&arr){
        int n=arr.size();
        vector<int>v(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            int num=arr[i];
            while(!st.empty() && arr[st.top()]>num)st.pop();
            if(!st.empty())v[i]=st.top();
            else v[i]=-1;
            st.push(i);
        }
        return v;
    }


    int solve(vector<int>&arr){
        int n=arr.size();
        vector<int>nextSmall=nextSmaller(arr);
        vector<int>prevSmall=prevSmaller(arr);


        int ans=0;
        for(int i=0;i<n;i++){
            int num=arr[i];
            int prev=prevSmall[i];
            int next=nextSmall[i];
            int len=next-prev-1;
            if(len>=num){
                ans=max(ans,num*num);
            }
        }
        return ans;

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>v(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')v[j]=0;
                else v[j]+=(matrix[i][j]-'0');
                
            }
            ans=max(ans,solve(v));
        }
        return ans;
    }
};