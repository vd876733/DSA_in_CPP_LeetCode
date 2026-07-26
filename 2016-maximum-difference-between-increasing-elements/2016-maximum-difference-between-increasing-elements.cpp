class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minValue = nums[0];
        int ans = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minValue) {
                ans = max(ans, nums[i] - minValue);
            }
            minValue = min(minValue, nums[i]);
        }
        return ans;
    }
};