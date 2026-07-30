class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void solve(int index, string digits, string &path) {
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            solve(index + 1, digits, path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        string path = "";
        solve(0, digits, path);
        return ans;
    }
};