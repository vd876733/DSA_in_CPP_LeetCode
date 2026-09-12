class Solution {
public:

    int rows;
    int cols;

    bool dfs(vector<vector<char>>& board,
             string& word,
             int r,
             int c,
             int index) {

        // We found the complete word
        if (index == word.size()) {
            return true;
        }

        // Out of bounds
        if (r < 0 || r >= rows ||
            c < 0 || c >= cols) {
            return false;
        }

        // Current cell doesn't match
        if (board[r][c] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Try four directions
        bool found =
            dfs(board, word, r + 1, c, index + 1) ||
            dfs(board, word, r - 1, c, index + 1) ||
            dfs(board, word, r, c + 1, index + 1) ||
            dfs(board, word, r, c - 1, index + 1);

        // Undo the change
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (board[r][c] == word[0]) {

                    if (dfs(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};