class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 0;

        int gap = max(1, (mx - mn) / (n - 1));

        int bucketCount = (mx - mn) / gap + 1;

        vector<pair<int, int>> bucket(
            bucketCount,
            {INT_MAX, INT_MIN}
        );

        // Put every number into a bucket
        for (int x : nums) {
            int index = (x - mn) / gap;

            bucket[index].first =
                min(bucket[index].first, x);

            bucket[index].second =
                max(bucket[index].second, x);
        }

        int ans = 0;
        int prevMax = mn;

        // Check gaps between non-empty buckets
        for (int i = 0; i < bucketCount; i++) {

            if (bucket[i].first == INT_MAX)
                continue;

            ans = max(ans, bucket[i].first - prevMax);

            prevMax = bucket[i].second;
        }

        return ans;
    }
};