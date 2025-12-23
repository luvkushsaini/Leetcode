class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for(int i = n - 2 ; i >= 0 ; i--){
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }

        int gMax = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            int val = events[i][2];
            int end = events[i][1];

            gMax = max(val, gMax);

            int left = i + 1, right = n - 1;
            int nextValidIdx = -1;

            while(left <= right){
                int mid = left + (right - left)/2;
                if(events[mid][0] > end){
                    nextValidIdx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if(nextValidIdx != -1){
                gMax = max(gMax, val + suffixMax[nextValidIdx]);
            }
        }

        return gMax;
    }
};