


class Solution {
public:
    // 4 direction moves: up, right, down, left
    const array<pair<int,int>, 4> d4 = {{{-1,0}, {0,1}, {1,0}, {0,-1}}};

    int solve(int sx, int sy, const vector<string>& grid, unordered_map<char, vector<pair<int,int>>>& mp) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9; // Infinity constant for unreachable cells
        
        // Distance array to track minimum moves to each cell
        vector<vector<int>> dist(m, vector<int>(n, INF));
        
        // Array to track if a teleport letter has been used
        vector<bool> used(26, false);
        
        // Deque for BFS to store positions to explore
        deque<pair<int,int>> dq;

        dist[sx][sy] = 0; // Starting point distance is 0
        dq.emplace_back(sx, sy); // Add starting point to the deque

        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front(); // Get current position
            int d = dist[x][y]; // Current distance from start to (x, y)

            char c = grid[x][y]; // Current cell character

            // Teleportation if letter not used yet
            if (c >= 'A' && c <= 'Z' && !used[c - 'A']) {
                used[c - 'A'] = true; 
                for (const auto &p : mp[c]) {
                    int nx = p.first, ny = p.second; // New coordinates for teleportation
                    if (dist[nx][ny] > d) { // Check if a shorter path is found
                        dist[nx][ny] = d; // No cost for teleportation
                        dq.emplace_front(nx, ny); // Add to front for zero-cost move
                    }
                }
            }

            // Normal moves in 4 directions
            for (const auto &dir : d4) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; 
                if (grid[nx][ny] == '#') continue; 
                if (dist[nx][ny] > d + 1) { // Check if a shorter path is found
                    dist[nx][ny] = d + 1; // Increment distance for normal move
                    dq.emplace_back(nx, ny); // Add to back for normal move
                }
            }
        }

        // Return the distance to the bottom-right corner or -1 if unreachable
        return dist[m-1][n-1] == INF ? -1 : dist[m-1][n-1];
    }

    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        if (m == 0) return -1; // Edge case: empty matrix
        int n = matrix[0].size();

        // Map teleport letter to positions
        unordered_map<char, vector<pair<int,int>>> mp;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
                    mp[matrix[i][j]].emplace_back(i, j); // Store coordinates of teleport letters

        return solve(0, 0, matrix, mp); // Start BFS from the top-left corner
    }
};