class Solution {
    int n, m;
    Map<Character, List<Integer>> mp;
    int[][] dp;

    int solve(int i, int j, String ring, String key) {
        if (i == m) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        char ch = key.charAt(i);
        int ans = Integer.MAX_VALUE;

        for (int pos : mp.get(ch)) {

            int x = 1 + solve(i + 1, pos, ring, key);

            if (pos < j) {
                ans = Math.min(ans, j - pos + x);
                ans = Math.min(ans, n - j + pos + x);
            } else {
                ans = Math.min(ans, pos - j + x);
                ans = Math.min(ans, n - pos + j + x);
            }
        }

        return dp[i][j] = ans;
    }

    public int findRotateSteps(String ring, String key) {
        n = ring.length();
        m = key.length();

        mp = new HashMap<>();

        for (char c = 'a'; c <= 'z'; c++) {
            mp.put(c, new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            mp.get(ring.charAt(i)).add(i);
        }

        dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(0, 0, ring, key);
    }
}