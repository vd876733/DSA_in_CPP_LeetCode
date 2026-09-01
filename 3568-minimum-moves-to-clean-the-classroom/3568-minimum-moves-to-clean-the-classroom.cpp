class Solution {
public:
    struct State {
        int r;
        int c;
        int energy;
        int mask;
        int dist;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = 0, sc = 0;
        // Give every litter a number
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        int litterCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }
        int fullMask = (1 << litterCount) - 1;
        queue<State> q;
        q.push({sr, sc, energy, 0, 0});
        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited( m,vector<vector<vector<bool>>>( n, vector<vector<bool>>( energy + 1, vector<bool>(1 << litterCount, false) ) ) );
        visited[sr][sc][energy][0] = true;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            State cur = q.front();
            q.pop();
            int r = cur.r;
            int c = cur.c;
            int e = cur.energy;
            int mask = cur.mask;
            int dist = cur.dist;
            // All litter collected
            if (mask == fullMask) {
                return dist;
            }
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                // Outside grid
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }
                // Obstacle
                if (classroom[nr][nc] == 'X') {
                    continue;
                }
                // Need one energy to move
                if (e == 0) {
                    continue;
                }
                int ne = e - 1;
                int nmask = mask;
                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    nmask |= (1 << id);
                }
                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }
                if (!visited[nr][nc][ne][nmask]) {
                    visited[nr][nc][ne][nmask] = true;
                    q.push({nr, nc, ne, nmask, dist + 1});
                }
            }
        }
        return -1;
    }
};