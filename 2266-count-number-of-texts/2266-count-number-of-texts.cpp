class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> dp;
    long long solve(int idx, string &s) {
        if (idx == s.size())
            return 1;
        if (dp[idx] != -1)
            return dp[idx];
        long long ans = 0;
        int limit = (s[idx] == '7' || s[idx] == '9') ? 4 : 3;
        for (int len = 1; len <= limit; len++) {
            if (idx + len > s.size())
                break;
            bool same = true;
            for (int j = idx; j < idx + len; j++) {
                if (s[j] != s[idx]) {
                    same = false;
                    break;
                }
            }
            if (!same)
                break;
            ans = (ans + solve(idx + len, s)) % MOD;
        }
        return dp[idx] = ans;
    }
    int countTexts(string pressedKeys) {
        dp.assign(pressedKeys.size(), -1);
        return solve(0, pressedKeys);
    }
};