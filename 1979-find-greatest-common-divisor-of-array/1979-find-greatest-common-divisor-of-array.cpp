class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_ans = INT_MAX;
        int max_ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {

            min_ans = min(min_ans, nums[i]);
            max_ans = max(max_ans, nums[i]);
        }
        return __gcd(min_ans, max_ans);
    }
};