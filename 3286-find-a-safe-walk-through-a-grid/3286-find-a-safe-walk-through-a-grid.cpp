class Solution {
public:
    // previous submitted solution was based on the bfs using priority queue as we can travel in all four direction 
    int n, m;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int health, vector<vector<int>>& grid) {
        if (health <= 0)
            return false;
        if (i == n - 1 && j == m - 1)
            return true;
        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        dp[i][j][health] = 0;

        for (int k = 0; k < 4; k++) {
            int x = i + dr[k];
            int y = j + dc[k];

            if (x >= 0 && x < n && y >= 0 && y < m) {
                int newHealth = health - grid[x][y];
                if (solve(x, y, newHealth, grid))
                    return dp[i][j][health] = 1;
            }
        }

        return dp[i][j][health];
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();

        health -= grid[0][0];
        if (health <= 0)
            return false;

        dp.assign(n, vector<vector<int>>(m, vector<int>(health + 1, -1)));
        return solve(0, 0, health, grid);
    }
};