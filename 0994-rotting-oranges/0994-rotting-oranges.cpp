class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // Find all rotten and count fresh
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process one minute
            while (size--) {

                auto [row, col] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {

                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    // Check boundaries and fresh orange
                    if (newRow >= 0 && newRow < rows &&
                        newCol >= 0 && newCol < cols &&
                        grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;
                        fresh--;

                        q.push({newRow, newCol});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};