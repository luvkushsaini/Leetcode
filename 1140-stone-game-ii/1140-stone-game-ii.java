class Solution {
    //previously submitted solution was of O(n^3) time complexity  and this sone is optimized with time complexit of O(n^2);
    int n;
    int[][] dp;
    int[] suffixSum;

    public int stoneGameII(int[] piles) {
        n = piles.length;
        suffixSum = new int[n];
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        dp = new int[n][n + 1];

        return solve(0, 1);
    }

    int solve(int i, int M) {
        if (i >= n) return 0;
        if (2 * M >= n - i) {
            return suffixSum[i];
        }

        if (dp[i][M] != 0) return dp[i][M];
        int ans = 0;
        for (int X = 1; X <= 2 * M; X++) {
            int opponent = solve(i + X, Math.max(M, X));
            int current = suffixSum[i] - opponent;
            ans = Math.max(ans, current);
        }

        return dp[i][M] = ans;
    }
}