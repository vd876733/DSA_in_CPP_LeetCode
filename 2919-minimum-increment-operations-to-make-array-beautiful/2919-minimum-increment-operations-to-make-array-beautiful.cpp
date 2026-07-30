class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            long long cost = max(0LL, (long long)k - nums[i]);
            if (i < 3) {
                dp[i] = cost;
            } else {
                dp[i] = cost + min({
                    dp[i - 1],
                    dp[i - 2],
                    dp[i - 3]
                });
            }
        }
        return min({
            dp[n - 1],
            dp[n - 2],
            dp[n - 3]
        });
    }
};