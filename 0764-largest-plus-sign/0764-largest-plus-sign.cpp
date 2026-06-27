class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(int i = 0; i < mines.size(); i++) {
            grid[mines[i][0]][mines[i][1]] = 0;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    continue;
                int k = 1;
                while(true) {
                    int up = i - k;
                    int down = i + k;
                    int left = j - k;
                    int right = j + k;
                    if(up < 0 || down >= n || left < 0 || right >= n)
                        break;
                    if(grid[up][j] == 0 || grid[down][j] == 0 || grid[i][left] == 0 || grid[i][right] == 0)
                        break;
                    k++;
                }
                ans = max(ans, k);
            }
        }
        return ans;
    }
};