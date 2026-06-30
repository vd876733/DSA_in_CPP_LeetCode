class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0, j = 0; i < n && j < n; i++, j++) {
            sum += mat[i][j];
        }
        for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if(i != j) {
                sum += mat[i][j];
            }
        }
        return sum;
    }
};