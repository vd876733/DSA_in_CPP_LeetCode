class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd.push_back(__gcd(nums[i], mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            ans += __gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};