class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_ans = nums[0];
        int max_ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {

            min_ans = min(min_ans, nums[i]);
            max_ans = max(max_ans, nums[i]);
        }
        return __gcd(min_ans, max_ans);
    }
};