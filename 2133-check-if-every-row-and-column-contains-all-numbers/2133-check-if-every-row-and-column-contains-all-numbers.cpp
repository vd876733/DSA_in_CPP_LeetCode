class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 1 || matrix[i][j] > n)
                    return false;
                mp[matrix[i][j]]++;
                if(mp[matrix[i][j]] > 1)
                    return false;
            }
        }
        for(int j = 0; j < n; j++) {
            unordered_map<int, int> mp;
            for(int i = 0; i < n; i++){
                mp[matrix[i][j]]++;
                if(mp[matrix[i][j]] > 1)
                    return false;
            }
        }
        return true;
    }
};