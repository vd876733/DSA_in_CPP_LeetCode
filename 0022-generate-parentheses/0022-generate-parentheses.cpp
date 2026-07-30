class Solution {
public:
    vector<string> ans;
    void solve(int open, int close, int n, string &path) {
        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        }
        if (open < n) {
            path.push_back('(');
            solve(open + 1, close, n, path);
            path.pop_back();
        }
        if (close < open) {
            path.push_back(')');
            solve(open, close + 1, n, path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        solve(0, 0, n, path);
        return ans;
    }
};