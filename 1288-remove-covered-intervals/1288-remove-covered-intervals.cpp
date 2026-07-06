class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])return b[1]<a[1];
            return a[0]<b[0];
        });
        int n=intervals.size();
        int count=0;
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && intervals[j][1]<=intervals[i][1])j++;
            count+=(j-i-1);
            i=j;
        }
        return n-count;
    }
};