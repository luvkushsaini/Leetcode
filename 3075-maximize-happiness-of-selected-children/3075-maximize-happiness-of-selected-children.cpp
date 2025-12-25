class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;

        int n = happiness.size() - 1;

        sort(happiness.begin(), happiness.end());

        for(int i = 0; i < k; i++) {
            int currentHappiness = happiness[n - i] - i;
            if(currentHappiness > 0)
                ans += currentHappiness;
            else
                break;
        }

        return ans;
    }
};