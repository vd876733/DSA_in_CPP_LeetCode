class Solution {
public:
    int MOD = 1000000007;
    int dp[51][51][51];
    int solve(int m, int n, int maxMove, int row, int col) {
        // Ball goes out of the grid
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }
        // No moves left
        if (maxMove == 0) {
            return 0;
        }
        // Already calculated
        if (dp[row][col][maxMove] != -1) {
            return dp[row][col][maxMove];
        }
        long long up = solve(m, n, maxMove - 1, row - 1, col);
        long long down = solve(m, n, maxMove - 1, row + 1, col);
        long long left = solve(m, n, maxMove - 1, row, col - 1);
        long long right = solve(m, n, maxMove - 1, row, col + 1);
        return dp[row][col][maxMove] =
            (up + down + left + right) % MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};