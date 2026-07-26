class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        const long long LIM = 100000;
        long long largest = nums[n - 1];
        long long secondLargest = nums[n - 2];
        long long smallest = nums[0];
        long long secondSmallest = nums[1];
        // Replace one element with +100000
        long long maxPair = max(
            largest * secondLargest,
            smallest * secondSmallest
        );
        long long ans1 = LIM * maxPair;
        // Replace one element with -100000
        long long minPair = min({
            largest * smallest,
            largest * secondSmallest,
            secondLargest * smallest,
            secondLargest * secondSmallest
        });
        long long ans2 = (-LIM) * minPair;
        return max(ans1, ans2);
    }
};