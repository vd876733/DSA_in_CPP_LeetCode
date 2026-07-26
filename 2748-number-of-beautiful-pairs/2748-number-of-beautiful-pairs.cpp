class Solution {
public:

    int firstDigit(int x) {
        while (x >= 10) {
            x /= 10;
        }
        return x;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int first = firstDigit(nums[i]);
            for (int j = i + 1; j < n; j++) {
                int last = nums[j] % 10;
                if (__gcd(first, last) == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};