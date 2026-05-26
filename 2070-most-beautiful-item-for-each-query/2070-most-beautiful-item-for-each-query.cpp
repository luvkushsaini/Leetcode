class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        sort(items.begin(),items.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });

        vector<int>maxBeauty(n);
        maxBeauty[0]=items[0][1];

        for(int i=1;i<n;i++){
            maxBeauty[i]=max(maxBeauty[i-1],items[i][1]);
        }

        vector<int>ans(queries.size());

        for(int i=0;i<queries.size();i++){
            int val=queries[i];
            int ind=upper_bound(items.begin(),items.end(),vector<int>{val,INT_MAX})-items.begin();
            if(ind==0){
                ans[i]=0;
                continue;
            }
            ans[i]=maxBeauty[ind-1];
        }

        return ans;


    }
};