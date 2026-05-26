class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        vector<int>start,end;
        for(int i=0;i<n;i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int size=people.size();
        vector<int>ans(size);

        for(int i=0;i<people.size();i++){
            int value=people[i];
            int ind1=upper_bound(start.begin(),start.end(),value)-start.begin();
            int ind2=lower_bound(end.begin(),end.end(),value)-end.begin();
            ans[i]=ind1-ind2;
        }
        return ans;

        
    }
};