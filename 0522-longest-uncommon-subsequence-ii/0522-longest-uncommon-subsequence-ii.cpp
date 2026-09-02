class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) {
            if (i < s.size() && s[i] == c) {
                i++;
            }
        }
        return i == s.size();
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            bool uncommon = true;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            if (uncommon) {
                ans = max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};