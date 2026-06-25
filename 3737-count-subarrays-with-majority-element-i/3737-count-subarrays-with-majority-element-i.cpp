class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(nums[i] == target)
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i] - 1;
        }
        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        vector<int> bit(vals.size() + 1, 0);
        auto update = [&](int idx) {
            while(idx < bit.size()) {
                bit[idx]++;
                idx += idx & (-idx);
            }
        };
        auto query = [&](int idx) {
            int sum = 0;
            while(idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        };
        long long ans = 0;
        for(int x : prefix) {
            int idx =lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            ans += query(idx - 1);
            update(idx);
        }
        return ans;
    }
};