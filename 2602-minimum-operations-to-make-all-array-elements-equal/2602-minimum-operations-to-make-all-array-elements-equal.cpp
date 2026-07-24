class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<long long> ans;
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i];
            int idx = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            long long leftSum = 0;
            if (idx > 0)
                leftSum = prefix[idx - 1];
            long long rightSum = prefix[n - 1] - leftSum;
            long long leftCost = 1LL * x * idx - leftSum;
            long long rightCost = rightSum - 1LL * x * (n - idx);
            ans.push_back(leftCost + rightCost);
        }
        return ans;
    }
};