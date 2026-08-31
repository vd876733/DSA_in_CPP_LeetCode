class Solution {
public:
    bool solve(vector<int>& nums, vector<bool>& used,
               int k, int start, int currSum, int target) {
        // Only one subset remains
        if (k == 1)
            return true;
        // Current subset completed
        if (currSum == target) {
            return solve(nums, used, k - 1, 0, 0, target);
        }
        for (int i = start; i < nums.size(); i++) {
            if (used[i])
                continue;
            if (currSum + nums[i] > target)
                continue;
            used[i] = true;
            if (solve(nums, used, k, i + 1,
                      currSum + nums[i], target))
                return true;
            used[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        // Necessary condition
        if (sum % k != 0)
            return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        // Largest element itself is too big
        if (nums[0] > target)
            return false;
        vector<bool> used(nums.size(), false);
        return solve(nums, used, k, 0, 0, target);
    }
};