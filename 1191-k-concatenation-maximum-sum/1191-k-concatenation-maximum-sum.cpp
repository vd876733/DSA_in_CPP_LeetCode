class Solution {
public:
    const int MOD = 1e9 + 7;
    long long kadane(vector<int>& nums) {
        long long curr = 0;
        long long best = 0;
        for (int x : nums) {
            curr = max(0LL, curr + x);
            best = max(best, curr);
        }
        return best;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0;
        for (int x : arr)
            sum += x;
        if (k == 1)
            return kadane(arr) % MOD;
        vector<int> twice = arr;
        for (int x : arr)
            twice.push_back(x);
        long long ans = kadane(twice);
        if (sum > 0)
            ans += (long long)(k - 2) * sum;
        return ans % MOD;
    }
};