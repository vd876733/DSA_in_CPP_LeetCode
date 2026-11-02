class Solution {
public:
    int solve(vector<int> &nums, vector<int> &prefix, int L, int M){
        int n = nums.size();

        int ans = 0, best = 0;

        // i = starting index of M window
        for(int i = L; i <= n - M; i++){
            // M window: [i, i+M-1]
            int curr1 = prefix[i + M - 1] - (i > 0 ? prefix[i - 1] : 0);

            // L window: [i-L, i-1]
            int curr2 = prefix[i - 1] - (i - L > 0 ? prefix[i - L - 1] : 0);

            best = max(best, curr2);
            ans = max(ans, curr1 + best);
        }

        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        return max(solve(nums, prefix, L, M),
                   solve(nums, prefix, M, L));
    }
};