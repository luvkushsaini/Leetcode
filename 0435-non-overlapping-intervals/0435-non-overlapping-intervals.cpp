class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int count=0;
        int i=0;
        int j=1;
        while(j<n){
            if(intervals[i][1]<=intervals[j][0]){
                i=j;
                j++;
            }
            else if(intervals[i][1]>intervals[j][1]){
                count++;
                i=j;
                j++;
            }
            else{
                count++;
                j++;
            }
        }

        return count;
    }
};