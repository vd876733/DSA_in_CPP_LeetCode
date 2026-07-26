class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mV = nums[0];
        int ans = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mV) {
                ans = max(ans, nums[i] - mV);
            }
            mV = min(mV, nums[i]);
        }
        return ans;
    }
};